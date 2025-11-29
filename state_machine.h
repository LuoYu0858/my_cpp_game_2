//
// Created by LuoYu on 2025/11/29.
//

#ifndef HOLLOWSAMURAI_STATE_MACHINE_H
#define HOLLOWSAMURAI_STATE_MACHINE_H

#include "state_node.h"

#include <string>
#include <graphics.h>
#include <unordered_map>

class StateMachine {
public:
    StateMachine();
    ~StateMachine();

    void on_update(float delta);

    void set_entry(const std::string& id);
    void switch_to(const std::string& id);
    void register_state(const std::string& id, StateNode* state_node);

private:
    bool need_init = true;                                  // 是否曾经被初始化
    StateNode* current_state = nullptr;                     // 当前激活的状态节点
    std::unordered_map<std::string, StateNode*> state_pool; // 节点状态池
};

#endif //HOLLOWSAMURAI_STATE_MACHINE_H