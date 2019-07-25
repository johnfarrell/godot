## Build Issues

## 1. Install ign-math
I used the guide [here](https://ignitionrobotics.org/libs/math) under _Source Install_. They have their own flavor of cmake required for some reason as well to build ign-math. Might be able to get away with just installing the binary and having the source files available in the module, I didn't try that.

## 2. Building SDFormat
From [here](http://sdformat.org/tutorials?tut=install).

Clean and install dependencies
```
$ sudo apt-get remove 'libsdformat*' 'sdformat*'
$ sudo apt-get install build-essential libtinyxml-dev libboost-all-dev cmake mercurial pkg-config
```

Clone source
```
$ mkdir ~/sdf_source
$ cd ~/sdf_source
$ hg clone https://bitbucket.org/osrf/sdformat
```
Get on the 2.0 branch
```
$ cd sdformat
$ hg up sdf_2.0
```

#### Changes to CMakeLists and cmake/SDFUtils
To add a compiler flag, add it on line 96 of ```CMakeLists.txt```

To add a static library, edit the ```sdf_add_library``` macro on line 57 of ```cmake/SDFUtils.cmake``` and change it to the following:
```cmake
macro (sdf_add_library _name)
    add_library(${_name} SHARED ${ARGN})
  + add_library(${_name}_static STATIC ${ARGN})
    target_link_libraries (${_name} ${general_libraries})
  + target_link_libraries (${_name}_static ${general_libraries})
endmacro()
```

### Build
Make build directory
```
$ mkdir build
$ cd build
```
Build
```
$ make .. -DCMAKE_INSTALL_PREFIX=/usr
$ make -j4
$ sudo make install
```

### Get static library
Copy the static library (located in ```src/sdformat_static.a```) into the ```libs``` folder of the modelmaker module.

### Add the 2.2 sdf to include path
In ```/usr/include``` there will be a ```sdformat-2.2``` directory. I copied the ```sdf``` file out of that into the base ```/usr/include```.


## Building Godot
Clone the modelmaker branch and build it.

I would make sure the SDFormat library isn't being used before running these to make sure everything builds smoothly, you should be able to just comment out ```types/sdf_core.cpp:60```
```
$ scons p=x`` tools=yes module_mono_enabled=yes mono_glue=no
$ bin/godot.x11.tools.64.mono --generate-mono-glue modules/mono/glue
```

Now the editor can be compiled with Mono:
```
$ scons p=x11 target=debug tools=yes module_mono_enabled=yes -j 4
```
This is where Godot doesn't compile. I'm sure it wouldn't compile the glue also, but I haven't tried to to avoid unnecessarily long compiling times.

I have this command as a build task in VSCode.

To run the editor, I use the following command:
```
$ ./bin/godot.x11.tools.64.mono -v
```