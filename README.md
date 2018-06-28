# LovelyDesign  [![Build Status](https://travis-ci.com/ColorfulTime/GeekDesign.svg?branch=master)](https://travis-ci.com/ColorfulTime/GeekDesign#)
For Learning CICD

### Additional Resources
- GBase
- Index

### Get GDesign
- Git clone
- make

### Release History

Platform | Release | Architecture | SSL   | Filename
-------- |-------- |------------  | ---   | --------
Linux    | Ubutnu18| x64          | 0.1.0 | GD


4 key concepts of docker:
Dockerfile, image, container, registry.


You can use [skip ci] or [ci skip] to skip the .CircleCI build.

How to install cmake?
- sudo apt-get -Y install cmake
- or install specify one:
  sudo wget https://cmake.org/files/v3.11/cmake-3.11.4-Linux-x86_64.tar.gz
  tar xf cmake-3.11.4-Linux-x86_64.tar.gz
  export PATH="$(pwd)/cmake-3.11.4-Linux-x86_64/bin:$PATH" (you have to change ~./bashrc or /etc/environmetn if you want to change PATH permanantly)

How to update /etc/environment by script?
https://stackoverflow.com/questions/26263249/how-to-modify-etc-environment-from-a-bash-script 

#!/bin/bash
sed -e 's|PATH="\(.*\)"|PATH="/opt/jdk1.6.0_45/bin:\1"|g' -i /etc/environment