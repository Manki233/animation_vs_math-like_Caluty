#ifndef F_TIME 

#define F_TIME

#define FPS 30

long long g_GameTick = 0;

struct Tick {
    int tick;

    Tick (int argTick) {
        tick = argTick;
    }

    Tick () {
        tick = 0;
    }

    inline double toSec () const {
        return double (tick) / FPS;
    }

    inline int toMs () const {
        return (int) toSec () / 1000;
    }

    Tick operator - (Tick arg) const {
        return tick - arg. tick;
    }
};

void WaitFor (Tick tick) {
    delay_ms (tick. toMs ());
}

void UpdateGameTick () {
    g_GameTick ++;
}

#endif