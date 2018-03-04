#include "../include/Enemy.h"
#include "../include/resources.h"

Enemy::Enemy()
{
    //SET THE SQUARE X POSITION OVER THE TOP BORDER AND IN A RANDOM X POSITION
    m_square.setPosition(rand()%WIN_SIZE-SQUARE_RADIUS, -SQUARE_RADIUS);
}

void Enemy::update()
{
    //IF THE SQUARE ISN'T TOUCH THE BOT BORDER MOVE IT TO THE BORDER
    if(m_square.getPosition().y < WIN_SIZE+SQUARE_RADIUS)
        m_square.move(0, EN_VEL);

    //ELSE RE INITIALIZE THE OBJECT (SO I RETURN TO A RANDOM POSITION)
    else m_square.setPosition(rand()%WIN_SIZE-SQUARE_RADIUS, -SQUARE_RADIUS);
}
