class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int carry=1;
        int n=digits.size();

        for(int i=n-1;i>=0;i--){
            int curSum=digits[i] + carry;
            carry=curSum/10;
            int digit=curSum%10;

            ans.push_back(digit);
        }

        if(carry)
            ans.push_back(carry);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};