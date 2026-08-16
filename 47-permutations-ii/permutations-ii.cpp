class Solution {
public:
    void solve(int i, int n, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == n) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int j = i; j < n; j++) {

            // Don't use the same number twice at this level
            if (used.count(nums[j]))
                continue;

            used.insert(nums[j]);

            swap(nums[i], nums[j]);

            solve(i + 1, n, nums, ans);

            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(0, nums.size(), nums, ans);

        return ans;
    }
};