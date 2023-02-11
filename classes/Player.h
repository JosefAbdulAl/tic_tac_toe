#pragma once

#include "types.h"

namespace tic {
    class Player {
        public:
            Player(const Sign sign);
            Sign get_sign() const;

        private:
            const Sign sign;
    };
}

