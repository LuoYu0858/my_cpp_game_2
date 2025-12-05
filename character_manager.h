//
// Created by LuoYu on 2025/12/2.
//

#ifndef HOLLOWSAMURAI_CHARACTER_MANAGER_H
#define HOLLOWSAMURAI_CHARACTER_MANAGER_H

#include "character.h"

class CharacterManager {
public:
    static CharacterManager* instance();

    [[nodiscard]] Character* get_enemy() const {
        return enemy;
    }

    [[nodiscard]] Character* get_player() const {
        return player;
    }

    void on_input(const ExMessage& msg) const;
    void on_update(float delta) const;
    void on_render() const;

private:
    CharacterManager();
    ~CharacterManager();

private:
    static CharacterManager* manager;

    Character* enemy = nullptr;
    Character* player = nullptr;
};

#endif //HOLLOWSAMURAI_CHARACTER_MANAGER_H