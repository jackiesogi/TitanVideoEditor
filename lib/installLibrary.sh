#!/bin/bash

# install ffmpeg dependencies
sudo apt install ffmpeg -y

# Check if libaction.so already exists and remove it
if [ -f "libaction.so" ]; then
    echo "Removing existing libaction.so..."
    rm libaction.so
fi

# Check if action.h already exists in /usr/local/include/simplEngine and remove it
if [ -f "/usr/local/include/simplEngine/action.h" ]; then
    echo "Removing existing action.h..."
    sudo rm /usr/local/include/simplEngine/action.h
fi

# compiling the shared object
echo "Compiling..."
g++ -shared -o libaction.so -fPIC ./lib/action.cpp

# install the shared object to where it should be
echo "Install the libaction.so ..."
sudo cp libaction.so /usr/local/lib/libaction.so
sudo mkdir -p /usr/local/include/simplEngine/
sudo cp ./lib/action.h /usr/local/include/simplEngine/action.h
sudo ldconfig

# finished!
echo "Installation has finished..."
echo "[Hint] When compiling your code using \"simplEngine/action.h\", please use -L. -laction"
