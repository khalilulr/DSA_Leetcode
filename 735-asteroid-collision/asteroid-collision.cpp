class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast:asteroids){
            bool isAlive=true;
            while(isAlive &&
                !st.empty()
                && st.top()>0
                && ast<0){
                    if(st.top()<-ast){
                        st.pop();
                    }
                    else if(st.top()==-ast){
                        st.pop();
                        isAlive=false;
                    }
                    else isAlive=false;
                }
            if(isAlive)
                st.push(ast);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};