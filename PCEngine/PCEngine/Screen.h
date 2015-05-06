//
//  Screen.h
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 6..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#ifndef __PCEngine__Screen__
#define __PCEngine__Screen__

#include <SDL2/SDL.h>
namespace baram {
    class Screen {
    private:
        SDL_Rect mWindowRect;
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        
        bool initSDL();
        bool createWindow();
        bool createRenderer();
        void setupRenderer();
    public:
        Screen();
        ~Screen();
        void update();
        void draw();
    };
}

#endif
