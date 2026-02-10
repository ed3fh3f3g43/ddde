#ifndef BALL_H
#define BALL_H

class Ball {
private:
    float x, y, z;      // Position coordinates
    float velocityX, velocityY, velocityZ;  // Velocity components
    float radius;       // Ball radius
    float gravity;      // Gravity effect
    bool isMoving;      // Whether the ball is moving

public:
    Ball(float startX = 0.0f, float startY = 0.0f, float startZ = 0.0f);
    
    void update(float deltaTime);
    void kick(float forceX, float forceY, float forceZ);  // Apply force to ball
    void reset();  // Reset ball position
    
    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getRadius() const { return radius; }
    bool getIsMoving() const { return isMoving; }
    
    // Setters
    void setPosition(float newX, float newY, float newZ);
    void setVelocity(float velX, float velY, float velZ);
};

#endif // BALL_H