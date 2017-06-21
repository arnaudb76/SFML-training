#include "Rocket.h"
#include<math.h>
#include<iostream>

Rocket::Rocket()
{
    m_angle = 0;
    m_velocity =0;
    m_mass = 100;
    m_thrust = 0;
    m_rot_speed =0;

    m_texture.loadFromFile("rocket4.png");
    m_sprite.setTexture(m_texture);

    m_buffer.loadFromFile("Recording.ogg");
    m_sound.setBuffer(m_buffer);
    m_sound.setPitch(1.0);

    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2,m_sprite.getLocalBounds().height/2);
    m_sprite.setPosition(400,300); // todo: a parametre en fonction de la taille de la fenetre.
    m_cross_border = false;
}

Rocket::~Rocket()
{
    //dtor
}

sf::Vector2f Rocket::get_accel(){
    m_accel.x= (m_thrust/m_mass*sin(deg2rad(m_angle)) ) ;
    m_accel.y= (-m_thrust/m_mass*cos(deg2rad(m_angle))) + 20;
    return m_accel;
}

void Rocket::animation(int a){
    if (a==1) {
            m_texture.loadFromFile("rocket4.png");
            if (m_sound.getStatus()!=2){
                    m_sound.play();}
             }

    else {m_texture.loadFromFile("rocket_off.png"); m_sound.stop();}
}

float Rocket::get_velocity(){
    m_velocity = sqrt(m_speed.x*m_speed.x+m_speed.y*m_speed.y);
    return m_velocity;
}

void Rocket::set_angle(int angle){
    m_angle = angle%360;
}

float Rocket::get_angle(){
    return m_angle;
}


sf::Vector2f Rocket::get_speed(float time){
    m_speed.x = m_speed.x + get_accel().x * time;
    m_speed.y = m_speed.y + get_accel().y * time;
    return m_speed;
}

float Rocket::deg2rad(int deg){
    return deg*3.1415/180;
}

void Rocket::update_velocity(float time){
    get_speed(time);
    m_angle = m_angle + m_rot_speed*time;
    get_move(time);
}

sf::Vector2f Rocket::get_move(float time){
    m_move.x=m_speed.x * time;
    m_move.y=m_speed.y * time;
    return m_move;
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


sf::Sprite Rocket::get_sprite(){
    return m_sprite;
}

void Rocket::move_sprite(){
    m_sprite.move(m_move.x,m_move.y);
    m_sprite.setRotation(m_angle);
    check_border();
}

void Rocket::check_border(){ // todo parameteren fonction de la taille de la fenetre
    sf::Vector2f position = m_sprite.getPosition();
    m_cross_border = false;
    if (position.x<0) {m_sprite.setPosition(1920,position.y);m_velocity=0; m_cross_border = true;}
    if (position.x>1920) {m_sprite.setPosition(0,position.y);m_velocity=0;m_cross_border = true;}
    if (position.y<0) {m_sprite.setPosition(position.x,1);m_velocity=0;m_cross_border = true;}
    if (position.y>800) {m_sprite.setPosition(position.x,799);m_velocity=0;m_cross_border = true;}
}

sf::Vector2f Rocket::get_position(){
    return m_sprite.getPosition();
}

void Rocket::print_status(){
            std::cout << "Speed: " << get_velocity()<< std::endl;
            std::cout << "Pos x: " << get_position().x << std::endl;
            std::cout << "Pos y: " << get_position().y << std::endl;
        }

void Rocket::kaboom(){
     m_texture.loadFromFile("boom.png");
     m_sprite.setTexture(m_texture);
     m_buffer.loadFromFile("boom_sound.ogg");
     m_sound.setBuffer(m_buffer);
     m_sound.play();
     while (m_sound.getStatus()!=0){
     }
     m_buffer.loadFromFile("Recording.ogg");
     m_speed.x=0;
     m_speed.y=0;
     m_sprite.setPosition(400,300);
}
