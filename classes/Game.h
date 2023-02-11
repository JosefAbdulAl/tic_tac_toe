#pragma once
#include "Board.h"
#include "Player.h"

namespace tic {
    class Game {
        public:
            Game();
            void start();

        private:
            Board board;
            const Player p1;
            const Player p2;
            bool p1_turn;
            void change_turn();
    };
}

