/*
interacts with user
processes user input
*/
#include <iostream>
#include <fstream>
#include <string>
#include "fx.cpp"
// included header files
#define CLS std::system("clear")
// declared macros
class Interface
{
private:
    fx *dx;

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
// class definations
Interface::Interface()
{
    // class constructor
    std::string fname;
    std::cout << "enter source filename :";
    std::cin >> fname;
    dx = new fx(fname);
    CLS;
}
Interface::~Interface()
{
    // class destructor
    delete dx;
}
void Interface::menu()
{
    // displays main menu
    std::cout << " current file :" << dx->getfname() << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "0\texit video editor" << std::endl;
    std::cout << "1\textract image frame" << std::endl;
    std::cout << "2\textract audio clip" << std::endl;
    std::cout << "3\textract video clip" << std::endl;
    std::cout << "4\tsplit video" << std::endl;
    std::cout << "5\tconvert video ( resource intensive )" << std::endl;
    std::cout << "6\tconvert to gif" << std::endl;
    std::cout << "7\tconcat video" << std::endl;
    std::cout << "8\tmute video" << std::endl;
    std::cout << "9\tomit video segment" << std::endl;
    std::cout << "10\tchange video speed" << std::endl;
    std::cout << "11\tchange video resolution" << std::endl;
    std::cout << "12\tchange video volume" << std::endl;
    std::cout << "13\tchange video bitrate ( resource intensive )" << std::endl;
    std::cout << "14\toverlay audio" << std::endl;
    std::cout << "15\toverlay subtitle" << std::endl;
    std::cout << "16\tpick another video file" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << " current file :" << dx->getfname() << std::endl;    
    std::cout << "================================================" << std::endl;
}
void Interface::boot()
{
    int choice;

    do
    {
        // displays menu
        menu();
        // takes user input
        std::cout << "enter your choice (0-16) :";
        std::cin >> choice;
        // makes selection based on input
        switch (choice)
        {
        case 0:
            break;
        case 1:
            extractframe();
            break;
        case 2:
            extractaudio();
            break;
        case 3:
            extractclip();
            break;
        case 4:
            splitvideo();
            break;
        case 5:
            convertvideo();
            break;
        case 6:
            getgif();
            break;
        case 7:
            concat();
            break;
        case 8:
            mute();
            break;
        case 9:
            omission();
            break;
        case 10:
            vSpeed();
            break;
        case 11:
            vRes();
            break;
        case 12:
            vVol();
            break;
        case 13:
            vBitrate();
            break;
        case 14:
            overlayaudio();
            break;
        case 15:
            overlaysub();
            break;
        case 16:
            changeselection();
            break;
        default:
            // case for wrong choice
            std::cout << "wrong choice lol" << std::endl;
        }
        // clears screen after operation
        CLS;
    } while (choice != 0);
    // checks for exit state
}
bool Interface::validstr(std::string &str)
{
    // checks minimum path length
    if (str.std::string::length() < 4)
    {
        std::cerr << "incorrect file parameter\ninclude extension ( for example:test.mp4 )" << std::endl;
        return false;
    }
    // checks for whitespace
    if (str.std::string::find(' ') != std::string::npos)
    {
        std::cerr << "incorrect file parameter\nfilename can't contain whitespace" << std::endl;
        return false;
    }
    // to do alphanumeric check ~ regex

    return true;
}
void Interface::changeselection()
{
    std::string fname;
    // inputs string + checks validity
    do
    {
        std::cout << "enter new filename :";
        std::cin >> fname;
    } while (!validstr(fname));
    // sets the filepath
    dx->setfname(fname);
}
void Interface::extractframe()
{
    // inputs parameters for frame extraction
    std::string seektime, height, width, ofilepath;
    std::cout << "enter time offset (hh:mm:ss) ";
    std::cin >> seektime;
    std::cout << "enter height resolution :";
    std::cin >> height;
    std::cout << "enter width resolution :";
    std::cin >> width;
    // tests the validity of filepath
    do
    {
        std::cout << "enter output image filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs extract frame operation
    dx->extractFrame(seektime, height, width, ofilepath);
    dx->exec(ofilepath);
}
void Interface::extractaudio()
{
    // inputs parameters for audio extraction
    std::string seektime, bitrate, ofilepath;
    std::cout << "enter time offset (hh:mm:ss) ";
    std::cin >> seektime;
    std::cout << "enter audio bitrate :";
    std::cin >> bitrate;
    // tests the validity of filepath
    do
    {
        std::cout << "enter output audio filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation based on parameters
    dx->extractAudio(seektime, bitrate, ofilepath);
    dx->exec(ofilepath);
}
void Interface::extractclip()
{
    // inputs parameters for clip extraction
    std::string seektime, duration, ofilepath;
    std::cout << "enter time offset (hh:mm:ss) ";
    std::cin >> seektime;
    std::cout << "enter clip duration :";
    std::cin >> duration;
    // tests validity of file path
    do
    {
        std::cout << "enter output video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operations
    dx->extractClip(seektime, duration, ofilepath);
    dx->exec(ofilepath);
}
void Interface::splitvideo()
{
    // inputs parameters
    std::string splitseek, ofilepath1, ofilepath2;
    std::cout << "enter split seek (hh:mm:ss) ";
    std::cin >> splitseek;
    // tests for filepath validity
    do
    {
        std::cout << "enter first output  video filename :";
        std::cin >> ofilepath1;
    } while (!validstr(ofilepath1));
    do
    {
        std::cout << "enter second output  video filename :";
        std::cin >> ofilepath2;
    } while (!validstr(ofilepath2));
    // performs file operations
    dx->splitVideo(splitseek, ofilepath1, ofilepath2);
    dx->exec(ofilepath1);
    dx->exec(ofilepath2);
}
void Interface::convertvideo()
{
    // input parameters
    std::string extn, vcodec, acodec;
    std::cout << "enter file extension (example:.mkv)";
    std::cin >> extn;
    std::cout << "enter video codec";
    std::cin >> vcodec;
    std::cout << "enter audio codec";
    std::cin >> acodec;
    // perform operation
    dx->convertVideo(extn, vcodec, acodec);
    std::string ofilepath = dx->getfname() + extn;
    dx->exec(ofilepath);
}
void Interface::getgif()
{
    // input parameters
    std::string seektime, duration, height, width, ofilepath, framerate;
    std::cout << "enter time offset (hh:mm:ss) ";
    std::cin >> seektime;
    std::cout << "enter clip duration :";
    std::cin >> duration;
    std::cout << "enter height resolution :";
    std::cin >> height;
    std::cout << "enter width resolution :";
    std::cin >> width;
    std::cout << "enter frame-rate :";
    std::cin >> framerate;
    do
    {
        std::cout << "enter output gif filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->getGif(seektime, duration, height, width, ofilepath, framerate);
    dx->exec(ofilepath);
}
void Interface::concat()
{
    // input filepaths
    std::string fpath, ofilepath;
    // check file path validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // prepare inputlist
    std::ofstream fout("inputlist.txt", std::ios::ate | std::ios::out);
    std::cout << "enter filenames:" << std::endl;
    int i;
    do
    {
        std::cin >> fpath;
        fout << "file '" + fpath + "'" << std::endl;
        i++;
    } while (!fpath.size());
    std::cout << "joining " << i << " files";
    fout.close();
    // performs operation
    dx->concat(ofilepath);
    dx->exec(ofilepath);
}
void Interface::overlayaudio()
{
    // input filepath and check validity
    std::string ofilepath, audfile;
    do
    {
        std::cout << "enter audio filename :";
        std::cin >> audfile;
    } while (!validstr(audfile));
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // perform operations
    dx->overlayAudio(audfile, ofilepath);
    dx->exec(ofilepath);
}
void Interface::overlaysub()
{
    // input ops parameter
    std::string ofilepath, vcodec, subfile;
    std::cout << "enter subtitle filename :";
    std::cin >> subfile;
    std::cout << "enter output codec (example :libx264) :";
    std::cin >> vcodec;
    // checks validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->overlaySub(subfile, vcodec, ofilepath);
    dx->exec(ofilepath);
}
void Interface::mute()
{
    // checks parameter validity
    std::string ofilepath;
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->muteAudio(ofilepath);
    dx->exec(ofilepath);
}
void Interface::omission()
{
    // inputs parameters
    std::string seektime_ini, seektime_fn, ofilepath;
    std::cout << "enter initial time offset (hh:mm:ss) ";
    std::cin >> seektime_ini;
    std::cout << "enter final time offset (hh:mm:ss) ";
    std::cin >> seektime_fn;
    // checks parameter validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->omitClip(seektime_ini, seektime_fn, ofilepath);
    dx->exec(ofilepath);
}
void Interface::vSpeed()
{
    // inputs parameter
    std::string ofilepath;
    double speed;
    std::cout << "set speed :";
    std::cin >> speed;
    // checks parameter validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->setSpeed(ofilepath, speed);
    dx->exec(ofilepath);
}
void Interface::vRes()
{
    // input parameters
    std::string height, width, ofilepath;
    std::cout << "enter height resolution :";
    std::cin >> height;
    std::cout << "enter width resolution :";
    std::cin >> width;
    // performs parameter validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->setRes(height, width, ofilepath);
    dx->exec(ofilepath);
}
void Interface::vVol()
{
    // inputs parameter
    std::string ofilepath, vol;
    std::cout << "enter volume :";
    std::cin >> vol;
    // checks path validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->setVol(vol, ofilepath);
    dx->exec(ofilepath);
}
void Interface::vBitrate()
{
    // input ops parameter
    std::string bitrate, ofilepath;
    std::cout << "enter bitrate :";
    std::cin >> bitrate;
    // check path validity
    do
    {
        std::cout << "enter output  video filename :";
        std::cin >> ofilepath;
    } while (!validstr(ofilepath));
    // performs operation
    dx->setBitrate(bitrate, ofilepath);
    dx->exec(ofilepath);
}
/*
int main()
{
    // main function for interface
    // doesn't trigger environment setup - runs without admin priv
    std::system("ffmpeg -loglevel quiet");
    // creates interface object
    Interface io;
    // starts the interface
    io.boot();
    // resets the environment
    std::system("ffmpeg -loglevel info");
    CLS;
}
*/