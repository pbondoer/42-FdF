# FdF @ 42

![screenshot](/screens/screen.png?raw=true)

A simple 3D height-map renderer. You can rotate models, color is defined by
relative height in the map. More features planned!

## Features
* Simple file format definition (array of space-separated integers)
* 3D rotations with the mouse
* Camera controls (zoom, translate)
* Pretty color gradients!
* Double-buffered
* Line clipping

### Planned features
* Other projections (right now it's just orthographic)
* Different view modes: point map, wireframe, and filled
* More color modes: gradient, file-defined and z-buffer
* Depth shader
* Multithreaded calculations (OpenCL even?)
* Anti-aliased rendering
* Level-of-detail (less points when you zoom out on huge maps)

## Compiling and running
Run `make`. An executable will compile. Currently only tested on OS X.

Run it with `./fdf [map]`. A bunch of sample maps are provided in the `maps`
directory. The one in the screenshot above is `maps/42.fdf`.

Controls are: drag with left click to rotate, drag with right to zoom, drag with
both to move around.

## License
This project is licensed under the GNU General Public License 3.
