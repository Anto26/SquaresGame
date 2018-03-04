#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square
{
    protected:
        sf::CircleShape m_square;

    public:
        Square();

        sf::CircleShape getShape() const;

        void draw(sf::RenderWindow &window);
};

#endif // SQUARE_H
