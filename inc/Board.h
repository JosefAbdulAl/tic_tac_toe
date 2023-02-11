#pragma once

#include "Player.h"
#include "types.h"

namespace tic {
    class Matrix {
        public:
            Sign get(int row, int col) const;
            void set(int row, int col, Sign sign);
        
        private:
            Sign m_matrix[3][3]{};
                            
    };

    class Board {
        public:
            void print_matrix() const;
            bool modify_matrix(int row, int col, Player const & p);
            bool won(Player const & p) const;
            bool is_full() const;

        private:
            Matrix matrix{};
            bool move_is_valid(int row, int col) const;
            bool check_row(Player const & p) const;
            bool check_col(Player const & p) const;
            bool check_diag(Player const & p) const;
    };
}
