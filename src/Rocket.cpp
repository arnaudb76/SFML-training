#include "Rocket.h"
#include<math.h>

Rocket::Rocket()
{
    m_angle = 0;
    m_velocity =10;
    m_mass = 100;
    m_thrust = 0;
    m_rot_speed =0;
    m_texture.loadFromFile("rocket.jpg");
    m_sprite.setTexture(m_texture);
}

Rocket::~Rocket()
{
    //dtor
}

float Rocket::get_velocity(){
    return m_velocity;
}

void Rocket::set_angle(int angle){
    m_angle = angle%360;
}

float Rocket::get_angle(){
    return m_angle;
}

float Rocket::get_dvx(){
    return (m_velocity*sin(deg2rad(m_angle )));
}

float Rocket::get_dvy(){
    return (-m_velocity*cos(deg2rad(m_angle )));
}


float Rocket::deg2rad(int deg){
    return deg*3.1415/180;
}

void Rocket::update_velocity(float time){
    float dax,day;
    dax = (m_thrust/m_mass*sin(deg2rad(m_angle)) );
    day = (-m_thrust/m_mass*cos(deg2rad(m_angle))) + 9 ; // Ici 9 est la gravite. TODO class planete avec gravite
    float dvx, dvy;
    dvx = dax * time + get_dvx();
    dvy = day * time + get_dvy();
    m_velocity = sqrt(dvx*dvx+dvy*dvy);
    m_angle = m_rot_speed*time;
}

void Rocket::add_rot_speed(float w){
    m_rot_speed = m_rot_speed + w;
}

float Rocket::get_rot_speed(){
    return m_rot_speed;
}

void Rocket::set_thrust(int T){
    m_thrust = T;     // ici penser a parametrer le max thrust.
}

bool Rocket::is_updated(){return update_flag;}
void Rocket::reset_update_flag(){update_flag = false;}
void Rocket::set_update_flag(){update_flag = true;}

sf::Sprite Rocket::get_sprite(){
    return m_sprite;
}



