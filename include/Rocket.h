#ifndef ROCKET_H
#define ROCKET_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


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
        float deg2rad(int deg);
        sf::Vector2f get_position();
        void update_velocity(float time);
        sf::Sprite get_sprite();
        void move_sprite();
        void check_border();
        void print_status();
        sf::Vector2f get_accel();
        sf::Vector2f get_speed(float time);
        sf::Vector2f get_move(float time);
        void animation(int a);
        void kaboom();

    private:
        int m_mass;         // Kg
        float m_angle;        // degree
        float m_velocity;     // M per second
        sf::Vector2f m_accel ;
        sf::Vector2f m_speed ;
        sf::Vector2f m_move ;
        int m_thrust;       // Newton
        float m_rot_speed;  // degree per second
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::SoundBuffer m_buffer;
        sf::Sound m_sound;
        bool m_cross_border;
};

#endif // ROCKET_H
