#include "LTexture.h"

LTexture::LTexture()
{
    mTexture = NULL;
    mWidth =0;
    mHeight =0;
}

LTexture::~LTexture()
{
    free();
}
bool LTexture::loadFromRenderedText(SDL_Renderer* gRenderer, TTF_Font* gFont,string textureText,SDL_Color textColor)
{
    free();
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor);
    if(textSurface != NULL)
    {
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        mWidth = textSurface->w;
        mHeight = textSurface->h;
        SDL_FreeSurface (textSurface);
    }

    else
    {
        cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() ;
    }
    return mTexture != NULL;
}

void LTexture::free()
{
    if(mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth =0;
        mHeight =0;
    }
}

void LTexture::setcolor(Uint8 red, Uint8 green, Uint8 blue){}

void LTexture::render(SDL_Renderer* gRenderer, int x, int y, int W, int H)
{
    SDL_Rect render4 = {x, y, W, H};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &render4);
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
