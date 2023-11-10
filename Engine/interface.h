/*
interacts with user
processes user input
*/
#include <iostream>
#include <fstream>
#include <string>
#include "action.h"
// included header files
#define CLS std::system("clear")
// declared macros
class Interface
{
private:
    Action *interface;

public:
    Interface();
    // class constructor
    ~Interface();
    // class destructor
    void menu();
    // displays main menu
    void boot();
    // invokes functions based on user input
    void changeselection();
    // changes active selection
    bool validstr(std::string &);
    // checks if the string is valid
    void extractframe();
    // extracts image frames from video
    void extractaudio();
    // extract audio clips from video
    void extractclip();
    // exctracts video clips
    void splitvideo();
    // splits video file
    void convertvideo();
    // converts video into another type
    void getgif();
    // converts video into .gif types
    void concat();
    // concates video clips
    void overlayaudio();
    // adds audio channel
    void overlaysub();
    // overlays subtitle
    void mute();
    // mutes audio
    void omission();
    // omits a clip segment
    void vSpeed();
    // changes the video speed
    void vRes();
    // changes the video resolution
    void vVol();
    // changes the video volume
    void vBitrate();
    // changes the video bitrate
};
