#ifndef GuiContent_H
#define GuiContent_H

#include <SDL2/SDL.h>

#include "editor/editor.hpp"

enum PropertiesMode {
    PROPMODE_NONE_SELECTED,
    PROPMODE_TRACK_SELECTOR,
    PROPMODE_FILTER_LIST,
    PROPMODE_FILTER_CONFIG
};

extern int timer_scroll;
extern int current_media_length;
extern std::string current_media_name;
extern std::vector<TrackType> current_streams;
extern std::vector<Filter*> current_filters;

extern std::string grabbed_media;
extern int grabbed_media_track_index;
extern int grabbed_media_position;
extern TrackType grabbed_media_type;

extern void properties_change_mode(PropertiesMode mode);

extern void gui_content_properties(SDL_Renderer* renderer, int x, int y, int w, int h);
extern void gui_content_file_browser(SDL_Renderer* renderer, int x, int y, int w, int h);
extern void gui_content_player(SDL_Renderer* renderer, int x, int y, int w, int h);
extern void gui_content_timer(SDL_Renderer* renderer, int x, int y, int w, int h);
extern void gui_content_timeline(SDL_Renderer* renderer, int x, int y, int w, int h);

#endif