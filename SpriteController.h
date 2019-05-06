#pragma once
#include "Sprite.h"
#include "Player.h"
#include <vector>
#include <memory>

class SpriteController {
    using SpritePointer = std::shared_ptr<Sprite>;
    private:
    std::vector<SpritePointer> sprites;
    public:
    // Constructors
    SpriteController();
    ~SpriteController();

    // Create and delete sprites
    bool createSprite(const int width, const int height, 
        const int x, const int y, const char* filePath);
    bool createPlayer(const int width, const int height, 
        const int x, const int y, const char* filePath);
    bool deleteSprite(const int id);

    std::vector<SpritePointer>& getSprites();
    void update(SDL_Event &event);
    void draw(SDL_Surface *destination);
    void checkCollisions();
};