#include "../include/Square.h"
#include "../include/resources.h"

using namespace sf;

Square::Square() : m_square(sf::CircleShape(SQUARE_RADIUS, 4))
{
    //SET A RANDOM SQUARE COLOR
    m_square.setFillColor(Color(rand()%255, rand()%255, rand()%255));

    //SET THAT THE SQUARE ROTATE AROUND ITS CENTER
    m_square.setOrigin(SQUARE_RADIUS, SQUARE_RADIUS);
}

CircleShape Square::getShape() const
{
    return m_square;
}

void Square::draw(RenderWindow &window)
{
    //ROTATE THE SQUARE
    m_square.rotate(5);

    //DRAW THE SQUARE
    window.draw(m_square);
}
