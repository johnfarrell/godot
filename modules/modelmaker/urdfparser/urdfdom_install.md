## Get console_bridge

Link: https://github.com/ros/console_bridge.git

```
$ cd console_bridge
$ git fetch --all --tags --prune
$ git checkout tags/0.2.7 -b 0.2.7
```

Build the library
```
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr
$ make -j4
$ sudo make install
```

## Get urdfdom_headers

Link: https://github.com/ros/urdfdom_headers.git

Get the code
```
$ cd urdfdom_headers
$ git fetch --all
$ git checkout tags/0.3.0 -b 0.3.0
```

Build the library
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
$ cd urdfdom
$ git fetch --all --tags --prune
$ git checkout tags/0.3.0 -b 0.3.0
```

```
$ mkdir build
$ cd build
```

```
$ cmake ..
$ make -j4
$ sudo make install
```


