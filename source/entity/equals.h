#ifndef F_EQUAL

#define F_EQUAL

// 这里面都是操作等号的方法

#include "..\configure.h"
#include "tile.h"
#include "death.h"
#include "spawn.h"

struct Expression {
    string str; 
    vector <int> types;
};

Expression GetStringLeft (Tile *tile) {
    Expression result;

    Vec2 m_Index = tile -> pos / WEB_LENGTH;

    int length = 0;

    while (pTiles [m_Index. x - length - 1] [m_Index. y]) {
        result.str += pTiles [m_Index. x - length - 1] [m_Index. y] -> tileChar;
        result.types. push_back (pTiles [m_Index. x - length - 1] [m_Index. y] -> tileType);

        length ++;
    }

    reverse (result. types. begin (), result. types. end ());
    reverse (result. str. begin (), result. str. end ());

    return result;
}

string GetStringRight (Tile *tile) {
    string result;

    Vec2 m_Index = tile -> pos / WEB_LENGTH;

    int length = 0;

    while (pTiles [m_Index. x + length + 1] [m_Index. y]) {
        result += pTiles [m_Index. x + length + 1] [m_Index. y] -> tileChar;

        length ++;
    }

    return result;
}

Vec2 GetInt (Expression exp, int pos) { // x = 数值，y = 位置
    int result = 0;

    int length = 0;

    while ((size_t) (pos + length) < exp.str.size () && exp.types [pos + length] == NUMBER) {
        result *= 10;
        result += exp.str [pos + length] - '0';

        length ++;
    }

    return {result, pos + length};
}

double Calue (double a, double b, char c) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow (a, b);
    }

    return a * b;
}

double SolveExp (Expression exp) {
    char* str = exp. str. data ();

    tranString (str);

    double result = eval (str);

    return result;
}

void SpawnNumbers (string str, Vec2 tilePos) {
    Vec2 m_Index = tilePos / WEB_LENGTH;

    int end = str. size () - 1;

    for (int i = str. size () - 1 ; i >= 1 ; i --) {
        if (str [i] == '0') {
            end = i;
        } else if (str [i] == '.') {
            end = i;
            break;
        } else {
            break;
        }
    }

    str = str. substr (0, end); // 去零

    for (int i = 0 ; i < str. size () ; i ++) {
        if (pTiles [m_Index. x + i + 1] [m_Index. y] && str [i] == pTiles [m_Index. x + i + 1] [m_Index. y] -> tileChar)
            continue;

        pTiles [m_Index. x + i + 1] [m_Index. y] = nullptr;

        CreateSpawn (tilePos + Vec2 ((i + 1) * WEB_LENGTH, 0), new Tile (tilePos + Vec2 ((i + 1) * WEB_LENGTH, 0), NUMBER, str [i]));
    }

    int i = str. size () + 1;

    while (pTiles [m_Index. x + i] [m_Index. y]) {
        CreateDeath (pTiles [m_Index. x + i] [m_Index. y] -> tileChar, tilePos + Vec2 (i * WEB_LENGTH, 0));
        pTiles [m_Index. x + i] [m_Index. y] = nullptr;
        i ++;
    }
}

void DoEqual (Tile *tile) {
    Expression exp = GetStringLeft (tile);

    double shouldAnswer = atof (GetStringRight (tile). c_str ());
    double answer = SolveExp (exp);
    
    if (answer != shouldAnswer || (answer == 0 && shouldAnswer == 0 && exp. str. size () > 0 && GetStringRight (tile). size () > 0)) {
        SpawnNumbers ((to_string (answer)), tile -> pos);
    }
}

#endif 