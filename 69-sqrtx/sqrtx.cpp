class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1)
            return x;

        int l = 1;
        int h = x;
        int ans = 0;

        while (l <= h) {

            int mid = l + (h - l) / 2;

            long long square = 1LL * mid * mid;

            if (square == x)
                return mid;

            if (square < x) {
                ans = mid;      // possible answer
                l = mid + 1;    // search right
            } else {
                h = mid - 1;    // search left
            }
        }

        return ans;
    }
};