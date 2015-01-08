# horizontally challenged

Horizontally Challenged is my attempt at learning about game engine development.
A major implication of that statement is that *gameplay is not a priority*. The
primary goal is to learn about the development of the engine.

I don't suggest using this as an example of how a game engine should be
structured. So far as I understand it, there are a couple glaring errors:

* Entities should be managed through an entity component system.
* Rendering should be somewhat decoupled from the entity itself. In that an
  entity may want to propagate pure data regarding a render from itself to a
  dedicated renderer.
* Asset loading is thoroughly sub-optimal due to relying upon SDL2's 2D
  rendering API.

As of January 8th, 2015, this project is considered 'completeld enough' for me
to start on something new.

### Attributions

**Format**:

* LINK - Author Name

* [res/test.png](http://opengameart.org/content/mad-sun) - Vengadora
* [res/forest_tiles.png](http://opengameart.org/content/forest-tiles) - surt
* [res/wood1.jpg](http://opengameart.org/content/wood-texture-tiles) - JCW

### License

For licensing information, refer to the `LICENSE` file.
