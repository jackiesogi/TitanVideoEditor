/*
sets up the environment pre-operation
*/
#include <cstdlib>
#include "interface.cpp"
// includes required header files
int main()
{
    // triggers engvironment setup - requires admin priv 
    std::system("sudo apt-get ffmpeg");
    std::system("ffmpeg -loglevel error");
    // creates interface object
    Interface io ;
    // starts the interface
    io.boot();
    // resets the environment
    std::system("ffmpeg -loglevel info");
    CLS;
}