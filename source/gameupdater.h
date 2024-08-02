#ifndef F_GAMEUPDATER

#define F_GAMEUPDATER

void (*updateFunctions [255]) (); // 创建一个回调函数数组，里面是其他地方用于更新的函数

int countUpdateFunctions = 0;     // 函数更新的数量

void Update () {
    for (int i = 0 ; i < countUpdateFunctions ; i ++) {
        (*updateFunctions [i]) ();   // 调用回调函数
    }
}

void AddUpdateFunction (void (*func) ()) { // 添加一个更新函数
    updateFunctions [countUpdateFunctions ++] = func;
}

#endif