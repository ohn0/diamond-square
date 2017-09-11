#ifndef _image_handler_H
#define _image_handler_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
class image_handler{
public:
    image_handler();
    ~image_handler();
    void load_image(const std::string,  SDL_Renderer*);
    void render_image_screen(const SDL_Window*, SDL_Renderer*);
    void render_image_rect(const SDL_Window*,  SDL_Renderer*, const SDL_Rect*);
private:
    void clean();
    SDL_Texture* image_tex = NULL;


};
#endif // _image_handler_H
