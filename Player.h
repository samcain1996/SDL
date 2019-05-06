#pragma once
#include "Sprite.h"

class Player : public Sprite {
    private:
    enum Direction {up, down, left, right}; // enum to store directions
    SDL_Rect src; // source rectangle for animating sprite
    int speed = 4; // movement speed 
    bool canMove(Direction dir) const; // check to see if movement is allowed

    public:
    // Constructors
    Player(const int width, const int height, const char* fileName);
    Player(const int width, const int height, const int x,
        const int y, const char* filename); 
    ~Player();
    void update(SDL_Event &event) override;
    void draw(SDL_Surface *destination) override;
};