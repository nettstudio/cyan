# Cyan

***v2.0 is currently under heavy development, please use v1.2 https://github.com/rodlie/cyan/tree/1.2***

## About

Cyan is an open source cross-platform image editor. Originally designed for prepress color convertion, but now aims to be a general-purpose image editor. v2 started from scratch so it might take a while to get to the level of features you might expect from an image editor. ETA for v2 is January 2019, but that may at any time change.

## Requirements

 * QtWidgets 5
 * QtConcurrent 5
 * lcms 2
 * ffmpeg 3
 * ImageMagick 6 with [patch](https://github.com/rodlie/ImageMagick6/commit/dffafb716da8d31f41a2e28e1b43a74d0edeaef3) (available as submodule ``magick/engine``)

## Build

```
git clone --recurse-submodules https://github.com/rodlie/cyan
cd cyan
mkdir build
cd build
qmake ..
make
./editor/build/Cyan
```
