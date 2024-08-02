#ifndef F_SETUPDATE

#define F_SETUPDATE

#include "configure.h"

void SetUpdate () {
    AddUpdateFunction (UpdateDeath);
    AddUpdateFunction (UpdateSpawn);
    AddUpdateFunction (UpdateGameTick);
    AddUpdateFunction (UpdateTile);
}

#endif