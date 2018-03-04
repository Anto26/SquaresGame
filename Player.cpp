#include "../include/Player.h"
#include "../include/resources.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Player::Player()
{
    m_square.setPosition(WIN_SIZE/2, WIN_SIZE-SQUARE_RADIUS);
}

void Player::update()
{
    //MOVE THE SQUARE IF IT IS VISIBLE INSIDE WINDOW (THEN IF IT IS BETWEEN THE BORDERS)
    if(Keyboard::isKeyPressed(Keyboard::Up) && m_square.getPosition().y > SQUARE_RADIUS)
        m_square.move(0, -PL_VEL);
    else if(Keyboard::isKeyPressed(Keyboard::Down) && m_square.getPosition().y < WIN_SIZE-SQUARE_RADIUS)
        m_square.move(0, PL_VEL);
    else if(Keyboard::isKeyPressed(Keyboard::Left) && m_square.getPosition().x > SQUARE_RADIUS)
        m_square.move(-PL_VEL, 0);
    else if(Keyboard::isKeyPressed(Keyboard::Right) && m_square.getPosition().x < WIN_SIZE-SQUARE_RADIUS)
        m_square.move(PL_VEL, 0);
}

bool Player::isTouchingSquare(const Square s) const
{
    //RETURN TRUE IF THE SQUARE INTERSECTS THE ENEMY SQUARE
    return m_square.getGlobalBounds().intersects(s.getShape().getGlobalBounds());
}
