#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/Player.h"
#include "../include/Ball.h"
#include "../include/Stadium.h"
#include "../include/CameraSystem.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

// Game state
Player* player = nullptr;
Ball* ball = nullptr;
Stadium* stadium = nullptr;
CameraSystem* camera = nullptr;

bool keys[256] = {false};  // Track key states

// Game initialization
void initGame() {
    player = new Player(0.0f, 0.0f, 0.0f);
    ball = new Ball(5.0f, 0.0f, 0.0f);
    stadium = new Stadium("assets/models/stadium.obj");
    camera = new CameraSystem();
    
    printf("Game initialized!\n");
}

// Handle keyboard input
void handleInput() {
    if (keys['W'] || keys['w']) {
        player->moveForward();
    }
    if (keys['S'] || keys['s']) {
        player->moveBackward();
    }
    if (keys['A'] || keys['a']) {
        player->moveLeft();
    }
    if (keys['D'] || keys['d']) {
        player->moveRight();
    }
    if (keys['Q'] || keys['q']) {
        player->rotateLeft();
    }
    if (keys['E'] || keys['e']) {
        player->rotateRight();
    }
}

// Game update function
void update(float deltaTime) {
    handleInput();
    player->update(deltaTime);
    ball->update(deltaTime);
    camera->followPlayer(player->getX(), player->getY(), player->getZ());
    
    // Simple collision between player and ball
    float distX = player->getX() - ball->getX();
    float distY = player->getY() - ball->getY();
    float distZ = player->getZ() - ball->getZ();
    float distance = sqrtf(distX * distX + distY * distY + distZ * distZ);
    
    if (distance < 1.5f) {  // If player is close to ball
        ball->kick(distX * 0.5f, 0.0f, distZ * 0.5f);  // Kick the ball
    }
}

// Main render function (placeholder for now)
void render() {
    // In a real implementation, this would render the 3D scene
    // For now we'll just print positions
    printf("Player: (%.2f, %.2f, %.2f), Ball: (%.2f, %.2f, %.2f)\r", 
           player->getX(), player->getY(), player->getZ(),
           ball->getX(), ball->getY(), ball->getZ());
}

// Main game loop
void gameLoop() {
    static float lastTime = 0.0f;
    float currentTime = emscripten_performance_now() / 1000.0f;  // Time in seconds
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    
    update(deltaTime);
    render();
}

// Keyboard event handler
EM_BOOL keyCallback(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData) {
    if (eventType == EMSCRIPTEN_EVENT_KEYDOWN) {
        keys[keyEvent->keyCode] = true;
    } else if (eventType == EMSCRIPTEN_EVENT_KEYUP) {
        keys[keyEvent->keyCode] = false;
    }
    
    // Handle escape key to prevent browser shortcuts
    if (keyEvent->keyCode == 27) {
        emscripten_run_script("event.preventDefault();");
        return true;
    }
    
    return true;
}

int main() {
    printf("Starting BallonTest1 Game...\n");
    
    initGame();
    
    // Set up keyboard callbacks
    emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, true, keyCallback);
    emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, true, keyCallback);
    
    // Run the game loop continuously
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(gameLoop, 0, 1);  // 0 FPS means run as fast as possible
#else
    // For native compilation, implement a simple loop
    while (1) {
        gameLoop();
        emscripten_sleep(16);  // Sleep for ~60 FPS
    }
#endif
    
    // Cleanup
    delete player;
    delete ball;
    delete stadium;
    delete camera;
    
    return 0;
}