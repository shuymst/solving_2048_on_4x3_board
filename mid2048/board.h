#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <random>
#include <cassert>
#include "types.h"

class Board {
private:
    const int64_t seed;
    std::mt19937_64 mt_;
    uint8_t tiles[12];

    inline static std::vector<uint16_t> right_action_;
    inline static std::vector<uint16_t> right_action_scores_1_;
    inline static std::vector<uint16_t> right_action_scores_2_;

    inline static std::vector<uint16_t> down_action_;
    inline static std::vector<uint16_t> down_action_scores_;

public:
    public:
    static void init();
    Board(int64_t seed);
    Board(const Board&) = delete;
    Board(Board&&) = delete;

    bool is_empty(Square sq) const;
    void spawn(Square sq, int num);
    int get_num(Square sq) const;
    void random_spawn();
    void reset();
    void game_start();
    void clear();
    bool is_gameover() const;

    uint32_t do_action(Action action);
    std::vector<Action> legal_actions() const;
    uint32_t compute_reward(Action action) const;
    bool is_changed_by(Action action) const;
    std::vector<Square> empty_squares() const;

    uint64_t key() const;
    void set(uint64_t key);
    uint64_t flip_horizontal() const;
    uint64_t flip_vertical() const;
    uint64_t flip_diagonal() const;
    uint64_t normalize() const;

    int get_board_sum() const;

    void print() const;
};

#endif