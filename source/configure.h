#ifndef F_CONFIGURE

#define F_CONFIGURE

// It's define basic and include lib.

#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

#include <graphics.h>

#define WINDOW_LENGTH_X 1280
#define WINDOW_LENGTH_Y 720

#define WEB_LENGTH 32

#define WEB_COUNT_X 40
#define WEB_COUNT_Y 22

#define MOUSE_LEFT_DOWN keystate(key_mouse_l) 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

struct Vec2 { // 二元坐标组
    int x = 0;
    int y = 0;

    Vec2 (int argX, int argY) {
        x = argX,
        y = argY;
    }

    Vec2 () {
        x = 0,
        y = 0;
    }

    Vec2 operator + (const int argB) const {
        return {x + argB, y + argB};
    }

    Vec2 operator + (const Vec2 argB) const {
        return {x + argB. x, y + argB. y};
    }

    Vec2 operator - (const int argB) const {
        return {x - argB, y - argB};
    }

    Vec2 operator - (const Vec2 argB) const {
        return {x - argB. x, y - argB. y};
    }

    Vec2 operator / (const int argB) const {
        return {
            x / argB,
            y / argB
        };
    }

    bool operator <= (const int argB) const {
        return (x <= argB && y <= argB);
    }

    bool operator == (const Vec2 argB) const {
        return !(*this != argB);
    }

    bool operator != (const Vec2 argB) const {
        return !(x == argB. x && y == argB. y);
    }
};

Vec2 abs (Vec2 a) {
    return {abs (a. x), abs (a. y)};
}

int GetLength (int x) {
    int length = 0;

    while (x > 9) {
        x /= 10;
        length ++;
    }

    return length + 1;
}

#include "gameupdater.h"

#include "eval.h"

#include "time.h"
#include "entity\tile.h"
#include "engine.h"
#include "entity\tilemove.h"
#include "entity\death.h"
#include "entity\spawn.h"
#include "entity\equals.h"

#include "setupdate.h"

#endif
