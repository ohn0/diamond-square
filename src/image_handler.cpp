#include "image_handler.h"
image_handler::image_handler(){
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
}

image_handler::~image_handler(){
    clean();
}

void image_handler::load_image(const std::string path, SDL_Renderer* renderer){
    SDL_Surface* temp_surface = IMG_Load(path.c_str());
    image_tex = SDL_CreateTextureFromSurface(renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
}

void image_handler::render_image_screen(const SDL_Window* window, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, image_tex, NULL, NULL);
}

void image_handler::render_image_rect(const SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect* rect){
    SDL_RenderSetViewport(renderer, rect);
    SDL_RenderCopy(renderer, image_tex, NULL, NULL);
    SDL_RenderSetViewport(renderer, NULL);
}

void image_handler::clean(){
    SDL_DestroyTexture(image_tex);
}
