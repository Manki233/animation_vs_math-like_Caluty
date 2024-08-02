#ifndef F_ENGINE

#define F_ENGINE

#include "configure.h"

Vec2 DoWeb (Vec2 shouldPos) {
    return {
        (int) floor (double (shouldPos. x) / WEB_LENGTH) * WEB_LENGTH,
        (int) floor (double (shouldPos. y) / WEB_LENGTH) * WEB_LENGTH
    };
}

void Refresh () {
	cleardevice ();
	
    for (int i = 0 ; i < WINDOW_LENGTH_X / WEB_LENGTH ; i ++) {
    	for (int j = 0 ; j < WINDOW_LENGTH_Y / WEB_LENGTH ; j ++) {
	        if (pTiles [i] [j] == nullptr || pTiles [i] [j] -> tileType == SPAWNING)
	            continue;
	
	        Tile iTile = *pTiles [i] [j];
	
	        setfont(WEB_LENGTH, 0, "Fira Code");

            settextjustify(CENTER_TEXT, CENTER_TEXT);

            setcolor (WHITE);

            setbkmode(TRANSPARENT);
	
	        xyprintf(iTile. pos. x + WEB_LENGTH / 2, iTile. pos. y + WEB_LENGTH / 2, "%c", iTile. tileChar);
		}
	}
}

void ShowWeb () {
    setcolor (WHITE);

    setbkmode(TRANSPARENT);

    for (int i = 0 ; i <= WINDOW_LENGTH_X ; i += WEB_LENGTH) {
        line (i, 0, i, WINDOW_LENGTH_Y);
    }

    for (int i = 0 ; i <= WINDOW_LENGTH_Y ; i += WEB_LENGTH) {
        line (0, i, WINDOW_LENGTH_X, i);
    }
}

#endif
