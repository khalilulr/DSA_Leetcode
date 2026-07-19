class Solution {
public:
    bool rotateString(string s, string goal) {
        //cdeabcdeab
        int n=s.size();
        goal+=goal;
        int m=goal.size();
        int i=0,j=0;
        while(j<m){
            if(s[0]==goal[j]){
                if(s==goal.substr(j,n))
                    return true;
            }
            j++;
        }
        return false;
    }
};