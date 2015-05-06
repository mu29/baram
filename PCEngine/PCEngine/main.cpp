//
//  main.cpp
//  baram
//
//  Created by 정인중 on 2015. 5. 5..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Screen.h"
using namespace baram;

int main( int argc, char* args[] )
{
    Screen* screen = new Screen();
    
    bool loop = true;
    while (loop) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                loop = false;
        }
        screen->draw();
        SDL_Delay( 16 );
    }
    
    return 0;
}
