#include "Landing_site.h"

Landing_site::Landing_site()
{
    m_landing_zone.setSize(sf::Vector2f(120,40));
    m_landing_zone.setFillColor(sf::Color(120,50,200));
    m_landing_zone.setPosition(sf::Vector2f(400,700));


}

Landing_site::~Landing_site()
{
    //dtor
}

sf::RectangleShape Landing_site::get_landing_zone()
{
    return m_landing_zone;
}
