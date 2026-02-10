#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    float x, y, z;          // Position coordinates
    float rotation;         // Player rotation angle
    float speed;           // Movement speed
    std::string modelPath; // Path to player model

public:
    Player(float startX = 0.0f, float startY = 0.0f, float startZ = 0.0f);
    
    void update(float deltaTime);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void rotateLeft();
    void rotateRight();
    
    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getRotation() const { return rotation; }
    
    // Setters
    void setPosition(float newX, float newY, float newZ);
    void setSpeed(float newSpeed);
};

#endif // PLAYER_H