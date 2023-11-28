#include "board.h"
#include <algorithm>
#include <gtest/gtest.h>

TEST(spawn_empty, 0) {
    Board::init();
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        EXPECT_EQ(true, board.is_empty(sq));
        board.spawn(sq, 1);
        EXPECT_EQ(false, board.is_empty(sq));
    }
}

TEST(do_action, 1) {
    /* 
    1 0 1 1
    0 0 1 0 
    1 1 2 2
    */
    Board board(0);
    board.spawn(SQ_1A, 1); board.spawn(SQ_1B, 0); board.spawn(SQ_1C, 1); board.spawn(SQ_1D, 1); 
    board.spawn(SQ_2A, 0); board.spawn(SQ_2B, 0); board.spawn(SQ_2C, 1); board.spawn(SQ_2D, 0); 
    board.spawn(SQ_3A, 1); board.spawn(SQ_3B, 1); board.spawn(SQ_3C, 2); board.spawn(SQ_3D, 2); 
    EXPECT_EQ(board.do_action(RIGHT_ACTION), 4+4+8);
    EXPECT_EQ(board.get_num(SQ_1A), 0); EXPECT_EQ(board.get_num(SQ_1B), 0); EXPECT_EQ(board.get_num(SQ_1C), 1); EXPECT_EQ(board.get_num(SQ_1D), 2);
    EXPECT_EQ(board.get_num(SQ_2A), 0); EXPECT_EQ(board.get_num(SQ_2B), 0); EXPECT_EQ(board.get_num(SQ_2C), 0); EXPECT_EQ(board.get_num(SQ_2D), 1);
    EXPECT_EQ(board.get_num(SQ_3A), 0); EXPECT_EQ(board.get_num(SQ_3B), 0); EXPECT_EQ(board.get_num(SQ_3C), 2); EXPECT_EQ(board.get_num(SQ_3D), 3);
}

TEST(do_action, 2) {
    /* 
    2 2 1 4
    0 4 3 4
    0 1 3 1
    */
    Board board(0);
    board.spawn(SQ_1A, 2); board.spawn(SQ_1B, 2); board.spawn(SQ_1C, 1); board.spawn(SQ_1D, 4); 
    board.spawn(SQ_2A, 0); board.spawn(SQ_2B, 4); board.spawn(SQ_2C, 3); board.spawn(SQ_2D, 4); 
    board.spawn(SQ_3A, 0); board.spawn(SQ_3B, 1); board.spawn(SQ_3C, 3); board.spawn(SQ_3D, 1); 
    EXPECT_EQ(board.do_action(DOWN_ACTION), 16+32);
    EXPECT_EQ(board.get_num(SQ_1A), 0); EXPECT_EQ(board.get_num(SQ_1B), 2); EXPECT_EQ(board.get_num(SQ_1C), 0); EXPECT_EQ(board.get_num(SQ_1D), 0);
    EXPECT_EQ(board.get_num(SQ_2A), 0); EXPECT_EQ(board.get_num(SQ_2B), 4); EXPECT_EQ(board.get_num(SQ_2C), 1); EXPECT_EQ(board.get_num(SQ_2D), 5);
    EXPECT_EQ(board.get_num(SQ_3A), 2); EXPECT_EQ(board.get_num(SQ_3B), 1); EXPECT_EQ(board.get_num(SQ_3C), 4); EXPECT_EQ(board.get_num(SQ_3D), 1);
}

TEST(do_action, 3) {
    /* 
    2 2 5 5
    1 3 1 2
    1 1 1 0
    */
    Board board(0);
    board.spawn(SQ_1A, 2); board.spawn(SQ_1B, 2); board.spawn(SQ_1C, 5); board.spawn(SQ_1D, 5); 
    board.spawn(SQ_2A, 1); board.spawn(SQ_2B, 3); board.spawn(SQ_2C, 1); board.spawn(SQ_2D, 2); 
    board.spawn(SQ_3A, 1); board.spawn(SQ_3B, 1); board.spawn(SQ_3C, 1); board.spawn(SQ_3D, 0); 
    EXPECT_EQ(board.do_action(LEFT_ACTION), 8+64+4);
    EXPECT_EQ(board.get_num(SQ_1A), 3); EXPECT_EQ(board.get_num(SQ_1B), 6); EXPECT_EQ(board.get_num(SQ_1C), 0); EXPECT_EQ(board.get_num(SQ_1D), 0);
    EXPECT_EQ(board.get_num(SQ_2A), 1); EXPECT_EQ(board.get_num(SQ_2B), 3); EXPECT_EQ(board.get_num(SQ_2C), 1); EXPECT_EQ(board.get_num(SQ_2D), 2);
    EXPECT_EQ(board.get_num(SQ_3A), 2); EXPECT_EQ(board.get_num(SQ_3B), 1); EXPECT_EQ(board.get_num(SQ_3C), 0); EXPECT_EQ(board.get_num(SQ_3D), 0);
}

