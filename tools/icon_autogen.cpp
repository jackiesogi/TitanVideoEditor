#include <fstream>
#include <filesystem>
#include <string>
#include <map>

std::string c_filename(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        char character = str[i];
        if (character >= 'A' && character <= 'Z') continue;
        if (character >= 'a' && character <= 'z') continue;
        if (character >= '0' && character <= '9') continue;
        str[i] = '_';
    }
    return str;
}

void write_if_not_same(std::filesystem::path path, std::string content) {
    if (std::filesystem::exists(path)) {
        int size = std::filesystem::file_size(path);
        char* data = (char*)malloc(size);
        std::ifstream stream = std::ifstream(path, std::ios::binary);
        stream.read(data, size);
        stream.close();
        std::string str = std::string(data, size);
        free(data);
        if (str == content) return;
    }
    std::ofstream stream = std::ofstream(path, std::ios::binary);
    stream.write(content.data(), content.size());
    stream.close();
}

int main() {
    std::map<std::string, std::string> syscursors = {
        { "move", "SIZEALL" },
        { "move_horizontal", "SIZEWE" },
        { "move_vertical", "SIZENS" }
    };

    std::string cursors_c = "";
    std::string cursors_h = "";
    std::string icons_c = "";
    std::string icons_h = "";

    cursors_c += "#include \"utils.hpp\"\n";
    cursors_c += "#include \"assets/assetdata.hpp\"\n";
    cursors_c += "#include <SDL2/SDL.h>\n";
    cursors_c += "\n";
    cursors_c += "// This file is automatically generated by the build system\n";
    cursors_c += "// Any changes to this file will be overwritten during build\n";
    cursors_c += "\n";
    cursors_c += "SDL_Cursor* cursor_default = nullptr;\n";

    cursors_h += "#ifndef Cursors_H\n";
    cursors_h += "#define Cursors_H\n";
    cursors_h += "\n";
    cursors_h += "#include <SDL2/SDL.h>\n";
    cursors_h += "\n";
    cursors_h += "// This file is automatically generated by the build system\n";
    cursors_h += "// Any changes to this file will be overwritten during build\n";
    cursors_h += "\n";
    cursors_h += "extern SDL_Cursor* cursor_default;\n";

    for (const auto& syscursor : syscursors) {
        cursors_c += "SDL_Cursor* cursor_" + syscursor.first + " = nullptr;\n";
        cursors_h += "extern SDL_Cursor* cursor_" + syscursor.first + ";\n";
    }

    icons_c += "#include \"utils.hpp\"\n";
    icons_c += "#include \"assets/assetdata.hpp\"\n";
    icons_c += "#include <SDL2/SDL.h>\n";
    icons_c += "\n";
    icons_c += "// This file is automatically generated by the build system\n";
    icons_c += "// Any changes to this file will be overwritten during build\n";
    icons_c += "\n";

    icons_h += "#ifndef Icons_H\n";
    icons_h += "#define Icons_H\n";
    icons_h += "\n";
    icons_h += "#include <SDL2/SDL.h>\n";
    icons_h += "\n";
    icons_h += "// This file is automatically generated by the build system\n";
    icons_h += "// Any changes to this file will be overwritten during build\n";
    icons_h += "\n";

    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::path("assets/images"))) {
        std::string name = entry.path().filename().string();
        name = name.substr(0, name.length() - 4);
        if (name.rfind("cursor_", 0) == 0) {
            cursors_h += "extern SDL_Cursor* " + name + ";\n";
            cursors_c += "SDL_Cursor* " + name + " = nullptr;\n";
        }
        else {
            icons_h += "extern SDL_Texture* icon_" + name + ";\n";
            icons_c += "SDL_Texture* icon_" + name + " = nullptr;\n";
        }
    }

    cursors_h += "\n";
    cursors_h += "extern void init_cursors();\n";
    cursors_h += "\n";
    cursors_h += "#endif\n";

    cursors_c += "\n";
    cursors_c += "void init_cursors() {\n";
    cursors_c += "    cursor_default = SDL_GetDefaultCursor();\n";

    icons_h += "\n";
    icons_h += "extern void init_icons(SDL_Renderer* renderer);\n";
    icons_h += "\n";
    icons_h += "#endif\n";

    icons_c += "\n";
    icons_c += "void init_icons(SDL_Renderer* renderer) {\n";

    for (const auto& syscursor : syscursors) {
        cursors_c += "    cursor_" + syscursor.first + " = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_" + syscursor.second + ");\n";
    }

    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::path("assets/images"))) {
        std::string name = entry.path().filename().string();
        name = name.substr(0, name.length() - 4);
        if (name.rfind("cursor_", 0) == 0) {
            cursors_c += "    " + name + " = SDL_CreateColorCursor(CreateSdlSurfaceFromPng(images_" + name + "_png), 8, 8);\n";
        }
        else {
            icons_c += "    icon_" + name + " = create_texture(renderer, images_" + name + "_png);\n";
        }
    }

    cursors_c += "}\n";
    icons_c += "}\n";

    write_if_not_same(std::filesystem::path("src/gui/lib/cursors.hpp"), cursors_h);
    write_if_not_same(std::filesystem::path("src/gui/lib/cursors.cpp"), cursors_c);
    write_if_not_same(std::filesystem::path("src/gui/lib/icons.hpp"), icons_h);
    write_if_not_same(std::filesystem::path("src/gui/lib/icons.cpp"), icons_c);

    return 0;
}