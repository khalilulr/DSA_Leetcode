class Solution {
public:
    int cntSub(int mid, vector<int>& nums) {
        int currentSum = 0;
        int subArrCnt = 1;

        for (int num : nums) {
            if (currentSum + num <= mid) {
                currentSum += num;
            } else {
                subArrCnt++;
                currentSum = num;
            }
        }

        return subArrCnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int l = maxi, h = sum;
        int ans = sum;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (cntSub(mid, nums) > k) {
                l = mid + 1;
            } else {
                ans = mid;
                h = mid - 1;
            }
        }

        return ans;
    }
};