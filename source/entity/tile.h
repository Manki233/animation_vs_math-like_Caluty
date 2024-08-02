#ifndef F_TILE 

#define F_TILE

#include "..\configure.h"

enum {
    NUMBER = -2,
    EQUAL,
    AIR,
    OPERATOR,
    SPAWNING
};

enum {
    STATIC,
    LINEAR,
    BETTER
};

class Tile {
    public:
        Tile (Vec2 aPos, int aTileType, int aTileChar) {
            pos = aPos;
            tileType = aTileType;
            tileChar = aTileChar;
        }

        Vec2 pos;
        Vec2 targetPos;

        Tick moveTime;
        
        int moving = STATIC;

        int tileType = AIR;
        int tileChar;

        void Update ();

        void Move (Vec2 argPos);
        void Move (Vec2 argPos, Tick time);
};

Tile *pTiles [WINDOW_LENGTH_X / WEB_LENGTH] [WINDOW_LENGTH_Y / WEB_LENGTH];

void UpdateTile () {
    for (int i = 0 ; i < WINDOW_LENGTH_X / WEB_LENGTH ; i ++) {
    	for (int j = 0 ; j < WINDOW_LENGTH_Y / WEB_LENGTH ; j ++) {
    		if (pTiles [i] [j] == nullptr)
    			continue;
        	pTiles [i] [j] -> Update ();
		}
    }
}

#endif
