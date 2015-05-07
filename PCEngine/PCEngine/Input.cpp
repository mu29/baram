//
//  Input.cpp
//  PCEngine
//
//  Created by 정인중 on 2015. 5. 7..
//  Copyright (c) 2015년 작은별. All rights reserved.
//

#include <SDL2/SDL.h>
#include "Input.h"
#include "Constant.h"
using namespace baram;

Input::Input() {
    currentKeyTable = new bool[Key::NUMBER];
    previousKeyTable = new bool[Key::NUMBER];
}

Input::~Input() {
    delete[] currentKeyTable;
    delete[] previousKeyTable;
}

void Input::update() {
    for (int i = 0; i < Key::NUMBER; i++) {
        previousKeyTable[i] = currentKeyTable[i];
    }
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYUP:
                updateKeyTable(event, false);
                break;
            case SDL_KEYDOWN:
                updateKeyTable(event, true);
                break;
            case SDL_MOUSEMOTION:
                
                break;
            case SDL_MOUSEBUTTONUP:
                
                break;
            case SDL_MOUSEBUTTONDOWN:
                
                break;
            case SDL_QUIT:
                currentKeyTable[Key::QUIT] = true;
                break;
        }
    }
}

void Input::updateKeyTable(SDL_Event& _event, bool _value) {
    switch (_event.key.keysym.sym)
    {
        case SDLK_UP:
            currentKeyTable[Key::UP] = _value;
            break;
        case SDLK_DOWN:
            currentKeyTable[Key::DOWN] = _value;
            break;
        case SDLK_LEFT:
            currentKeyTable[Key::LEFT] = _value;
            break;
        case SDLK_RIGHT:
            currentKeyTable[Key::RIGHT] = _value;
            break;
        case SDLK_SPACE:
        case SDLK_RETURN:
            currentKeyTable[Key::CONFIRM] = _value;
            break;
    }
}

bool Input::trigger(int code) {
    return !currentKeyTable[code] && previousKeyTable[code];
}

bool Input::press(int code) {
    return currentKeyTable[code] && previousKeyTable[code];
}

Input* Input::mInstance = nullptr;