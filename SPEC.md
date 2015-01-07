# File Specifications for HC

### TileMap

General Form:

```
tile <type id> <layer> <x> <y>
```

Example File:

```
tile 0 1 0 0
tile 0 1 1 0
tile 0 1 2 0
tile 0 1 3 1
```

Any line that doesn't start with `tile` will be ignored, which means one can
easily write comments!
