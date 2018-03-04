#include <SFML/Graphics.hpp> //FOR EVERY GRAPHIC FUNCTION
#include <string>
#include "include/Player.h"
#include "include/Enemy.h"
#include "include/resources.h"

using namespace std;
using namespace sf;

//TODO: SET THAT THE GAME OVER TEXT KEEP IN THE WINDOWN UNTIL THE PLAYER CLICKS A KEY

int main()
{
    srand(time(0));

    //SET THE ANTIALIASING LEVEL
    ContextSettings win_settings;
    win_settings.antialiasingLevel = 8;

    //WINDOW OBJECT
    RenderWindow window(VideoMode(WIN_SIZE, WIN_SIZE), "Squares", Style::Close, win_settings);
    window.setFramerateLimit(60);

    //FONTS
    Font arial_bold_font;
    arial_bold_font.loadFromFile("fonts/arialbd.ttf");
    Font arial_font;
    arial_font.loadFromFile("fonts/arial.ttf");

    //GAME OVER TEXT
    Text game_over_text("Game Over", arial_bold_font, 65);
    game_over_text.setColor(Color::Red);
    game_over_text.setPosition(WIN_SIZE/2-game_over_text.getGlobalBounds().width/2, WIN_SIZE/2-game_over_text.getGlobalBounds().height); //set at center (pls sfml developers create a fucking member variable obj.center -.-)

    //POINTS SYSTEM
    int points = 0;

    Player player;
    bool playerTouchedEnemy = false;

    vector<Enemy> enemies;

    //CLOCK FOR ACTION TO DO EVERY SECOND
    Clock every_sec_clock;

    while(window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
            if(e.type == Event::Closed)
                window.close();

        if(!playerTouchedEnemy)
        {
            //EVERY SECCOND
            if((int)every_sec_clock.getElapsedTime().asSeconds() == 1)
            {
                //ADD AN ENEMY
                enemies.push_back(Enemy());

                //ADD POINTS
                points += PPS;

                every_sec_clock.restart();
            }

            //UPDATE ALL
            player.update();
            for(unsigned i = 0; i < enemies.size(); i++)
            {
                enemies[i].update();

                //CHECK IF THE PLAYER HAS TOUCHING AN ENEMY
                if(player.isTouchingSquare(enemies[i]))
                    playerTouchedEnemy = true;
            }
        }

        window.clear();

        //DRAW ALL
        window.draw(Text("Points: " + to_string(points), arial_font, 20));
        player.draw(window);
        for(unsigned i = 0; i < enemies.size(); i++)
            enemies[i].draw(window);

        //IF PLAYER LOSES
        if(playerTouchedEnemy)
        {
            window.draw(game_over_text);
        }

        window.display();
    }
}
