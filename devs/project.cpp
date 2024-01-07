#include <iostream>
#include <sstream>
#include <string>
#include<stdlib.h>
#include<algorithm>
#include"project.hpp"

using namespace std;

string inputfile()
{
    FILE* pipe = popen("zenity --entry --text=\"Escribe tu nombre\"", "r");
    if (!pipe) {
        std::cerr << "Error opening pipe." << std::endl;
        //return EXIT_FAILURE;
    }

    // 读取zenity的输出
    char buffer[128];
    std::ostringstream result_stream;
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result_stream << buffer;
    }

    // 关闭zenity进程
    pclose(pipe);

    // 获取用户输入
    string result = result_stream.str();

    // 打印用户输入
    cout << "您输入的内容是: " << result;
    return result;
}


void openfile() {
    FILE* pipe = popen("zenity --file-selection --title=\"select your project\"", "r");
    if (!pipe) {
        std::cerr << "打开管道时发生错误。" << std::endl;
        return;
    }

    char buffer[128];
    std::string result = "";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }

    // 关闭zenity进程
    pclose(pipe);

    // 去除末尾的换行符
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) { return c == '\n'; }), result.end());

    // 打印用户选择的文件路径
    std::cout << "您选择的文件路径是: " << result << std::endl;
}