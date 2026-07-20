class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        // maxE[i] = maximum element from nums[0...i]
        vector<int> maxE(n);
        maxE[0] = nums[0];

        for (int i = 1; i < n; i++) {
            maxE[i] = max(maxE[i - 1], nums[i]);
        }

        // minE[i] = minimum element from nums[i...n-1]
        vector<int> minE(n);
        minE[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minE[i] = min(minE[i + 1], nums[i]);
        }

        vector<int> ans(n);

        ans[n - 1] = maxE[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (maxE[i] <= minE[i+1]) {
                ans[i] = maxE[i];
            } else {
                ans[i] = ans[i + 1];
            }
        }

        return ans;
    }
};