#include <iostream>
#include "Board.h"

namespace tic {
    inline std::ostream & operator<< (std::ostream & os, Sign const & sign) {
        if(sign == Sign::EMPTY) {
            os << "[ ]";
        }
        else if(sign == Sign::CROSS) {
            os << "[X]";
        }
        else {
            os << "[O]";
        }

        return os;
    }

    Sign Matrix::get(int row, int col) const {
        return m_matrix[row][col];
    }

    void Matrix::set(int row, int col, Sign sign) {
        m_matrix[row][col] = sign;
    }

    void Board::print_matrix() const {
        std::cout << "------------" << std::endl;
        for(int row=0; row<3; row++) {
            for (int col=0; col<3; col++){
                std::cout << matrix.get(row,col) << " ";
            }
            std::cout << std::endl;
            }
        std::cout << "------------" << std::endl;
    }

    bool Board::modify_matrix(int row, int col, Player const & p) {
        if(move_is_valid(row, col)) {
            matrix.set(row, col, p.get_sign());
            return true;
        }
        return false;
    }

    bool Board::won(Player const & p) const {
        return check_row(p) || check_col(p) || check_diag(p);
    }

    bool Board::is_full() const {
        for(int row=0; row<3; row++) {
            for(int col=0; col<3; col++) {
                if(matrix.get(row, col) == Sign::EMPTY){
                    return false;
                }
            }
        }
        return true;
    }

    bool Board::move_is_valid(int row, int col) const {
        bool is_within_board = row < 3 && row >= 0 && col < 3 && col >= 0;
        bool tile_is_empty = matrix.get(row, col) == Sign::EMPTY;

        return is_within_board && tile_is_empty;
    }

    bool Board::check_row(Player const & p) const {
        Sign sign = p.get_sign();
        for(int row=0; row<3; row++) {
            if(matrix.get(row, 0) == sign && matrix.get(row, 1) == sign && matrix.get(row, 2) == sign) {
                return true;
            }
        }
        return false;
    }

    bool Board::check_col(Player const & p) const {
        Sign sign = p.get_sign();
        for(int col=0; col<3; col++) {
            if(matrix.get(0, col) == sign && matrix.get(1, col) == sign && matrix.get(2, col) == sign) {
                return true;
            }
        }
        return false;
    }

    bool Board::check_diag(Player const & p) const {
        Sign sign = p.get_sign();
        bool check_diag_1 = matrix.get(0, 0) == sign && matrix.get(1, 1) == sign && matrix.get(2, 2) == sign;
        bool check_diag_2 = matrix.get(0, 2) == sign && matrix.get(1, 1) == sign && matrix.get(2, 0) == sign;

        return check_diag_1 || check_diag_2;
    }
}