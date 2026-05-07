#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int pile : piles) right = max(right, pile); // upper bound = largest pile

        while (left <= right) {
            int mid = left + (right - left) / 2; // avoid overflow
            if (canEatInTime(piles, mid, h)) {
                // mid is valid, try smaller speeds
                right = mid - 1;
            } else {
                // mid too slow, need faster speed
                left = mid + 1;
            }
        }

        // left now points to the minimum valid speed
        return left;
    }

private:
    bool canEatInTime(const vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int pile : piles) {
            // ceil division without floating point
            hours += (pile + speed - 1) / speed;
        }
        return hours <= h;
    }
};
