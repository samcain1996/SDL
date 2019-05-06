#pragma once
#include "SDL.h"
#include <iostream>
#include <algorithm>
#include <iterator>

class Sprite {
    private:
    int id; // unique id to keep track of sprite

    protected:
    const int width, height; // width and height
    bool moveable; // Can the sprite move or not
    int xPos = 100, yPos = 100; // Position

    SDL_Surface *image = NULL; // Texture
    SDL_Surface *dest = NULL; // Sprite destination
    SDL_Rect destRect; // Sprite bounds

    public:
    // Constructors
    Sprite(const int width, const int height);
    Sprite(const int width, const int height, const int x, const int y);
    Sprite(const int width, const int height, const char* filePath);
    Sprite(const int width, const int height, const int x, 
            const int y, const char* filePath);
    ~Sprite();

    const int getId() const; // Return unique id
    const bool isMoveable() const; // Returns if the sprite is moveable
    virtual const SDL_Rect& getRect() const; // Returns bounds
    virtual void draw(SDL_Surface *destination); // draw to surface
    virtual void update(SDL_Event &event); // update variables
    virtual bool loadImage(const char* filePath); // load image
};