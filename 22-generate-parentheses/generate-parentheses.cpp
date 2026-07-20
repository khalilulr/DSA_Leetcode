class Solution {
public:
    void solve(int ob,int cb,int n,vector<string>&ans,string ss){
        if(ob==n && cb==n){
            ans.push_back(ss);
            return;
        }
        if(ob> n || cb>n)
            return;
        if( ob>cb){
            solve(ob,cb+1,n,ans,ss+')');
        }
        solve(ob+1,cb,n,ans,ss+'(');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ss;
        solve(0,0,n,ans,ss);
        return ans;
    }
};