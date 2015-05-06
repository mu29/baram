//
//  Sprite.cpp
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 5..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#include "Sprite.h"
#include "SpriteManager.h"
#include "Error.h"
using namespace baram;

Sprite::Sprite() {
    mRect.x = 0;
    mRect.y = 0;
    mRect.w = 0;
    mRect.h = 0;
    mOriginalRect = mRect;
    z = 0;
    mTexture = NULL;
    mRenderer = NULL;
}

Sprite::Sprite(int _width, int _height) {
    mRect.x = 0;
    mRect.y = 0;
    mRect.w = _width;
    mRect.h = _height;
    mOriginalRect = mRect;
    z = 0;
    mTexture = NULL;
    mRenderer = NULL;
}

Sprite::Sprite(SDL_Renderer* _renderer, const char* _file) {
    mRect.x = 0;
    mRect.y = 0;
    z = 0;
    mFile = _file;
    mRenderer = _renderer;
    loadTexture(*mRenderer, *mFile);
}

Sprite::Sprite(const Sprite& other) {
    mRect.x = 0;
    mRect.y = 0;
    z = 0;
    mFile = other.mFile;
    mRenderer = other.mRenderer;
    loadTexture(*mRenderer, *mFile);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mRenderer = NULL;
}

void Sprite::loadTexture(SDL_Renderer& _renderer, const char& _file) {
    try {
        mTexture = IMG_LoadTexture(&_renderer, &_file);
        if (mTexture == nullptr)
            throw Error::NULL_TEXTURE;
        
        SDL_QueryTexture(mTexture, NULL, NULL, &mRect.w, &mRect.h);
        mOriginalRect = mRect;
        SpriteManager* manager = SpriteManager::getInstance();
        manager->addSprite(*this);
    } catch (int e) {
        Error::print(e, SDL_GetError());
    }
}

int Sprite::getX() {
    return mRect.x;
}

int Sprite::getY() {
    return mRect.y;
}

int Sprite::getWidth() {
    return mRect.w;
}

int Sprite::getHeight() {
    return mRect.h;
}

const SDL_Rect& Sprite::getRect() {
    return mRect;
}

void Sprite::setX(int _x) {
    mRect.x = _x;
}

void Sprite::setY(int _y) {
    mRect.y = _y;
}

void Sprite::setWidth(int _width) {
    _width = _width < 0 ? -_width : _width;
    mRect.w = _width;
}

void Sprite::setHeight(int _height) {
    _height = _height < 0 ? -_height : _height;
    mRect.h = _height;
}

void Sprite::setRect(SDL_Rect& rect) {
    mRect.x = rect.x;
    mRect.y = rect.y;
    mRect.w = rect.w;
    mRect.h = rect.h;
}

void Sprite::expend(float rate) {
    mRect.w *= rate;
    mRect.h *= rate;
}
