class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorV=0;
        for(auto num:nums)
            xorV^=num;
        return xorV;
    }
};