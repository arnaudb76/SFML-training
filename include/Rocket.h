#ifndef ROCKET_H
#define ROCKET_H
#include<SFML/Graphics.hpp>


class Rocket
{
    public:
        Rocket();
        ~Rocket();
        void set_angle(int angle);
        void set_velocity(float v);
        void set_mass(int m);
        void add_rot_speed(float w);
        void set_thrust(int T);
        float get_velocity();
        float get_rot_speed();
        float get_angle();
        float get_dvx();
        float get_dvy();
        float deg2rad(int deg);
        void update_velocity(float time);
        bool is_updated();
        void reset_update_flag();
        void set_update_flag();
        sf::Sprite get_sprite();
        void move_sprite();
        void check_border();


    private:
        int m_mass;         // Kg
        float m_angle;        // degree
        float m_velocity;     // M per second
        int m_thrust;       // Newton
        float m_rot_speed;  // degree per second
        bool update_flag;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};

#endif // ROCKET_H