TEST(do_action, 4) {
    /* 
    1 0 1 11
    2 2 1 11
    1 2 1  5
    */
    Board board(0);
    board.spawn(SQ_1A, 1); board.spawn(SQ_1B, 0); board.spawn(SQ_1C, 1); board.spawn(SQ_1D, 11); 
    board.spawn(SQ_2A, 2); board.spawn(SQ_2B, 2); board.spawn(SQ_2C, 1); board.spawn(SQ_2D, 11); 
    board.spawn(SQ_3A, 1); board.spawn(SQ_3B, 2); board.spawn(SQ_3C, 1); board.spawn(SQ_3D,  5); 
    EXPECT_EQ(board.do_action(UP_ACTION), 8+4+4096);
    EXPECT_EQ(board.get_num(SQ_1A), 1); EXPECT_EQ(board.get_num(SQ_1B), 3); EXPECT_EQ(board.get_num(SQ_1C), 2); EXPECT_EQ(board.get_num(SQ_1D), 12);
    EXPECT_EQ(board.get_num(SQ_2A), 2); EXPECT_EQ(board.get_num(SQ_2B), 0); EXPECT_EQ(board.get_num(SQ_2C), 1); EXPECT_EQ(board.get_num(SQ_2D),  5);
    EXPECT_EQ(board.get_num(SQ_3A), 1); EXPECT_EQ(board.get_num(SQ_3B), 0); EXPECT_EQ(board.get_num(SQ_3C), 0); EXPECT_EQ(board.get_num(SQ_3D),  0);
}

TEST(is_changed_by, 5) {
    /*
    1  2  3  4
    5  6  7  8
    9 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, (int)sq+1);
    }
    EXPECT_FALSE(board.is_changed_by(RIGHT_ACTION));
    EXPECT_FALSE(board.is_changed_by(DOWN_ACTION));
    EXPECT_FALSE(board.is_changed_by(LEFT_ACTION));
    EXPECT_FALSE(board.is_changed_by(UP_ACTION));
}

TEST(is_changed_by, 6) {
    /*
    1  2  3  0
    5  6  7  8
    9 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        if (sq != SQ_1D) {
            board.spawn(sq, (int)sq+1);
        }
    }
    EXPECT_TRUE(board.is_changed_by(RIGHT_ACTION));
    EXPECT_FALSE(board.is_changed_by(DOWN_ACTION));
    EXPECT_FALSE(board.is_changed_by(LEFT_ACTION));
    EXPECT_TRUE(board.is_changed_by(UP_ACTION));
}

TEST(is_changed_by, 7) {
    /*
    1  2  3  4
    5  6  7  8
    0 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        if (sq != SQ_3A) {
            board.spawn(sq, (int)sq+1);
        }
    }
    EXPECT_FALSE(board.is_changed_by(RIGHT_ACTION));
    EXPECT_TRUE(board.is_changed_by(DOWN_ACTION));
    EXPECT_TRUE(board.is_changed_by(LEFT_ACTION));
    EXPECT_FALSE(board.is_changed_by(UP_ACTION));
}

TEST(is_changed_by, 8) {
    /*
    1  1  3  4
    5  6  7  8
    9 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        if (sq == SQ_1B) {
            board.spawn(sq, 1);
        } else {
            board.spawn(sq, (int)sq+1);
        }
    }
    EXPECT_TRUE(board.is_changed_by(RIGHT_ACTION));
    EXPECT_FALSE(board.is_changed_by(DOWN_ACTION));
    EXPECT_TRUE(board.is_changed_by(LEFT_ACTION));
    EXPECT_FALSE(board.is_changed_by(UP_ACTION));
}

TEST(is_changed_by, 9) {
    /*
    1  2  3  4
    1  6  7  8
    9 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        if (sq == SQ_2A) {
            board.spawn(sq, 1);
        } else {
            board.spawn(sq, (int)sq+1);
        }
    }
    EXPECT_FALSE(board.is_changed_by(RIGHT_ACTION));
    EXPECT_TRUE(board.is_changed_by(DOWN_ACTION));
    EXPECT_FALSE(board.is_changed_by(LEFT_ACTION));
    EXPECT_TRUE(board.is_changed_by(UP_ACTION));
}

TEST(is_game_over1, 10) {
    /*
    1  2  3  4
    5  6  7  8
    9 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, (int)sq+1);
    }
    EXPECT_TRUE(board.is_gameover());
}

TEST(is_game_over2, 11) {
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, 1);
    }
    EXPECT_FALSE(board.is_gameover());
}

TEST(key, 12) {
    /*
    1  2  3  4
    5  6  7  8
    9 10 11 12
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, (int)sq+1);
    }
    uint64_t key = board.key();
    Board another_board(0);
    another_board.set(key);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        EXPECT_EQ(board.get_num(sq), another_board.get_num(sq));
    }
}

TEST(flip, 13) {
    /*
    1  2  3  4     4  3  2  1
    5  6  7  8 ->  8  7  6  5
    9 10 11 12    12 11 10  9
    */

    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, (int)sq+1);
    }
    Board flipped_board(0);
    flipped_board.spawn(SQ_1A,  4); flipped_board.spawn(SQ_1B,  3); flipped_board.spawn(SQ_1C,  2); flipped_board.spawn(SQ_1D, 1);
    flipped_board.spawn(SQ_2A,  8); flipped_board.spawn(SQ_2B,  7); flipped_board.spawn(SQ_2C,  6); flipped_board.spawn(SQ_2D, 5);
    flipped_board.spawn(SQ_3A, 12); flipped_board.spawn(SQ_3B, 11); flipped_board.spawn(SQ_3C, 10); flipped_board.spawn(SQ_3D, 9);

    EXPECT_EQ(board.flip_horizontal(), flipped_board.key());
}

