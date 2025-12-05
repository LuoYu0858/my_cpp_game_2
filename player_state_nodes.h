//
// Created by LuoYu on 2025/12/2.
//

#ifndef HOLLOWSAMURAI_PLAYER_STATE_NODES_H
#define HOLLOWSAMURAI_PLAYER_STATE_NODES_H

#include "timer.h"
#include "state_node.h"

class PlayerAttackStates : public StateNode {
public:
    PlayerAttackStates();
    ~PlayerAttackStates() = default;

    void on_enter() override;
    void on_update(float delta) override;
    void on_exit() override;

private:
    static void update_hit_box_position();

private:
    Timer timer;
};

class PlayerDeadState : public StateNode {
public:
    PlayerDeadState();
    ~PlayerDeadState() = default;

    void on_enter() override;
    void on_update(float delta) override;

private:
    Timer timer;
};

class PlayerFallState : public StateNode {
public:
    PlayerFallState() = default;
    ~PlayerFallState() = default;

    void on_enter() override;
    void on_update(float delta) override;
};

class PlayerIdleState : public StateNode {
public:
    PlayerIdleState() = default;
    ~PlayerIdleState() = default;

    void on_enter() override;
    void on_update(float delta) override;
};

class PlayerJumpState : public StateNode {
public:
    PlayerJumpState() = default;
    ~PlayerJumpState() = default;

    void on_enter() override;
    void on_update(float delta) override;
};

class PlayerRollState : public StateNode {
public:
    PlayerRollState();
    ~PlayerRollState() = default;

    void on_enter() override;
    void on_update(float delta) override;
    void on_exit() override;

private:
    Timer timer;
};

class PlayerRunState : public StateNode {
public:
    PlayerRunState() = default;
    ~PlayerRunState() = default;

    void on_enter() override;
    void on_update(float delta) override;
    void on_exit() override;
};

#endif //HOLLOWSAMURAI_PLAYER_STATE_NODES_H