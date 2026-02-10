#include "../include/Player.h"
#include <cmath>

Player::Player(float startX, float startY, float startZ) 
    : x(startX), y(startY), z(startZ), rotation(0.0f), speed(5.0f) {
}

void Player::update(float deltaTime) {
    // Update any time-based changes here
    // Currently just placeholder
}

void Player::moveForward() {
    x += sin(rotation) * speed * 0.1f;
    z += cos(rotation) * speed * 0.1f;
}

void Player::moveBackward() {
    x -= sin(rotation) * speed * 0.1f;
    z -= cos(rotation) * speed * 0.1f;
}

void Player::moveLeft() {
    x += sin(rotation - M_PI/2) * speed * 0.1f;
    z += cos(rotation - M_PI/2) * speed * 0.1f;
}

void Player::moveRight() {
    x += sin(rotation + M_PI/2) * speed * 0.1f;
    z += cos(rotation + M_PI/2) * speed * 0.1f;
}

void Player::rotateLeft() {
    rotation += 0.1f;
}

void Player::rotateRight() {
    rotation -= 0.1f;
}

void Player::setPosition(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

void Player::setSpeed(float newSpeed) {
    speed = newSpeed;
}