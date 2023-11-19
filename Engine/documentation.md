# Documentation
- [Action Class](#action-class)
  - [Constructor](#constructor)
## `Action` Class
### Constructor
#### `Action(std::string &filename)`
##### Description
Constructor of the `Action` class, with a given video file name as `filename`, it construct an instance of a `Action` class, which can be used to do a range of operation afterward, for example, extract frame from at specific time, extract an independent audio track.
##### Parameter

|Parameter|Description|
|-|-|
|`filename`|Directory of the video going to process,<br>it can be either a absolute path or relative path.|
##### Return Value
（Non）

##### Example
```c++
#include "Egnine/action.h"

int main()
{
    Action *a1 = new Action("Hello_world_Video.mp4");
    return 0;
}
```