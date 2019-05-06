#include "Sprite.h"

// Constructors
Sprite::Sprite(const int width, const int height) :
    width(width), height(height) {
        Sprite(width, height, NULL);
    }

Sprite::Sprite(const int width, const int height,
    const int x, const int y) : width(width), height(height) {
        Sprite(width, height, x, y, NULL);
    }

Sprite::Sprite(const int width, const int height, const char* filePath) :
    width(width), height(height) {
        Sprite(width, height, 0, 0, filePath);
    }

Sprite::Sprite(const int width, const int height, const int x,
    const int y, const char* filePath) : width(width), height(height) {
        static int idCounter = 0;
        id = idCounter++;
        loadImage(filePath);
        xPos = x;
        yPos = y;
        moveable = false;
    }

// Destructor
Sprite::~Sprite() {
    }

// Return unique id
const int Sprite::getId() const {
    return id;
}

// Returns if the sprite is moveable
const bool Sprite::isMoveable() const {
    return moveable;
}

/**
 * Load an image
 * @param filePath file location
 */
bool Sprite::loadImage(const char* filePath) {
    // load image 
    if (image = SDL_LoadBMP(filePath)) {
        return true;
    }

    // output error if image can't be loaded
    else {
        std::cerr << "Unable to load image " <<
            SDL_GetError() << std::endl;
        image = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
        return false;
    }
}

const SDL_Rect& Sprite::getRect() const { return destRect; }

// Draw sprite to surface
void Sprite::draw(SDL_Surface *destination) {
    dest = destination;
    // Draw Sprite
   // SDL_FillRect(image, NULL, red);
    SDL_BlitSurface(image, NULL, destination, &destRect);
}

// Update variables
void Sprite::update(SDL_Event &event) {
    destRect.x = xPos;
    destRect.y = yPos;
}