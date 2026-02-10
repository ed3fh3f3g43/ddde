#include "../include/Ball.h"
#include <cmath>

Ball::Ball(float startX, float startY, float startZ) 
    : x(startX), y(startY), z(startZ), 
      velocityX(0.0f), velocityY(0.0f), velocityZ(0.0f),
      radius(0.5f), gravity(-9.8f), isMoving(false) {
}

void Ball::update(float deltaTime) {
    // Apply gravity if ball is above ground level
    if (y > 0.0f) {
        velocityY += gravity * deltaTime;
    } else {
        // If ball hits ground, bounce slightly and slow down
        if (velocityY < 0.0f) {
            velocityY = -velocityY * 0.6f;  // Bounce with damping
            y = 0.0f;  // Keep ball above ground
        }
    }
    
    // Update position based on velocity
    x += velocityX * deltaTime;
    y += velocityY * deltaTime;
    z += velocityZ * deltaTime;
    
    // Apply friction to slow down the ball gradually
    velocityX *= 0.98f;
    velocityZ *= 0.98f;
    
    // Check if ball is still moving significantly
    float speed = sqrt(velocityX * velocityX + velocityY * velocityY + velocityZ * velocityZ);
    isMoving = speed > 0.01f;
    
    // If ball goes underground, bring it back to surface
    if (y < 0.0f) {
        y = 0.0f;
    }
}

void Ball::kick(float forceX, float forceY, float forceZ) {
    velocityX += forceX;
    velocityY += forceY;
    velocityZ += forceZ;
    isMoving = true;
    
    // Limit maximum velocity to prevent extreme speeds
    float maxVelocity = 20.0f;
    float currentSpeed = sqrt(velocityX * velocityX + velocityY * velocityY + velocityZ * velocityZ);
    
    if (currentSpeed > maxVelocity) {
        float scale = maxVelocity / currentSpeed;
        velocityX *= scale;
        velocityY *= scale;
        velocityZ *= scale;
    }
}

void Ball::reset() {
    x = 0.0f;
    y = 0.5f;  // Slightly above ground
    z = 0.0f;
    velocityX = 0.0f;
    velocityY = 0.0f;
    velocityZ = 0.0f;
    isMoving = false;
}

void Ball::setPosition(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

void Ball::setVelocity(float velX, float velY, float velZ) {
    velocityX = velX;
    velocityY = velY;
    velocityZ = velZ;
    isMoving = (velX != 0.0f || velY != 0.0f || velZ != 0.0f);
}