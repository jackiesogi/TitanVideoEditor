# Documentation

- [`Action` Class](#action-class)
  - [Action](#constructor) -- Constructor of the `Action` class
  - [play](#play) -- Play the given source video
  - [extractFrame](#extractframe) -- Extract a frame at a specific time point from the video.
  - [extractAudio](#extractaudio) -- Extracts an independent audio track
  - [extractClip](#extractclip) -- Extracts a clip from the video 
  - [splitVideo](#splitvideo) -- Splits the video into two parts
  - [overlayAudio](#overlayaudio) -- 
  - [overlaySub](#overlaysub) -- 
  - [convertVideo](#convertvideo) -- Convert video's format and codec.
  - [getGif](#getgif) -- Generate a gif from a given video.
  - [concat](#concat) -- Concatenates multiple video files listed in
  - [getfilename](#getfilename) -- Gets the filename of the current video being processed
  - [setfilename](#setfilename) -- Sets the filename of the video to be processed.
  - [setBitrate](#setbitrate) -- Sets the bitrate of the video.
  - [muteAudio](#muteaudio) -- Mutes the audio of the video.
  - [omitClip](#omitclip) -- Omits a section of the video between two specified times.
  - [setSpeed](#setspeed) -- Adjusts the playback speed of the video.
  - [setRes](#setres) -- Sets the resolution of the video.
  - [setVol](#setvol) -- Adjusts the volume level of the video

## `Action` Class


#### Constructor
[[back to top]](#documentation)
##### Prototype
```c++
Action(std::string &filename)
```
##### Description
Constructor of the `Action` class, with a given video file name as `filename`, it constructs an instance of a `Action` class, which can be used to do a range of operation afterward, for example, extract frame from at specific time, extract an independent audio track.
##### Parameter
|Parameter|Description|
|-|-|
|`filename`|Directory of the video going to process,<br>it can be either a absolute path or relative path.|
##### Example
```c++
#include "Egnine/action.h"

int main()
{
    Action *a1 = new Action("Hello_world_Video.mp4");
    return 0;
}
```


#### play
[[back to top]](#documentation)
##### Prototype
```c++
void play(std::string &arg)
```
##### Description
Play the given source video.
Note that it is redirect to `ffplay` command, so you can still pass the arguments that you may use in `ffplay` command. For example, `-nodisp` for play the audio without a GUI window.
##### Parameter
|Parameter|Description|
|-|-|
|`arg`|The options you specify when you play the source video.(See `man ffplay`)|
##### Example
```c++
#include "Egnine/action.h"

int main()
{
    Action *a1 = new Action("Hello_world_Video.mp4");
    a1.play("-nodisp")
    return 0;
}
```


#### extractFrame
[[back to top]](#documentation)
##### Prototype
```c++
void extractFrame( std::string &seektime,
                   std::string &height,
                   std::string &width,
                   std::string &ofilepath )
```
##### Description
Extract a frame at a specific time point from the video.
##### Parameter
##### Example


#### extractAudio
[[back to top]](#documentation)
##### Prototype
```c++
void extractAudio( std::string &seektime,
                   std::string &bitrate,
                   std::string &ofilepath )
```
##### Description
Extracts an independent audio track from the video at a specific time with a specified bitrate.
##### Parameters

| Parameter   | Description                                      |
|-------------|--------------------------------------------------|
| `seektime`  | Time in the video to extract the audio.           |
| `bitrate`   | Bitrate of the extracted audio.                   |
| `ofilepath` | Output file path to save the extracted audio.     |
##### Example


#### extractClip
[[back to top]](#documentation)
##### Prototype
```c++
void extractClip( std::string &seektime,
                  std::string &duration,
                  std::string &ofilepath )
```
##### Description
Extracts a clip from the video starting at a specified time for a defined duration.
##### Parameters

| Parameter   | Description                                     |
|-------------|-------------------------------------------------|
| `seektime`  | Time in the video to start the extracted clip.   |
| `duration`  | Duration of the extracted clip.                  |
| `ofilepath` | Output file path to save the extracted clip.     |
##### Example


#### splitVideo
[[back to top]](#documentation)
##### Prototype
```c++
void splitVideo( std::string &splitseek,
                 std::string &ofilepath1,
                 std::string &ofilepath2 )
```

##### Description
Splits the video into two parts at a specified time.

##### Parameters

| Parameter     | Description                                       |
|---------------|---------------------------------------------------|
| `splitseek`   | Time in the video to split it into two parts.      |
| `ofilepath1`  | Output file path for the first split video.        |
| `ofilepath2`  | Output file path for the second split video.       |
##### Example


#### overlayAudio
[[back to top]](#documentation)
##### Protype
```c++
void Action::overlayAudio( std::string &audiofile,
                           std::string &ofilepath )
```
##### Description
##### Parameter
##### Example


#### overlaySub
[[back to top]](#documentation)
##### Prototype
```c++
void Action::overlaySub( std::string &subfile,
                         std::string &vcodec,
                         std::string &ofilepath )
```
##### Description
##### Parameter
##### Example


#### convertVideo
[[back to top]](#documentation)
##### Prototype
```c++
void Action::convertVideo( std::string &extn,
                           std::string &vcodec,
                           std::string &acodec )
```
##### Description
Convert video's format and codec.
##### Parameter
##### Example

#### getGif
[[back to top]](#documentation)
##### Prototype
```c++
void Action::getGif( std::string &seektime,
                     std::string &duration,
                     std::string &height,
                     std::string &width,
                     std::string &ofilepath,
                     std::string &framerate )
```
##### Description
Generate a gif from a given video.
##### Parameter
##### Example


#### concat
[[back to top]](#documentation)
##### Prototype
```c++
void concat(std::string &ofilepath)
```
##### Description
Concatenates multiple video files listed in `inputlist.txt` into a single video file.
##### Parameters

| Parameter   | Description                                |
|-------------|--------------------------------------------|
| `ofilepath` | Output file path to save the concatenated video. |
##### Example

#### getfilename
[[back to top]](#documentation)
##### Prototype
```c++
std::string getfilename()
```
##### Description
Gets the filename of the current video being processed.
##### Return Value
String containing the filename of the video.
##### Example


#### setfilename
[[back to top]](#documentation)
##### Prototype
```c++
void setfilename(std::string filename)
```
##### Description
Sets the filename of the video to be processed.
##### Parameters
| Parameter   | Description                               |
|-------------|-------------------------------------------|
| `filename`  | New filename for the video to be processed. |
##### Example


#### setBitrate
[[back to top]](#documentation)
##### Prototype
```c++
void setBitrate( std::string &bitrate,
                 std::string &ofilepath )
```
##### Description
Sets the bitrate of the video.
##### Parameters
| Parameter   | Description                                  |
|-------------|----------------------------------------------|
| `bitrate`   | New bitrate for the video.                   |
| `ofilepath` | Output file path for the adjusted video.     |
##### Example


#### muteAudio
[[back to top]](#documentation)
##### Prototype
```c++
void muteAudio(std::string &ofilepath)
```
##### Description
Mutes the audio of the video.
##### Parameters
| Parameter   | Description                            |
|-------------|----------------------------------------|
| `ofilepath` | Output file path for the muted video.   |
##### Example


#### omitClip
[[back to top]](#documentation)
##### Prototype
```c++
void omitClip( std::string &seektime_ini,
               std::string &seektime_fn,
               std::string &ofilepath )
```
##### Description
Omits a section of the video between two specified times.
##### Parameters
| Parameter       | Description                                       |
|-----------------|---------------------------------------------------|
| `seektime_ini`  | Start time to omit the video section.              |
| `seektime_fn`   | End time to omit the video section.                |
| `ofilepath`     | Output file path for the processed video.          |
##### Example


#### setSpeed
[[back to top]](#documentation)
##### Prototype
```c++
void setSpeed(std::string &ofilepath, double speed)
```
##### Description
Adjusts the playback speed of the video.
##### Parameters
| Parameter   | Description                                   |
|-------------|-----------------------------------------------|
| `ofilepath` | Output file path for the adjusted speed video. |
| `speed`     | Speed multiplier for playback adjustment.      |
##### Example


#### setRes
[[back to top]](#documentation)
##### Prototype
```c++
void setRes( std::string &height,
             std::string &width,
             std::string &ofilepath )
```
##### Description
Sets the resolution of the video.
##### Parameters
| Parameter   | Description                                |
|-------------|--------------------------------------------|
| `height`    | Height of the adjusted video resolution.   |
| `width`     | Width of the adjusted video resolution.    |
| `ofilepath` | Output file path for the adjusted video.   |
##### Example


#### setVol
[[back to top]](#documentation)
##### Prototype
```c++
void setVol( std::string &vol,
             std::string &ofilepath )
```
##### Description
Adjusts the volume level of the video.
##### Parameters
| Parameter   | Description                              |
|-------------|------------------------------------------|
| `vol`       | Volume adjustment level.                 |
| `ofilepath` | Output file path for the adjusted video. |
##### Example
