class Solution {
public:
    long long ans = 0;

    void solve(int i, int sum, int n, long long prod, int cnt) {
        if (sum == 0) {
            if (cnt >= 2)
                ans = max(ans, prod);
            return;
        }

        if (i > n || sum < 0)
            return;

        // Take i
        solve(i, sum - i, n, prod * i, cnt + 1);

        // Don't take i
        solve(i + 1, sum, n, prod, cnt);
    }

    int integerBreak(int n) {
        solve(1, n, n, 1, 0);
        return (int)ans;
    }
};