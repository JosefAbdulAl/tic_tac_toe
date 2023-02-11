#include "Player.h"

namespace tic {
    Player::Player(const Sign sign) : sign(sign) {}

    Sign Player::get_sign() const {
        return sign;
    }
}