//
// Created by LuoYu on 2025/12/2.
//

#include "enemy.h"
#include "player.h"
#include "character_manager.h"
#include "bullet_time_manager.h"

CharacterManager* CharacterManager::manager = nullptr;

CharacterManager* CharacterManager::instance() {
    if (not manager) manager = new CharacterManager();
    return manager;
}

void CharacterManager::on_input(const ExMessage& msg) const {
    player->on_input(msg);
}

void CharacterManager::on_update(float delta) const {
    enemy->on_update(delta);
    player->on_update(delta);
}

void CharacterManager::on_render() const {
    enemy->on_render();
    BulletTimeManager::instance()->post_process();
    player->on_render();
}

CharacterManager::CharacterManager() {
    enemy = new Enemy();
    player = new Player();
}

CharacterManager::~CharacterManager() {
    delete enemy;
    delete player;
}