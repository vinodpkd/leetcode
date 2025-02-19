//374. Guess Number Higher or Lower
/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.
  */
class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + ((high - low)>>1); // Slightly faster calculation
            int result = guess(mid);
            if (result == 0) {
                return mid; // Correct guess
            } else if (result == -1) {
                high = mid - 1; // Guess is too high
            } else {
                low = mid + 1; // Guess is too low
            }
        }
        return -1; // This line is theoretically unreachable if the input is valid
    }
};
