#include <iostream>
#include "classes/Player.h"
#include "classes/Board.h"


int main() {
    Board board {};
    Player p1 = Player(1, true);
    Player p2 = Player(2, false);
    int row {};
    int col {};

    while(!board.won(p1) and !board.won(p2) and !board.is_full()) {
        bool valid = false;
        board.print_matrix();
        std::cin >> row >> col;

        if(p1.get_my_turn()) {
            valid = board.modify_matrix(row,col,p1);
        }

        else if(p2.get_my_turn()) {
            valid = board.modify_matrix(row,col,p2);
        }
        
        if(valid) {
            p1.change_turn();
            p2.change_turn();
        }

        else {
            std::cout << "Invalid move! Try again!" << std::endl;
        }
    }

    board.print_matrix();
    
    if(board.won(p1)) {
        std::cout << "Player 1 won!" << std::endl;
    }

    else if(board.won(p2)) {
        std::cout << "Player 2 won!" << std::endl;
    }

    else {
        std::cout << "Tied!" << std::endl;
    }

    return 0;
}