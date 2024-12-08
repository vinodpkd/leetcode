//1812. Determine Color of a Chessboard Square
/*
You are given coordinates, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.
Return true if the square is white, and false if the square is black.
The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.
*/
class Solution {
public:
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
