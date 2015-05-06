//
//  SpriteManager.cpp
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 6..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#include <SDL2/SDL.h>
#include "SpriteManager.h"
using namespace baram;

SpriteManager::SpriteManager() {
    spriteList.clear();
}

SpriteManager::~SpriteManager() {
    spriteList.clear();
}

void SpriteManager::addSprite(Sprite& _sprite) {
    for(list<Sprite*>::iterator iter = spriteList.begin(); iter != spriteList.end(); ++iter) {
        if ((*iter)->z > _sprite.z) {
            spriteList.insert(--iter, &_sprite);
            break;
        }
    }
    
    spriteList.push_back(&_sprite);
}

void SpriteManager::removeSprite(Sprite& _sprite) {
    spriteList.remove(&_sprite);
}

void SpriteManager::draw(SDL_Renderer& _renderer) {
    for(list<Sprite*>::iterator iter = spriteList.begin(); iter != spriteList.end(); ++iter) {
        SDL_RenderCopy(&_renderer, (*iter)->mTexture, NULL, &((*iter)->mRect));
    }
}

SpriteManager* SpriteManager::mInstance = nullptr;
