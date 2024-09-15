## A simple opengl & freetype 2 font renderer setup.

> Note: This is not a single header library, unfortunately. If someone knows how I can acheive this with the freetype dependency, please let me know.

## How to use: 

- this project depends on my `jstl/opengl/shader.hpp` header, that I just use as libraries installed on my system.
  You can find the `jstl` headers [here](https://github.com/toolateralus/jstl).
    You can either just download the necessary header, or clone the library and use its `install.sh` to install the entire library to `/usr/local/include/jstl`, however it's rather large, so you may not want to do that.
    If you cherry-pick the header, be sure to update the path [on this line in `font.hpp`](font.hpp#L18).

- in your build system, you must have an include flag pointing at the freetype headers path. 
  You can do this many ways, but we just use `-Ideps` flag.
- in addition, you must link against a few different libraries, in our Makefile, we use:
  `LD_FLAGS := -lGL -lGLEW -lglfw -lfreetype`
- we use `-lglfw` just for the window example. but the rest are neccesary.

- see the example's makefile for more information, but I think that's it. again, if you know of a way to simplify this to a single-include header, please let me know.

