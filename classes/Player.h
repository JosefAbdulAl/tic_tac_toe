#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player(const int sign);
        int get_sign() const;

    private:
        const int sign;
};

#endif // PLAYER_H
