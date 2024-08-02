#ifndef F_DEATH

#define F_DEATH

#include "..\configure.h"

class Death { // 只能用 new 分配内存！
    public:
        char deathChar;

        Vec2 pos;

        Tick lifeTime;

        bool killed = false;

        Death (char c, Vec2 p) {
            deathChar = c;
            pos = p;
            lifeTime = 15;
        }

        void Update () {
            Draw ();

            if (lifeTime.tick > 0) {
                lifeTime.tick --;
            } else {
                killed = true;
            }
        }
    private:
        void Draw () {
            char buf [3];

            sprintf (buf, "%c", deathChar);

            setfont(WEB_LENGTH - lifeTime.tick + 15, textwidth(buf) - lifeTime.tick + 15, "Fira Code");

            setbkmode(TRANSPARENT);

            setcolor (EGEGRAY(255 / 15 * lifeTime.tick));

	        xyprintf (pos.x + WEB_LENGTH / 2, pos.y + WEB_LENGTH / 2, "%c", deathChar);
        }
};

Death *pDeath [WEB_COUNT_X * WEB_COUNT_Y];
int pDeathTop = 0;

void CreateDeath (char c, Vec2 p) {
    int choose = pDeathTop;

    for (int i = 0 ; i < pDeathTop ; i ++) {
        if (pDeath [i] == nullptr) {
            choose = i;
            break;
        }
    }

    if (choose == pDeathTop)
        pDeathTop ++;

    pDeath [choose] = new Death (c, p);
}

void UpdateDeath () {
    for (int i = 0 ; i < pDeathTop ; i ++) {
        if (pDeath [i] == nullptr)
            continue;
    	
        if (pDeath [i] -> killed)  {  
            // Vec2 m_Index = DoWeb (pDeath [i] -> pos) / WEB_LENGTH;

            // pTiles [m_Index. x] [m_Index. y] = nullptr;

            pDeath [i] = nullptr;
        }

        if (pDeath [i] == nullptr)
            continue;

        pDeath [i] -> Update ();
    }
}

#endif
