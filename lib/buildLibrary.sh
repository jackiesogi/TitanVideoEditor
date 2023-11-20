#!/bin/bash

# compiling the shared object
echo "compiling..."
g++ -shared -o libaction.so -fPIC ../Engine/action.cpp

# install the shared object to where it should be
echo "install the libaction.so ..."
sudo cp libaction.so /usr/local/lib/libaction.so
sudo mkdir /usr/local/include/simplEngine/
sudo cp ../Engine/action.h /usr/local/include/simplEngine/action.h
sudo ldconfig

# finished!
echo "intallation has finished..."
echo "[Hint] When compile your code using \"simplEngine/action.h\" please use -L. -laction"