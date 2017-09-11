#include "image_handler.h"
#include <cmath>
#include <iostream>
#define MAX_ITERATIONS 100
float mandelbrotValue(float, float);

int main(int argc, char* args[]){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH
                                          ,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    bool fractalGenerated = false;
    SDL_Event e;
    SDL_Rect rect = {0,0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
        }
        float scrWidthThird = (float) SCREEN_WIDTH/3.f;
        float scrHeightHalf = (float) SCREEN_HEIGHT/2.f;
        float mandelbrotLevel = 0.f;
        if(!fractalGenerated){
            for(int i = 0; i < SCREEN_WIDTH; i++){
                for(int j = 0; j < SCREEN_HEIGHT; j++){
                    float normX, normY;
                    normX = (((float)i)/scrWidthThird) - 2;
                    normY = (((float)j)/scrHeightHalf) - 1;
                    if(normX > 1 || normX < -2){
                        std::cout << "Normalization failed: X value:" << normX << std::endl;
                    }
                    if(normY > 1 || normY < -1){
                        std::cout << "Normalization failed: Y value: " << normY << std::endl;
                    }
                    mandelbrotLevel = mandelbrotValue(normX, normY);
                    if(mandelbrotLevel < 2){
                        SDL_SetRenderDrawColor(renderer, 0x00, 0xEE, 0xFC, 0xFF);
    //                    std::cout << normX << " " << normY << std::endl;
                    }
                    else{
                        SDL_SetRenderDrawColor(renderer, (int)mandelbrotLevel % 0xFF, 0x00, 0x00, 0xFF);
                    }
                    SDL_RenderDrawPoint(renderer, i, j);
                }
            fractalGenerated = true;
        }
        }

//        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
//        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit(); IMG_Quit();
    return 0;
}

float mandelbrotValue(float X, float Y)
{
    //Return true if the complex value is bounded.
    float Zval = sqrt(pow(X, 2) + pow(Y, 2));
    float Zx = X;
    float Zy = Y;
    float tX, tY;
    int i = 0;
    while(Zval < 2 && i++ < MAX_ITERATIONS){
        tX = Zx;
        tY = Zy;
        Zx = pow(tX,2) - pow(tY,2);
        Zx += X;
        Zy = 2 * tX * tY;
        Zy += Y;
        Zval = sqrt(pow(Zx,2) + pow(Zy,2));
    }

    if(Zval < 2){
        return Zval;
    }
    else{
        return (float)i;
    }
}
