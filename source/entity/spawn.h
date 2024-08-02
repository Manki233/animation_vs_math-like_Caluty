#ifndef F_SPAWN

#define F_SPAWN

#include "..\configure.h"

class Spawn { // 只能用 new 分配内存！
    public:
        char SpawnChar;

        Vec2 pos;

        Tile *spawnTile;

        Tick lifeTime;

        bool killed = false;

        Spawn (Vec2 p, Tile *t) {
            spawnTile = t;
            SpawnChar = t -> tileChar;
            pos = p;
            lifeTime = 0;
        }

        void Update () {
            Draw ();

            if (lifeTime.tick < 31) {
                lifeTime.tick ++;
            } else {
                killed = true;

                Vec2 m_Index = DoWeb (pos) / WEB_LENGTH;

                spawnTile -> tileType = STATIC;

                pTiles [m_Index. x] [m_Index. y] = spawnTile;
            }
        }
    private:
        void Draw () {
            char buf [3];

            sprintf (buf, "%c", SpawnChar);

            setbkmode(TRANSPARENT);

            setcolor (EGEGRAY(255 / 30 * lifeTime.tick));

	        xyprintf (pos.x + WEB_LENGTH / 2, pos.y + WEB_LENGTH / 2, "%c", SpawnChar);
        }
};

Spawn *pSpawn [WEB_COUNT_X * WEB_COUNT_Y];
int pSpawnTop = 0;

void CreateSpawn (Vec2 p, Tile *t) {
    int choose = pSpawnTop;

    for (int i = 0 ; i < pSpawnTop ; i ++) {
        if (pSpawn [i] == nullptr) {
            choose = i;
            break;
        }
    }

    if (choose == pSpawnTop)
        pSpawnTop ++;

    pSpawn [choose] = new Spawn (p, t);
}

void UpdateSpawn () {
    for (int i = 0 ; i < pSpawnTop ; i ++) {
        if (pSpawn [i] == nullptr)
            continue;
    	
        if (pSpawn [i] -> killed) {
            pSpawn [i] = nullptr;

            continue;
        }

        pSpawn [i] -> Update ();
    }
}

#endif
