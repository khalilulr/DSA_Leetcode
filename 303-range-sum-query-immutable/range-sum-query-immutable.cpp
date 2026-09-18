class NumArray {
    vector<int>preSum;
public:
    NumArray(vector<int>& nums) {
        int curSum=0;
        for(auto num:nums){
            preSum.push_back(curSum);
            curSum+=num;
        }
        preSum.push_back(curSum);
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1]-preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */