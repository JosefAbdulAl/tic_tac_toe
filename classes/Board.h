#pragma once

#include "Player.h"

namespace tic {
    class Board {
    public:
        Board();
        void print_matrix() const;
        bool modify_matrix(int row, int col, Player const & p);
        bool won(Player const & p) const;
        bool is_full() const;

    private:
        int matrix[3][3];
        bool move_is_valid(int row, int col) const;
        bool check_row(Player const & p) const;
        bool check_col(Player const & p) const;
        bool check_diag(Player const & p) const;
    };
}
