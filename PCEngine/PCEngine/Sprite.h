//
//  Sprite.h
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 5..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#ifndef __PCEngine__Sprite__
#define __PCEngine__Sprite__

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>

namespace baram {
    class Sprite {
    private:
        const char* mFile;
        int z;
        SDL_Rect mRect;
        SDL_Rect mOriginalRect;
        SDL_Texture* mTexture;
        SDL_Renderer* mRenderer;
    public:
        Sprite();
        Sprite(int, int);
        Sprite(SDL_Renderer*, const char*);
        Sprite(const Sprite&);
        ~Sprite();
        
        void loadTexture(SDL_Renderer&, const char&);
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        const SDL_Rect& getRect();
        void setX(int);
        void setY(int);
        void setWidth(int);
        void setHeight(int);
        void setRect(SDL_Rect&);
        void expend(float);
        
        friend class SpriteManager;
    };
}

#endif

