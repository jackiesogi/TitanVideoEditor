# Documentation
---
- [Documentation](#documentation)
  - [`Action` Class](#action-class)
      - [`Action(std::string &filename)`](#actionstdstring-filename)
        - [Description](#description)
        - [Parameter](#parameter)
        - [Return Value](#return-value)
        - [Example](#example)
      - [`void exec(std::string &arg)`](#void-execstdstring-arg)
      - [`void extractFrame(std::string &seektime, std::string &height, std::string &width, std::string &ofilepath)`](#void-extractframestdstring-seektime-stdstring-height-stdstring-width-stdstring-ofilepath)
      - [`void extractAudio(std::string &seektime, std::string &bitrate, std::string &ofilepath)`](#void-extractaudiostdstring-seektime-stdstring-bitrate-stdstring-ofilepath)
        - [Description](#description-1)
        - [Parameters](#parameters)
      - [`void extractClip(std::string &seektime, std::string &duration, std::string &ofilepath)`](#void-extractclipstdstring-seektime-stdstring-duration-stdstring-ofilepath)
        - [Description](#description-2)
        - [Parameters](#parameters-1)
      - [`void splitVideo(std::string &splitseek, std::string &ofilepath1, std::string &ofilepath2)`](#void-splitvideostdstring-splitseek-stdstring-ofilepath1-stdstring-ofilepath2)
        - [Description](#description-3)
        - [Parameters](#parameters-2)
      - [`void concat(std::string &ofilepath)`](#void-concatstdstring-ofilepath)
        - [Description](#description-4)
        - [Parameters](#parameters-3)
      - [`std::string getfilename()`](#stdstring-getfilename)
        - [Description](#description-5)
        - [Return Value](#return-value-1)
      - [`void setfilename(std::string filename)`](#void-setfilenamestdstring-filename)
        - [Description](#description-6)
        - [Parameters](#parameters-4)
      - [`void setBitrate(std::string &bitrate, std::string &ofilepath)`](#void-setbitratestdstring-bitrate-stdstring-ofilepath)
        - [Description](#description-7)
        - [Parameters](#parameters-5)
      - [`void muteAudio(std::string &ofilepath)`](#void-muteaudiostdstring-ofilepath)
        - [Description](#description-8)
        - [Parameters](#parameters-6)
      - [`void omitClip(std::string &seektime_ini, std::string &seektime_fn, std::string &ofilepath)`](#void-omitclipstdstring-seektime_ini-stdstring-seektime_fn-stdstring-ofilepath)
        - [Description](#description-9)
        - [Parameters](#parameters-7)
      - [`void setSpeed(std::string &ofilepath, double speed)`](#void-setspeedstdstring-ofilepath-double-speed)
        - [Description](#description-10)
        - [Parameters](#parameters-8)
      - [`void setRes(std::string &height, std::string &width, std::string &ofilepath)`](#void-setresstdstring-height-stdstring-width-stdstring-ofilepath)
        - [Description](#description-11)
        - [Parameters](#parameters-9)
      - [`void setVol(std::string &vol, std::string &ofilepath)`](#void-setvolstdstring-vol-stdstring-ofilepath)
        - [Description](#description-12)
        - [Parameters](#parameters-10)

---

## `Action` Class
#### `Action(std::string &filename)`
##### Description
Constructor of the `Action` class, with a given video file name as `filename`, it construct an instance of a `Action` class, which can be used to do a range of operation afterward, for example, extract frame from at specific time, extract an independent audio track.
##### Parameter

|Parameter|Description|
|-|-|
|`filename`|Directory of the video going to process,<br>it can be either a absolute path or relative path.|
##### Return Value
（None）

##### Example
```c++
#include "Egnine/action.h"

int main()
{
    Action *a1 = new Action("Hello_world_Video.mp4");
    return 0;
}
```
#### `void exec(std::string &arg)`
#### `void extractFrame(std::string &seektime, std::string &height, std::string &width, std::string &ofilepath)`

#### `void extractAudio(std::string &seektime, std::string &bitrate, std::string &ofilepath)`

##### Description
Extracts an independent audio track from the video at a specific time with a specified bitrate.

##### Parameters

| Parameter   | Description                                      |
|-------------|--------------------------------------------------|
| `seektime`  | Time in the video to extract the audio.           |
| `bitrate`   | Bitrate of the extracted audio.                   |
| `ofilepath` | Output file path to save the extracted audio.     |


#### `void extractClip(std::string &seektime, std::string &duration, std::string &ofilepath)`

##### Description
Extracts a clip from the video starting at a specified time for a defined duration.

##### Parameters

| Parameter   | Description                                     |
|-------------|-------------------------------------------------|
| `seektime`  | Time in the video to start the extracted clip.   |
| `duration`  | Duration of the extracted clip.                  |
| `ofilepath` | Output file path to save the extracted clip.     |


#### `void splitVideo(std::string &splitseek, std::string &ofilepath1, std::string &ofilepath2)`

##### Description
Splits the video into two parts at a specified time.

##### Parameters

| Parameter     | Description                                       |
|---------------|---------------------------------------------------|
| `splitseek`   | Time in the video to split it into two parts.      |
| `ofilepath1`  | Output file path for the first split video.        |
| `ofilepath2`  | Output file path for the second split video.       |

// ... (Repeat the structure for each function)


#### `void concat(std::string &ofilepath)`

##### Description
Concatenates multiple video files listed in `inputlist.txt` into a single video file.

##### Parameters

| Parameter   | Description                                |
|-------------|--------------------------------------------|
| `ofilepath` | Output file path to save the concatenated video. |

#### `std::string getfilename()`

##### Description
Gets the filename of the current video being processed.

##### Return Value
String containing the filename of the video.


#### `void setfilename(std::string filename)`

##### Description
Sets the filename of the video to be processed.

##### Parameters

| Parameter   | Description                               |
|-------------|-------------------------------------------|
| `filename`  | New filename for the video to be processed. |


#### `void setBitrate(std::string &bitrate, std::string &ofilepath)`

##### Description
Sets the bitrate of the video.

##### Parameters

| Parameter   | Description                                  |
|-------------|----------------------------------------------|
| `bitrate`   | New bitrate for the video.                   |
| `ofilepath` | Output file path for the adjusted video.     |


#### `void muteAudio(std::string &ofilepath)`

##### Description
Mutes the audio of the video.

##### Parameters

| Parameter   | Description                            |
|-------------|----------------------------------------|
| `ofilepath` | Output file path for the muted video.   |


#### `void omitClip(std::string &seektime_ini, std::string &seektime_fn, std::string &ofilepath)`

##### Description
Omits a section of the video between two specified times.

##### Parameters

| Parameter       | Description                                       |
|-----------------|---------------------------------------------------|
| `seektime_ini`  | Start time to omit the video section.              |
| `seektime_fn`   | End time to omit the video section.                |
| `ofilepath`     | Output file path for the processed video.          |


#### `void setSpeed(std::string &ofilepath, double speed)`

##### Description
Adjusts the playback speed of the video.

##### Parameters

| Parameter   | Description                                   |
|-------------|-----------------------------------------------|
| `ofilepath` | Output file path for the adjusted speed video. |
| `speed`     | Speed multiplier for playback adjustment.      |


#### `void setRes(std::string &height, std::string &width, std::string &ofilepath)`

##### Description
Sets the resolution of the video.

##### Parameters

| Parameter   | Description                                |
|-------------|--------------------------------------------|
| `height`    | Height of the adjusted video resolution.   |
| `width`     | Width of the adjusted video resolution.    |
| `ofilepath` | Output file path for the adjusted video.   |


#### `void setVol(std::string &vol, std::string &ofilepath)`

##### Description
Adjusts the volume level of the video.

##### Parameters

| Parameter   | Description                              |
|-------------|------------------------------------------|
| `vol`       | Volume adjustment level.                 |
| `ofilepath` | Output file path for the adjusted video. |

