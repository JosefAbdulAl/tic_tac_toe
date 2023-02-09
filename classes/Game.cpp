#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"

Game::Game() : board{}, p1(Player(1)), p2(Player(2)), p1_turn(true) {}

int Game::start() {
    int row {};
    int col {};

    while(!board.won(p1) and !board.won(p2) and !board.is_full()) {
        bool valid = false;
        board.print_matrix();
        std::cin >> row >> col;

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

void Game::change_turn() {
    p1_turn = !p1_turn;
}
