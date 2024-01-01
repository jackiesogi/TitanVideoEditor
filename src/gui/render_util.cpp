#include "render_util.hpp"
#include "simplEngine/action.h"
#include "gui/lib/icons.hpp"
#include "libs/portable-file-dialogs.hpp"

#include <iostream>

int translateX = 0;
int translateY = 0;

void render_translate(int x, int y) {
    translateX += x;
    translateY += y;
}

void reset_translation() {
    translateX = 0;
    translateY = 0;
}

void render_rect(SDL_Renderer* renderer, int x, int y, int width, int height, int rgba) {
    SDL_Rect rect;
    rect.x = x + translateX;
    rect.y = y + translateY;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renderer, (rgba >> 24) & 0xFF, (rgba >> 16) & 0xFF, (rgba >> 8) & 0xFF, rgba & 0xFF);
    SDL_RenderFillRect(renderer, &rect);
}

void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) {
    SDL_Rect rect;
    rect.x = x + translateX;
    rect.y = y + translateY;
    rect.w = width;
    rect.h = height;
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void render_text(SDL_Renderer* renderer, int x, int y, std::string text) {
    for (int i = 0; i < text.size(); i++) {
        int character = (int)text[i];
        SDL_Rect src;
        src.x = character % 16 * 7;
        src.y = (character / 16 - 2) * 14;
        src.w = 7;
        src.h = 14;
        SDL_Rect dst;
        dst.x = translateX + x + i * 7;
        dst.y = translateY + y;
        dst.w = 7;
        dst.h = 14;
        SDL_RenderCopy(renderer, icon_font, &src, &dst);
    }
}

void render_track(Track track)
{
    FILE* fp;
    char  buffer[1024]; // read the standard output from zenity file selection dialog
    fp = popen("zenity --file-selection --directory --title='Select an directory for exporting'", "r");
    std::string ifile = "/home/jck/Videos/simpledit.txt"; // TODO: input path has to be dynamically assign
    std::string ofile = ""; // the output mp4 path

    if(fp == NULL) {
        fprintf(stderr, "Failed to execute zenity command.");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        ofile += buffer;
    } 
    ofile.pop_back();
    ofile += "/SimplEdit_output.mp4"; 
    std::cout << ofile;
    pclose(fp);

    FILE* fd = fopen(ifile.c_str(), "w");
    for (const auto& clip : track.clips) {
        fprintf(fd, "file '%s'\n", clip.media.c_str());
    }
    // Close the file
    fclose(fd);

    std::string nil = "empty";
    Action video(nil);
    
    int res = video.concat(ifile, ofile);
    if (res == 1) {
        pfd::message("Titan Video Editor", "Something went wrong during the video exporting\n", pfd::choice::ok, pfd::icon::error);
    } else {
        pfd::message("Titan Video Editor", "Video has been exported successfully!\n", pfd::choice::ok);
    }
}