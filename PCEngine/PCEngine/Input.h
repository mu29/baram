//
//  Input.h
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 7..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#ifndef __PCEngine__Input__
#define __PCEngine__Input__

namespace baram {
    class Input {
    private:
        bool* currentKeyTable;
        bool* previousKeyTable;
        static Input* mInstance;
        
        Input();
        ~Input();
        
        void updateKeyTable(SDL_Event&, bool);
    public:
        void update();
        bool trigger(int);
        bool press(int);
        
        static Input* getInstance() {
            if (mInstance == nullptr)
                mInstance = new Input();
            
            return mInstance;
        }
    };
}

#endif /* defined(__PCEngine__Input__) */
