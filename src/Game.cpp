#include <iostream>
#include <limits>

#include "Game.h"

namespace tic {
    void Game::start() {
        while(!board.won(p1) and !board.won(p2) and !board.is_full()) {
            bool valid = false;
            board.print_matrix();

            // Get user input.
            int col{}, row{};
            while (true) {
                std::cin >> row >> col;
                if (std::cin.fail()) {
                    // Clear error flag and ignore up to streamsize max number of new lines.
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cout << "Illegal input, please try again." << std::endl;
                } else {
                    break;
                }
            }

            if(p1_turn) {
                valid = board.modify_matrix(row,col,p1);
            }
            else {
                valid = board.modify_matrix(row,col,p2);
            }
            
            if(valid) {
                change_turn();
            }
            else {
                std::cout << "Invalid move, please try again!" << std::endl;
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
    }

    void Game::change_turn() {
        p1_turn = !p1_turn;
    }
}