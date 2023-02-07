#include <iostream>
#include "Board.h"
#include "Player.h"

Board::Board() : matrix{ {0, 0, 0}, 
                         {0, 0, 0},
                         {0, 0, 0} } {}

void Board::print_matrix() const {
    std::cout << "------------" << std::endl;
    for(int row=0; row<3; row++) {
        for (int col=0; col<3; col++){
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
        }
    std::cout << "------------" << std::endl;
}

bool Board::modify_matrix(int row, int col, Player const & p) {
    if(move_is_valid(row, col)) {
        matrix[row][col] = p.get_sign();
        return true;
    }
    else {
        return false;
    }
}

bool Board::won(Player const & p) const {
    return check_row(p) || check_col(p) || check_diag(p);
}

bool Board::is_full() const {
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(matrix[row][col] == 0){
                return false;
            }
        }
    }
    return true;
}

bool Board::move_is_valid(int row, int col) const {
    bool is_within_board = row < 3 && row >= 0 && col < 3 && col >= 0;
    bool tile_is_empty = matrix[row][col] == 0;

    return is_within_board && tile_is_empty;
}

bool Board::check_row(Player const & p) const {
    int sign = p.get_sign();
    for(int row=0; row<3; row++) {
        if(matrix[row][0] == sign && matrix[row][1] == sign && matrix[row][2] == sign) {
            return true;
        }
    }
    return false;
}

bool Board::check_col(Player const & p) const {
    int sign = p.get_sign();
    for(int col=0; col<3; col++) {
        if(matrix[0][col] == sign && matrix[1][col] == sign && matrix[2][col] == sign) {
            return true;
        }
    }
    return false;
}

bool Board::check_diag(Player const & p) const {
    int sign = p.get_sign();
    bool check_diag_1 = matrix[0][0] == sign && matrix[1][1] == sign && matrix[2][2] == sign;
    bool check_diag_2 = matrix[0][2] == sign && matrix[1][1] == sign && matrix[2][0] == sign;

    return check_diag_1 || check_diag_2;
}