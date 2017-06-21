#ifndef LANDING_SITE_H
#define LANDING_SITE_H
#include<SFML/Graphics.hpp>


class Landing_site
{
    public:
        Landing_site();
        ~Landing_site();
        sf::RectangleShape get_landing_zone();

    private:
        sf::RectangleShape m_landing_zone;
};

#endif // LANDING_SITE_H
