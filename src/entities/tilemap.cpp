#include "tilemap.hpp"

//////////////
// Includes //
#include <fstream>

//////////
// Code //

// Constructing an empty set of tiles.
TileMap::TileMap() { }

// Adding a new Tile to the TileMap.
void TileMap::addTile(Tile t) {
    while (this->tileLayers.size() < t.getLayer())
        this->tileLayers.push_back(std::vector<Tile>());
    this->tileLayers[t.getLayer() - 1].push_back(t);
}

// Rendering every single tile in a tile map.
void TileMap::render(Window& w, const Camera& c, const Assets& a) {
    for (int i = this->tileLayers.size() - 1; i >= 0; i--) {
        for (auto it = this->tileLayers[i].begin(); it != this->tileLayers[i].end(); it++)
            it->render(w, c, a);
    }
}

// Accessing a copy of the tiles.
std::vector<Tile> TileMap::getTiles(int layer) const {
    return this->tileLayers[layer - 1];
}

// Getting the collision layer.
std::vector<Tile> TileMap::getCollisionTiles() const {
    return this->getTiles(1);
}

// Accessing the number of tiles.
int TileMap::layers() const { return this->tileLayers.size(); }

// Loading a tile map from an istream.
TileMap loadTileMap(std::istream& stream) {
    TileMap tm;

    std::string prefix;
    int type, layer, x, y;
    while (!stream.eof()) {
        // Skipping a line if it's not the right kind of thing.
        stream >> prefix;
        if (prefix.compare("tile") != 0) {
            while (!stream.eof() && !(stream.peek() == '\n'))
                stream.get();
            continue;
        }

        stream >> type;
        stream >> layer;
        stream >> x;
        stream >> y;

        tm.addTile(Tile(static_cast<TileType>(type), layer, x, y));
    }

    return tm;
}

// Loading a tile map from a location on disk.
TileMap loadTileMap(std::string path) {
    std::ifstream file(path);
    if (!file.good())
        return TileMap();

    TileMap tm = loadTileMap(file);

    file.close();
    return tm;
}

// Writing a tile map to an ostream.
bool saveTileMap(std::ostream& stream, TileMap tm) {
    for (int i = 0; i < tm.layers(); i++) {
        std::vector<Tile> layer = tm.getTiles(i);
        for (auto it = layer.begin(); it != layer.end(); it++) {
            stream << "tile"
                   << " " << static_cast<int>(it->getType())
                   << " " << it->getLayer()
                   << " " << it->getTX()
                   << " " << it->getTY()
                   << std::endl;
        }
    }

    return false;
}

// Writing a tile map to a location on disk.
bool saveTileMap(std::string path, TileMap tm) {
    std::ofstream file(path);
    if (!file.good())
        return true;

    bool b = saveTileMap(file, tm);

    file.close();

    return b;
}
