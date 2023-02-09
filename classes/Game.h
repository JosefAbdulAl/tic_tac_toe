#include "Board.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H

class Game {
    public:
        Game();
        int start();

    private:
        Board board;
        Player p1;
        Player p2;
        bool p1_turn;
        void change_turn();
};

#endif // GAME_H