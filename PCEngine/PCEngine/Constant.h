//
//  Error.h
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 6..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#ifndef __PCEngine__Error__
#define __PCEngine__Error__

#include <iostream>

namespace baram {
    class Error {
    public:
        const static int NULL_SURFACE = 0;
        const static int NULL_TEXTURE = 1;
        const static int SDL_INIT_FAIL = 2;
        const static int CREATE_WINDOW_FAIL = 3;
        const static int CREATE_RENDERER_FAIL = 4;
        
        static void print(int code, const char* msg) {
            std::cout << msg << " (" << code  << ")" << std::endl;
        }
    };
    
    class Key {
    public:
        const static int NUMBER = 6;
        const static int UP = 0;
        const static int DOWN = 1;
        const static int LEFT = 2;
        const static int RIGHT = 3;
        const static int CONFIRM = 4;
        const static int QUIT = 5;
    };
}

#endif
