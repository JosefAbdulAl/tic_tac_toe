#include <iostream>
#include <string>

using namespace std;

class Player {
    public:
        Player(int sign, bool my_turn){
            this -> sign = sign;
            this -> my_turn = my_turn;
        }
    
    int get_sign() {
        return sign;
    }

    bool get_my_turn() {
        return my_turn;
    }

    void change_turn() {
        my_turn = !my_turn;
    }

    private:
        int sign;
        bool my_turn;
};

class Board {

    public:
        Board() : matrix{ {0, 0, 0}, 
                          {0, 0, 0},
                          {0, 0, 0} }{}

        void print_matrix() {
            cout << "------------" << endl;
            for(int row=0; row<3; row++) {
                for (int col=0; col<3; col++){
                    cout << matrix[row][col] << " ";
                }
                cout << endl;
                }
            cout << "------------" << endl;

        }

        bool modify_matrix(int row, int col, Player p) {
            if(move_is_valid(row, col)) {
                matrix[row][col] = p.get_sign();
                return true;
            }

            else {
                return false;
            }
        }

        bool won(Player p) {
            return check_row(p) || check_col(p) || check_diag(p);
        }

        bool is_full() {
            for(int row=0; row<3; row++) {
                for(int col=0; col<3; col++) {
                    if(matrix[row][col] == 0){
                        return false;
                    }
                }
            }
            return true;
        }

    private:
        int matrix[3][3];

        bool move_is_valid(int row, int col) {
            bool is_within_board = row < 3 && row >= 0 && col < 3 && col >= 0;
            bool tile_is_empty = matrix[row][col] == 0;

            return is_within_board && tile_is_empty;
        }

        bool check_row(Player p) {
            int sign = p.get_sign();
            for(int row=0; row<3; row++) {
                if(matrix[row][0] == sign && matrix[row][1] == sign && matrix[row][2] == sign) {
                    return true;
                }
            }
            return false;
        }

        bool check_col(Player p) {
            int sign = p.get_sign();
            for(int col=0; col<3; col++) {
                if(matrix[0][col] == sign && matrix[1][col] == sign && matrix[2][col] == sign) {
                    return true;
                }
            }
            return false;
        }

        bool check_diag(Player p) {
            int sign = p.get_sign();
            bool check_diag_1 = matrix[0][0] == sign && matrix[1][1] == sign && matrix[2][2] == sign;
            bool check_diag_2 = matrix[0][2] == sign && matrix[1][1] == sign && matrix[2][0] == sign;

            return check_diag_1 || check_diag_2;
        }
};


int main() {
    Board board;
    Player p1 = Player(1, true);
    Player p2 = Player(2, false);
    int row;
    int col;

    while(!board.won(p1) and !board.won(p2) and !board.is_full()) {
        bool valid = false;
        board.print_matrix();
        cin >> row >> col;

        if(p1.get_my_turn()) {
            valid = board.modify_matrix(row,col,p1);
        }

        else if(p2.get_my_turn()) {
            valid = board.modify_matrix(row,col,p2);
        }
        
        if(valid) {
            p1.change_turn();
            p2.change_turn();
        }

        else {
            cout << "Invalid move! Try again!" << endl;
        }

    }

    board.print_matrix();
    
    if(board.won(p1)) {
    cout << "Player 1 won!" << endl;
    }

    else if(board.won(p2)) {
    cout << "Player 2 won!" << endl;
    }

    else {
    cout << "Tied!" << endl;
    }

    return 0;
}