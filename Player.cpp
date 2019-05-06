#include "Player.h"
#include <iostream>

Player::Player(const int width, const int height, const char* fileName) :
    Sprite(width, height, fileName) {
        Player(width, height, 0, 0, fileName);
}

Player::Player(const int width, const int height, const int x,
    const int y, const char* fileName) : Sprite(width, height, x, y, fileName) {
        src.w = width;
        src.h = height;
        src.x = 0;
        src.y = 0;
        moveable = true;
    }

Player::~Player() {}

void Player::draw(SDL_Surface *destination) {
    dest = destination;

    // Draw player
    SDL_BlitSurface(image, &src, destination, &destRect);
   // std::cout << "X: " << sprites.at(sprites.size() - 1).getLocation().x << std::endl;
}

bool Player::canMove(Direction dir) const {
    if (dir == up) { return yPos <= 0 ? false : true; }
    else if (dir == down) { return (yPos + height) >= dest->h ? false : true; }
    else if (dir == left) { return xPos <= 0 ? false : true; }
    else if (dir == right) { (xPos + width) >= dest->w ? false: true; }
    else { return true; }
}

void Player::update(SDL_Event &event) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (event.type == SDL_KEYDOWN && dest != NULL) {

        // Get input and update Sprite
        if (state[SDL_SCANCODE_S] && canMove(down))   { yPos+=speed; src.x == 96 ? src.x = 0 : src.x += 32;}
        if (state[SDL_SCANCODE_W] && canMove(up))     { yPos-=speed; src.x == 96 ? src.x = 0 : src.x += 32;}
        if (state[SDL_SCANCODE_A] && canMove(left))   { xPos-=speed; src.x == 96 ? src.x = 0 : src.x += 32;}
        if (state[SDL_SCANCODE_D] && canMove(right))  { xPos+=speed; src.x == 96 ? src.x = 0 : src.x += 32;}

        // Update location
        destRect.y = yPos;
        destRect.x = xPos;
    }
}
