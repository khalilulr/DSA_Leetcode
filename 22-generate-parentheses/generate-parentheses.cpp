class Solution {
public:
    void solve(int ob,int cb,int n,string ss,vector<string >&ans){
        if(ob==n && cb==n){
            ans.push_back(ss);
            return;
        }
        if(ob>n || cb>n)
            return;
        
        if(cb<ob){
            solve(ob,cb+1,n,ss+')',ans);
        }
            solve(ob+1,cb,n,ss+'(',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ss;
        solve(0,0,n,ss,ans);
        return ans;
    }
};