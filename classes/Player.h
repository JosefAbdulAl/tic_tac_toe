#pragma once

namespace tic {class Player {
    public:
        Player(const int sign);
        int get_sign() const;

    private:
        const int sign;
    };
}

