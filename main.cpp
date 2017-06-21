#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"Rocket.h"
#include"Landing_site.h"

bool check_collision(Rocket r, Landing_site s);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Rocket Lander");

    sf::Texture background;
    background.loadFromFile("moon.jpg");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);

    Rocket my_lander;
    Landing_site moon;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Left))) {my_lander.add_rot_speed(-1.0);}
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Right))) {my_lander.add_rot_speed(1.0);}
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) {my_lander.set_thrust(10000); my_lander.animation(1);}
            else {my_lander.set_thrust(0);my_lander.animation(2);}

        my_lander.update_velocity(clock.restart().asSeconds());
        my_lander.move_sprite();

        window.clear();
        window.draw(background_sprite);
        window.draw(my_lander.get_sprite());
        window.draw(moon.get_landing_zone());

        if (check_collision(my_lander, moon)) {
                my_lander.kaboom();
                }

        window.display();
    }
return 0;

}



bool check_collision(Rocket r, Landing_site s){
        return r.get_sprite().getGlobalBounds().intersects(s.get_landing_zone().getGlobalBounds());
}
