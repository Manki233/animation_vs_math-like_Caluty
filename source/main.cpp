#include "configure.h"

using namespace std;

// Code from manki

int main () {
    initgraph (WINDOW_LENGTH_X, WINDOW_LENGTH_Y, false);

    setcaption ("Caluety : from - Animations vs Math Alanbecker   Manki"); 

    cout << fixed << setpreciso
    
    SetUpdate ();

    ege_enable_aa (true); // 抗锯齿
    
    int nowCatchX = WINDOW_LENGTH_X / 2 / WEB_LENGTH - 1, nowCatchY = WINDOW_LENGTH_Y / 2 / WEB_LENGTH - 3;

    pTiles [nowCatchX - 1] [nowCatchY] = new Tile({(nowCatchX - 1) * WEB_LENGTH, nowCatchY * WEB_LENGTH}, NUMBER, '1');
    pTiles [nowCatchX] [nowCatchY] = new Tile({(nowCatchX) * WEB_LENGTH, nowCatchY * WEB_LENGTH}, NUMBER, '+');
    pTiles [nowCatchX] [nowCatchY + 1] = new Tile({(nowCatchX) * WEB_LENGTH, (nowCatchY + 1) * WEB_LENGTH}, NUMBER, '-');
    pTiles [nowCatchX] [nowCatchY - 1] = new Tile({(nowCatchX) * WEB_LENGTH, (nowCatchY - 1) * WEB_LENGTH}, NUMBER, '*');
    pTiles [nowCatchX] [nowCatchY + 2] = new Tile({(nowCatchX) * WEB_LENGTH, (nowCatchY + 2) * WEB_LENGTH}, NUMBER, '/');
    pTiles [nowCatchX] [nowCatchY - 2] = new Tile({(nowCatchX) * WEB_LENGTH, (nowCatchY - 2) * WEB_LENGTH}, NUMBER, '^');
    pTiles [nowCatchX + 1] [nowCatchY] = new Tile({(nowCatchX + 1) * WEB_LENGTH, nowCatchY * WEB_LENGTH}, OPERATOR, '1');

    bool isDraging = false;

    for ( ; ; delay_fps (FPS)) {
    	int x, y;
    	
	    mousepos (&x, &y);

        if (pTiles [nowCatchX] [nowCatchY] != nullptr) {
            if (MOUSE_LEFT_DOWN) {
                pTiles [nowCatchX] [nowCatchY] -> Move ({x, y}, Tick (30));
                isDraging = true;
            }
        }

        if (isDraging == true && !MOUSE_LEFT_DOWN && pTiles [nowCatchX] [nowCatchY] != nullptr) {
            int nextX, nextY;
            nextX = DoWeb ({x, y}). x / WEB_LENGTH;
            nextY = DoWeb ({x, y}). y / WEB_LENGTH;
            if (nextX == nowCatchX && nextY == nowCatchY) // 错位防止拖回错误
                nextX ++;

            if (pTiles [nextX] [nextY] != nullptr) {
                CreateDeath (pTiles [nextX] [nextY] -> tileChar, pTiles [nextX] [nextY] -> pos);
             }
            pTiles [nextX] [nextY] = pTiles [nowCatchX] [nowCatchY];
            pTiles [nowCatchX] [nowCatchY] = nullptr;
            nowCatchX = nextX;
            nowCatchY = nextY;
            isDraging = false;
            pTiles [nowCatchX] [nowCatchY] -> Move ({nextX * WEB_LENGTH, nextY * WEB_LENGTH}, Tick (15));
        }

        if (!MOUSE_LEFT_DOWN) {
            nowCatchX = DoWeb ({x, y}). x / WEB_LENGTH;
            nowCatchY = DoWeb ({x, y}). y / WEB_LENGTH;
        }

        Refresh ();
        
        Update ();

        if (KEY_DOWN('W') || KEY_DOWN('w')) {
            ShowWeb ();
        }

        if (kbmsg ()) {
            key_msg msg = getkey ();

            if ((msg. msg == key_msg_up) && (msg. key == key_E)) {
                int nextX, nextY;
                nextX = DoWeb ({x, y}). x / WEB_LENGTH;
                nextY = DoWeb ({x, y}). y / WEB_LENGTH;
                
                if (pTiles [nextX] [nextY] != nullptr) {
                    CreateDeath (pTiles [nextX] [nextY] -> tileChar, pTiles [nextX] [nextY] -> pos);
                    delete pTiles [nextX] [nextY];
                }

                pTiles [nextX] [nextY] = new Tile ({nextX * WEB_LENGTH, 0}, EQUAL, '=');

                pTiles [nextX] [nextY] -> Move ({DoWeb ({x, y}). x, DoWeb ({x, y}). y}, Tick (30));
            }
        }
    }
    return 0;
}
