//3274. Check if Two Chessboard Squares Have the Same Color
/*
You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.
Below is the chessboard for reference.
Return true if these two squares have the same color and false otherwise.
The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).
*/
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        if(squareIsWhite(coordinate1) == squareIsWhite(coordinate2))
            return true;
        return false;
    }

    bool squareIsWhite(string coordinates) {
        std::string blacks{"aceg"};
        std::string whites{"bdfh"};
        char first = coordinates[0];
        std::string second{coordinates[1]};
        int n = std::stoi(second);
        n = n % 2;

        if(blacks.find(first) != -1)
        {
            if(0 == n)
                return true;
            return false;
        }
        else
        {
            if(0 == n)
                return false;
            return true;

        }

        return false;
    }
};
