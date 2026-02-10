#include "../include/Stadium.h"

Stadium::Stadium(const std::string& modelFilePath) 
    : modelPath(modelFilePath), width(100.0f), length(60.0f), 
      goalWidth(10.0f), goalDepth(2.0f) {
}

void Stadium::render() {
    // Placeholder for rendering implementation
    // In a real implementation, this would load and draw the stadium model
}

void Stadium::setupCollisions() {
    // Setup boundary collision system
    // This would define the playable area boundaries in a real implementation
}

bool Stadium::isWithinBounds(float x, float z) const {
    float halfWidth = width / 2.0f;
    float halfLength = length / 2.0f;
    
    return (x >= -halfWidth && x <= halfWidth && 
            z >= -halfLength && z <= halfLength);
}

bool Stadium::isGoalArea(float x, float z) const {
    float halfWidth = width / 2.0f;
    float halfGoalWidth = goalWidth / 2.0f;
    
    // Check if position is in either goal area (at both ends of field)
    bool inPositiveGoal = (z >= length/2.0f) && 
                          (z <= length/2.0f + goalDepth) &&
                          (x >= -halfGoalWidth && x <= halfGoalWidth);
                          
    bool inNegativeGoal = (z <= -length/2.0f) && 
                          (z >= -length/2.0f - goalDepth) &&
                          (x >= -halfGoalWidth && x <= halfGoalWidth);
    
    return inPositiveGoal || inNegativeGoal;
}