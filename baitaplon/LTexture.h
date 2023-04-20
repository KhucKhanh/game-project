#ifndef __LTEXTURE_H__
#define __LTEXTURE_H__

#include<SDL.h>
#include<SDL_ttf.h>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>

using namespace std;
class LTexture
{
public:
    LTexture();
    ~LTexture();
    bool loadFromRenderedText ( SDL_Renderer* gRenderer, TTF_Font* gFont, string textureText, SDL_Color textColor );
    void free();
    void setcolor(Uint8 red, Uint8 green, Uint8 blue); //0-255
    void render (SDL_Renderer* gRenderer, int x, int y, int W, int H);
    int getWidth();
    int getHeight();


private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
};
#endif // _LTEXTURE_H_