TEST(flip, 14) {
    /*
    1  2  3  4     9 10 11 12
    5  6  7  8 ->  5  6  7  8
    9 10 11 12     1  2  3  4
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, (int)sq+1);
    }
    Board flipped_board(0);
    flipped_board.spawn(SQ_1A, 9); flipped_board.spawn(SQ_1B, 10); flipped_board.spawn(SQ_1C, 11); flipped_board.spawn(SQ_1D, 12);
    flipped_board.spawn(SQ_2A, 5); flipped_board.spawn(SQ_2B,  6); flipped_board.spawn(SQ_2C,  7); flipped_board.spawn(SQ_2D,  8);
    flipped_board.spawn(SQ_3A, 1); flipped_board.spawn(SQ_3B,  2); flipped_board.spawn(SQ_3C,  3); flipped_board.spawn(SQ_3D,  4);

    EXPECT_EQ(board.flip_vertical(), flipped_board.key());
}

TEST(flip, 15) {
    /*
    1  2  3  4    12 11 10  9
    5  6  7  8 ->  8  7  6  5
    9 10 11 12     4  3  2  1
    */
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, (int)sq+1);
    }
    Board flipped_board(0);
    flipped_board.spawn(SQ_1A, 12); flipped_board.spawn(SQ_1B, 11); flipped_board.spawn(SQ_1C, 10); flipped_board.spawn(SQ_1D, 9);
    flipped_board.spawn(SQ_2A,  8); flipped_board.spawn(SQ_2B,  7); flipped_board.spawn(SQ_2C,  6); flipped_board.spawn(SQ_2D, 5);
    flipped_board.spawn(SQ_3A,  4); flipped_board.spawn(SQ_3B,  3); flipped_board.spawn(SQ_3C,  2); flipped_board.spawn(SQ_3D, 1);

    EXPECT_EQ(board.flip_diagonal(), flipped_board.key());
}

TEST(empty_squares, 16) {
    Board board(0);
    for (Square sq = SQ_1A; sq < SQUARE_NB; ++sq) {
        board.spawn(sq, 1);
    }
    std::vector<Square> empty_squares = board.empty_squares();
    EXPECT_EQ(empty_squares.size(), 0);
}

TEST(empty_squares, 17) {
    Board board(0);
    board.spawn(SQ_1A, 1); board.spawn(SQ_1B, 0); board.spawn(SQ_1C, 5); board.spawn(SQ_1D, 10);
    board.spawn(SQ_2A, 0); board.spawn(SQ_2B, 4); board.spawn(SQ_2C, 1); board.spawn(SQ_2D, 0);
    board.spawn(SQ_3A, 2); board.spawn(SQ_3B, 0); board.spawn(SQ_3C, 0); board.spawn(SQ_3D, 11);
    
    std::vector<Square> empty_squares = board.empty_squares();
    EXPECT_EQ(empty_squares.size(), 5);
}

TEST(board_sum, 18) {
    Board board(0);
    board.spawn(SQ_1A, 0); board.spawn(SQ_1B, 2); board.spawn(SQ_1C, 3); board.spawn(SQ_1D, 1);
    board.spawn(SQ_2A, 1); board.spawn(SQ_2B, 2); board.spawn(SQ_2C, 3); board.spawn(SQ_2D, 1);
    board.spawn(SQ_3A, 3); board.spawn(SQ_3B, 4); board.spawn(SQ_3C, 6); board.spawn(SQ_3D, 4);

    EXPECT_EQ(board.get_board_sum(), 2 * 3 + 4 * 2 + 8 * 3 + 16 * 2 + 64);
}