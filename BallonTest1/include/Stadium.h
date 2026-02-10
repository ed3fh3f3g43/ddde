#ifndef STADIUM_H
#define STADIUM_H

#include <string>

class Stadium {
private:
    std::string modelPath;    // Path to stadium model
    float width, length;      // Dimensions of the stadium
    float goalWidth, goalDepth;  // Goal dimensions

public:
    Stadium(const std::string& modelFilePath);
    
    void render();  // Render the stadium
    void setupCollisions();  // Setup collision boundaries
    
    // Getters
    float getWidth() const { return width; }
    float getLength() const { return length; }
    float getGoalWidth() const { return goalWidth; }
    float getGoalDepth() const { return goalDepth; }
    
    // Check if position is within stadium bounds
    bool isWithinBounds(float x, float z) const;
    bool isGoalArea(float x, float z) const;  // Check if in goal area
};

#endif // STADIUM_H