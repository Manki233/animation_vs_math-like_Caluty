#ifndef F_TILEMOVE

#define F_TILEMOVE

#include "..\configure.h"
#include "equals.h"

void Tile :: Update () {
    if (moving == LINEAR) {
        Move (targetPos, moveTime);
    }

    if (moving == STATIC && tileType == EQUAL && (g_GameTick % (FPS * 2) == 0)) {
        DoEqual (this);
    }
}

void Tile :: Move (Vec2 argPos) {
    pos = argPos;
}

void Tile :: Move (Vec2 argPos, Tick time) {
    if (abs (argPos - pos) <= 1) { // 递归边界
        Move (argPos);             // 完成工作
        moving = STATIC;           // 状态设置
        return ;
    }

    moving = LINEAR;

    Vec2 force = argPos - pos;        // 总共要走的路程
    Vec2 dForce = force / (0.3 * time. tick); // 一帧要走的路程，d表示微分，这里借用

    Move (pos + dForce);// 移动

    targetPos = argPos; // 路程设置，留给下一次做
    moveTime = time - 1;// 时间因为用了一帧，所以 - 1

    return ;            // 放心留给下一帧吧
}

#endif
