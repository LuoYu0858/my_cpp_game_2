//
// Created by LuoYu on 2025/11/29.
//

#ifndef HOLLOWSAMURAI_STATE_NODE_H
#define HOLLOWSAMURAI_STATE_NODE_H

class StateNode {
public:
    StateNode() = default;
    ~StateNode() = default;

    virtual void on_enter() {}
    virtual void on_update(float delta) {}
    virtual void on_exit() {}
};

#endif //HOLLOWSAMURAI_STATE_NODE_H