#include "Player.h"

Player::Player(int sign, bool my_turn) : sign(sign), my_turn(my_turn) {}

int Player::get_sign() const {
    return sign;
}

bool Player::get_my_turn() const {
    return my_turn;
}

void Player::change_turn() {
    my_turn = !my_turn;
}