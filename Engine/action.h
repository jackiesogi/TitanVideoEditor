/*
interacts with the library 
*/
#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
// included headers

class Action
{
private:
    std::string filename;
    // holds filepath
public:
    // class constructor
    Action(std::string &filename);
    // returns filename
    std::string getfilename();
    // sets filename
    void setfilename(std::string filename);
    // plays file
    void exec(std::string &filename);
    // performs extract frame operation
    void extractFrame(std::string &seektime, std::string &height, std::string &width, std::string &ofilepath);
    // performs extract audio operation
    void extractAudio(std::string &seektime, std::string &bitrate, std::string &ofilepath);
    // performs extract video operation
    void extractClip(std::string &seektime, std::string &duration, std::string &ofilepath);
    // performs split video operation
    void splitVideo(std::string &splitseek, std::string &ofilepath1, std::string &ofilepath2);
    // performs audio overlay operation
    void overlayAudio(std::string &audiofile, std::string &ofilepath);
    // performs subtitle overlay operation
    void overlaySub(std::string &subfile, std::string &vcodec, std::string &ofilepath);
    // performs convert operation
    void convertVideo(std::string &extn, std::string &vcodec, std::string &acodec);
    // performs gif convert operation
    void getGif(std::string &seektime, std::string &duration, std::string &height, std::string &width, std::string &ofilepath, std::string &framerate);
    // concates files
    void concat(std::string &ofilepath);
    // mutes audio channel
    void muteAudio(std::string &ofilepath);
    // omits clip segment
    void omitClip(std::string &seektime_ini, std::string &seektime_fn, std::string &ofilepath);
    // changes clip speed
    void setSpeed(std::string &ofilepath, double speed);
    // changes clip resolution
    void setRes(std::string &height, std::string &width, std::string &ofilepath);
    // changes clip volume
    void setVol(std::string &vol, std::string &ofilepath);
    // changes video bitrate
    void setBitrate(std::string &bitrate, std::string &ofilepath);

    // rescale the video size
};

#endif // ACTION_H 