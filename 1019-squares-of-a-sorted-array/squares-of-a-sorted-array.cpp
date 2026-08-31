class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0, r = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];

            if (left > right) {
                ans[i] = left;
                l++;
            } else {
                ans[i] = right;
                r--;
            }
        }

        return ans;
    }
};