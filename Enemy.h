#ifndef ENEMY_H
#define ENEMY_H

#include "Square.h"

class Enemy : public Square
{
    public:
        Enemy();

        void update();
};

#endif // ENEMY_H
