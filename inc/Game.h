#pragma once
#include "Board.h"
#include "Player.h"
#include "types.h"

namespace tic {
    class Game {
        public:
            void start();

        private:
            Board board;
            const Player p1{Sign::CROSS};
            const Player p2{Sign::CIRCLE};
            bool p1_turn{true};
            void change_turn();
    };
}

