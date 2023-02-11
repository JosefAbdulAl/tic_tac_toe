#include "Player.h"

namespace tic {
    Player::Player(const int sign) : sign(sign) {}

    int Player::get_sign() const {
        return sign;
    }
}