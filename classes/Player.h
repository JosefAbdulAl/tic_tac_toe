#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player(int sign, bool my_turn);
        int get_sign() const;
        bool get_my_turn() const;
        void change_turn();

    private:
        int sign;
        bool my_turn;
};

#endif // PLAYER_H
