/*
interacts with the library 
*/
#ifndef FX_H
#define FX_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
// included headers

class fx
{
private:
    std::string fname;
    // holds filepath
public:
    fx(std::string &fname);
    // class constructor
    std::string getfname();
    // returns fname
    void setfname(std::string fname);
    // sets fname
    void exec(std::string &fname);
    // plays file
    void extractFrame(std::string &seektime, std::string &height, std::string &width, std::string &ofilepath);
    // performs extract frame operation
    void extractAudio(std::string &seektime, std::string &bitrate, std::string &ofilepath);
    // performs extract audio operation
    void extractClip(std::string &seektime, std::string &duration, std::string &ofilepath);
    // performs extract video operation
    void splitVideo(std::string &splitseek, std::string &ofilepath1, std::string &ofilepath2);
    // performs split video operation
    void overlayAudio(std::string &audiofile, std::string &ofilepath);
    // performs audio overlay operation
    void overlaySub(std::string &subfile, std::string &vcodec, std::string &ofilepath);
    // performs subtitle overlay operation
    void convertVideo(std::string &extn, std::string &vcodec, std::string &acodec);
    // performs convert operation
    void getGif(std::string &seektime, std::string &duration, std::string &height, std::string &width, std::string &ofilepath, std::string &framerate);
    // performs gif convert operation
    void concat(std::string &ofilepath);
    // concates files
    void muteAudio(std::string &ofilepath);
    // mutes audio channel
    void omitClip(std::string &seektime_ini, std::string &seektime_fn, std::string &ofilepath);
    // omits clip segment
    void setSpeed(std::string &ofilepath, double speed);
    // changes clip speed
    void setRes(std::string &height, std::string &width, std::string &ofilepath);
    // changes clip resolution
    void setVol(std::string &vol, std::string &ofilepath);
    // changes clip volume
    void setBitrate(std::string &bitrate, std::string &ofilepath);
    // changes video bitrate
};

#endif // FX_H