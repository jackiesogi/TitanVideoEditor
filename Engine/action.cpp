/*
interacts with the library 
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "action.h"
// included headers

// class definations
Action::Action(std::string &fname)
    : fname(fname) {}

void Action::exec(std::string &arg)
{
    system(("ffplay " + arg).c_str());
}

void Action::extractFrame(std::string &seektime, std::string &height, std::string &width, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -vf scale=" + height + ":" + width + " -vframes 1 " + ofilepath).c_str());
}

void Action::extractAudio(std::string &seektime, std::string &bitrate, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -vn  -ab " + bitrate + " " + ofilepath).c_str());
}

void Action::extractClip(std::string &seektime, std::string &duration, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -codec copy -t " + duration + " " + ofilepath).c_str());
}

void Action::splitVideo(std::string &splitseek, std::string &ofilepath1, std::string &ofilepath2)
{
    system(("ffmpeg -i " + this->fname + " -t " + splitseek + " -c copy " + ofilepath1+ " -ss " + splitseek + " -codec copy " + ofilepath2).c_str());
}
void Action::overlayAudio(std::string &audiofile, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -i " + audiofile + " -c:v copy -c:a aac -strict experimental " + ofilepath).c_str());
}
void Action::overlaySub(std::string &subfile, std::string &vcodec, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -i " + subfile + " -c copy -c:v " + vcodec + " -crf 23 -preset veryfast " + ofilepath).c_str());
}
void Action::convertVideo(std::string &extn, std::string &vcodec, std::string &acodec)
{
    system(("ffmpeg -i " + this->fname + " -c:v " + vcodec + " -c:a " + acodec + this->fname + extn).c_str());
}

void Action::getGif(std::string &seektime, std::string &duration, std::string &height, std::string &width, std::string &ofilepath, std::string &framerate)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -vf scale=" + height + ":" + width + " -t " + duration + " -r " + framerate + " " + ofilepath).c_str());
}

void Action::concat(std::string &ofilepath)
{
    system(("ffmpeg -f concat -i inputlist.txt -c copy " + ofilepath).c_str());
}

std::string Action::getfname()
{
    return fname;
}
void Action::setfname(std::string fname)
{
    this->fname = fname;
}
void Action::muteAudio(std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -an " + ofilepath).c_str());
}

void Action::omitClip(std::string &seektime_ini, std::string &seektime_fn, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -codec copy -t " + seektime_ini + " tempf1.mp4").c_str());
    system(("ffmpeg -i " + this->fname + " -ss " + seektime_ini + " -codec copy tempf2.mp4").c_str());

    std::ofstream fout("tempinputlist.txt", std::ios::ate | std::ios::out);
    fout << "file 'tempf1.mp4'" << std::endl;
    fout << "file 'tempf2.mp4'" << std::endl;
    fout.close();

    system(("ffmpeg -f concat -i tempinputlist.txt -c copy " + ofilepath).c_str());
}

void Action::setSpeed(std::string &ofilepath, double speed)
{
    system(("ffmpeg -i " + this->fname + " -filter:v \"setpts=" + std::to_string(speed) + "*PTS\" " + ofilepath).c_str());
}

void Action::setRes(std::string &height, std::string &width, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -vf scale=" + height + ":" + width + " -c:a copy " + ofilepath).c_str());
}

void Action::setVol(std::string &vol, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -af 'volume=" + vol + "' " + ofilepath).c_str());
}

void Action::setBitrate(std::string &bitrate, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -b:v " + bitrate + " -bufsize " + bitrate + " " + ofilepath).c_str());
}