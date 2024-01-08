#include"tempfile.hpp"


void record_temp_file_info(const std::string& filename, const Clip& fileInfo, std::map<std::string,Clip>& fileMap) 
{
    fileMap[filename] = fileInfo;
}

int write_temp_file(char* buffer, size_t length, std::map<std::string,Clip>& fileMap)
{
    int len = length;
    char filename[] = "/tmp/mytemp.XXXXXX";
    int fd = mkstemp(filename);

    // 在這裡加入設定檔案屬性的代碼
    Clip fileInfo;
    fileInfo.filename = "video/mp4";  // 根據實際需求設定 MIME Type
    fileInfo.filesize = len;

    // 將檔案名稱和屬性結構存入 map 中
    fileMap[filename] = fileInfo;

    unlink(filename);
    printf("template file name: %s\n", filename);
    write(fd, &len, sizeof(len));
    write(fd, buffer, len);

    return fd;
}

void query_file_info(const std::map<std::string,Clip>& fileMap, const std::string& filename)
{
    auto it = fileMap.find(filename);
    if (it != fileMap.end()) {
        // 檔案存在，可以使用 it->second 存取屬性
        std::cout << "File found - MIME Type: " << it->second.filename
                  << ", File Size: " << it->second.filesize << " bytes" << std::endl;
    } else {
        std::cout << "File not found." << std::endl;
    }
}

void delete_file_info(std::map<std::string,Clip>& fileMap, const std::string& filename)
{
    auto it = fileMap.find(filename);
    if (it != fileMap.end()) {
        // 檔案存在，可以使用 erase 刪除條目
        fileMap.erase(it);
        std::cout << "File information deleted for file: " << filename << std::endl;
    } else {
        std::cout << "File not found." << std::endl;
    }
}



/*
int main()
{
    std::map<std::string, TempFileInfo> fileMap;

    // 使用 write_temp_file 函數創建臨時檔案
    int fd = write_temp_file(/* buffer */, /* length */, fileMap);

    // 在這裡可以使用 fileMap 來查詢檔案的屬性

    // 最後，請確保在程式執行完畢時關閉檔案描述符
    close(fd);

    return 0;
}


*/

