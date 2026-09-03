class Solution {
public:
    void solve(int sIdx,int end,int size,vector<int>&ss,vector<vector<int>>&ans){
        if(ss.size()==size){
            ans.push_back(ss);
            return;
        }
        if(sIdx>end)
            return;

        ss.push_back(sIdx);
        solve(sIdx+1,end,size,ss,ans);
        ss.pop_back();
        solve(sIdx+1,end,size,ss,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ss;
        solve(1,n,k,ss,ans);
        return ans;
    }
};