#include "SpriteController.h"
#include <iostream>

using SpritePointer = std::shared_ptr<Sprite>;

SpriteController::SpriteController() {}

SpriteController::~SpriteController() {
    while (sprites.size() > 0) { sprites.pop_back(); }
}

/**
 * Create a controllable player character
 * @param width width of the player sprite
 * @param height height of the player sprite
 */
bool SpriteController::createPlayer(const int width, const int height,
    const int x, const int y, const char* filePath) {
        sprites.push_back(std::make_shared<Player>
            (width, height, x, y, filePath));
}

/**
 * Creates a sprite
 * @param width width of the sprite
 * @param height height of the sprite
 */
bool SpriteController::createSprite(const int width, const int height,
    const int x, const int y, const char* filePath) {
        sprites.push_back(std::make_shared<Sprite>
            (width, height, x, y, filePath));
}

/**
 * Deletes sprite
 * @param id the id of the sprite to be deleted
 */
bool SpriteController::deleteSprite(const int id) {
    for (int i = 0; i < sprites.size(); i++) {
        if(sprites.at(i)->getId() == id) {
            sprites.erase(sprites.begin() + i);
        }
    }
}

void SpriteController::update(SDL_Event &event) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_X]) {
        deleteSprite(1);
    }

    for (auto& sprite : sprites) {
        sprite->update(event);
    }
}

void SpriteController::draw(SDL_Surface *destination) {
    for (auto& sprite : sprites) {
        sprite->draw(destination);
    }
}

void SpriteController::checkCollisions() {
    for (auto& spriteOne : sprites) {
        for (auto& spriteTwo : sprites) {
            if (!spriteOne->isMoveable() || ! spriteTwo->isMoveable())
                continue;
            if (spriteOne->getId() == spriteTwo->getId())
                continue;
            // Check side to side
            SDL_Rect rect1 = spriteOne->getRect();
            SDL_Rect rect2 = spriteTwo->getRect();

            if (rect1.x + rect1.w >= rect2.x) {
                // Collision
            }
            if (rect2.x + rect2.w >= rect1.x) {
                // Collision
            }
        }
    }
}

std::vector<SpritePointer>& SpriteController::getSprites() {
    return sprites;
}