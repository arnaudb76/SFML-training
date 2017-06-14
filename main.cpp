#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Rocket.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Rocket Lander");
    Rocket my_lander;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Left))) {my_lander.add_rot_speed(-1.0); my_lander.set_update_flag();}
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Right))) {my_lander.add_rot_speed(1.0);my_lander.set_update_flag();}
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) {my_lander.set_thrust(1000);my_lander.set_update_flag();} else {my_lander.set_thrust(0);}


        if (my_lander.is_updated()){
            std::cout << "Speed: " << my_lander.get_velocity()<< std::endl;
            std::cout << "Rot speed: " << my_lander.get_rot_speed()<< std::endl;
            std::cout << "Angle: " << my_lander.get_angle()<< std::endl;
            my_lander.reset_update_flag();
        }

        my_lander.update_velocity(clock.restart().asSeconds());
        my_lander.move_sprite();

        window.clear();
        window.draw(my_lander.get_sprite());
        window.display();
    }
return 0;
}

