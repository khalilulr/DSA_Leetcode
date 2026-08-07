class Solution {
public:
    void solve(int i,int n,int ob,int cb,string subset,vector<string>&ans){
        if(ob==n && cb==n){
            ans.push_back(subset);
            return;
        }
        if(ob> n || cb>n)
            return;
        if(ob>cb){
            solve(i+1,n,ob,cb+1,subset+')',ans);
        }
        solve(i+1,n,ob+1,cb,subset+'(',ans);
    }
    vector<string> generateParenthesis(int n) {
        string subset="";
        vector<string>ans;
        solve(0,n,0,0,subset,ans);
        return ans;
    }
};