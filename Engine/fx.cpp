/*
interacts with the library 
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "fx.h"
// included headers

// class definations
fx::fx(std::string &fname)
    : fname(fname) {}

void fx::exec(std::string &arg)
{
    system(("ffplay " + arg).c_str());
}

void fx::extractFrame(std::string &seektime, std::string &height, std::string &width, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -vf scale=" + height + ":" + width + " -vframes 1 " + ofilepath).c_str());
}

void fx::extractAudio(std::string &seektime, std::string &bitrate, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -vn  -ab " + bitrate + " " + ofilepath).c_str());
}

void fx::extractClip(std::string &seektime, std::string &duration, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -codec copy -t " + duration + " " + ofilepath).c_str());
}

void fx::splitVideo(std::string &splitseek, std::string &ofilepath1, std::string &ofilepath2)
{
    system(("ffmpeg -i " + this->fname + " -t " + splitseek + " -c copy " + ofilepath1+ " -ss " + splitseek + " -codec copy " + ofilepath2).c_str());
}
void fx::overlayAudio(std::string &audiofile, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -i " + audiofile + " -c:v copy -c:a aac -strict experimental " + ofilepath).c_str());
}
void fx::overlaySub(std::string &subfile, std::string &vcodec, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -i " + subfile + " -c copy -c:v " + vcodec + " -crf 23 -preset veryfast " + ofilepath).c_str());
}
void fx::convertVideo(std::string &extn, std::string &vcodec, std::string &acodec)
{
    system(("ffmpeg -i " + this->fname + " -c:v " + vcodec + " -c:a " + acodec + this->fname + extn).c_str());
}

void fx::getGif(std::string &seektime, std::string &duration, std::string &height, std::string &width, std::string &ofilepath, std::string &framerate)
{
    system(("ffmpeg -i " + this->fname + " -ss " + seektime + " -vf scale=" + height + ":" + width + " -t " + duration + " -r " + framerate + " " + ofilepath).c_str());
}

void fx::concat(std::string &ofilepath)
{
    system(("ffmpeg -f concat -i inputlist.txt -c copy " + ofilepath).c_str());
}

std::string fx::getfname()
{
    return fname;
}
void fx::setfname(std::string fname)
{
    this->fname = fname;
}
void fx::muteAudio(std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -an " + ofilepath).c_str());
}

void fx::omitClip(std::string &seektime_ini, std::string &seektime_fn, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -codec copy -t " + seektime_ini + " tempf1.mp4").c_str());
    system(("ffmpeg -i " + this->fname + " -ss " + seektime_ini + " -codec copy tempf2.mp4").c_str());

    std::ofstream fout("tempinputlist.txt", std::ios::ate | std::ios::out);
    fout << "file 'tempf1.mp4'" << std::endl;
    fout << "file 'tempf2.mp4'" << std::endl;
    fout.close();

    system(("ffmpeg -f concat -i tempinputlist.txt -c copy " + ofilepath).c_str());
}

void fx::setSpeed(std::string &ofilepath, double speed)
{
    system(("ffmpeg -i " + this->fname + " -filter:v \"setpts=" + std::to_string(speed) + "*PTS\" " + ofilepath).c_str());
}

void fx::setRes(std::string &height, std::string &width, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -vf scale=" + height + ":" + width + " -c:a copy " + ofilepath).c_str());
}

void fx::setVol(std::string &vol, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -af 'volume=" + vol + "' " + ofilepath).c_str());
}

void fx::setBitrate(std::string &bitrate, std::string &ofilepath)
{
    system(("ffmpeg -i " + this->fname + " -b:v " + bitrate + " -bufsize " + bitrate + " " + ofilepath).c_str());
}