## Get console_bridge

Link: https://github.com/ros/console_bridge.git

```
$ git fetch --all --tags --prune
$ git checkout tags/0.3.0 -b 0.3.0
```

You need to remove the ```-std=c++11``` compile tag in ```CMakeLists.txt``` to ensure compatability with Godot and other libraries.

```
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr
$ make -j4
$ sudo make install
```

## Get urdfdom_headers

Link: https://github.com/ros/urdfdom_headers.git

```
$ git fetch --all
$ git checkout 0.4
```

```
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr
$ make -j4
$ sudo make install
```

## Get urdfdom

Link: https://github.com/ros/urdfdom

```
$ git fetch --all --tags --prune
$ git checkout tags/0.4.2 -b 0.4.2
```

```
$ mkdir build
$ cd build
```

Make sure you bring in the changes from modelmaker/urdfparser/makefiles before you make.
The one in /makefiles goes in /urdfdom and the one in /makefiles/urdf_parser will go in /urdfdom/urdf_parser. These will compile static libraries

```
$ cmake ..
$ make -j4
$ sudo make install
```


