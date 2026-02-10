#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

class CameraSystem {
private:
    float posX, posY, posZ;      // Camera position
    float targetX, targetY, targetZ;  // Look-at target
    float upX, upY, upZ;         // Up vector
    float fov;                   // Field of view
    float aspectRatio;           // Aspect ratio
    float nearPlane, farPlane;   // Clipping planes

public:
    CameraSystem();
    
    void update();  // Update camera matrices
    void followPlayer(float playerX, float playerY, float playerZ);  // Follow player
    void setPerspective(float newFov, float newAspectRatio, float newNear, float newFar);
    void lookAt(float targetX, float targetY, float targetZ);
    
    // Getters
    float getPosX() const { return posX; }
    float getPosY() const { return posY; }
    float getPosZ() const { return posZ; }
    float getTargetX() const { return targetX; }
    float getTargetY() const { return targetY; }
    float getTargetZ() const { return targetZ; }
};

#endif // CAMERASYSTEM_H