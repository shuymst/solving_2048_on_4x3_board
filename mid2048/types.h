#ifndef _TYPES_H_
#define _TYPES_H_

#include <cinttypes>

enum Square : uint8_t {
    SQ_1A, SQ_1B, SQ_1C, SQ_1D,
    SQ_2A, SQ_2B, SQ_2C, SQ_2D,
    SQ_3A, SQ_3B, SQ_3C, SQ_3D,
    SQUARE_NB = 12, SQUARE_NULL = 13
};

inline Square& operator++(Square& sq) {
    return sq = Square((int)sq + 1);
}

enum Action {
    RIGHT_ACTION, DOWN_ACTION, LEFT_ACTION, UP_ACTION, INVALID_ACTION
};

constexpr Action ALL_ACTIONS[] = {RIGHT_ACTION, DOWN_ACTION, LEFT_ACTION, UP_ACTION};

#endif