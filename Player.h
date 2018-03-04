#ifndef PLAYER_H
#define PLAYER_H

#include "Square.h"
#include "Enemy.h"

class Player : public Square
{
    public:
        Player();

        void update();

        bool isTouchingSquare(const Square s) const;
};

#endif // PLAYER_H
