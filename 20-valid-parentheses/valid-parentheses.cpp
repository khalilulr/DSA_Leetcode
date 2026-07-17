class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char b:s){
            if(b=='(' || b=='[' || b=='{')
                st.push(b);
            else{
                if(st.empty())
                    return false;
                if(st.top()!='(' && b==')' || b==']' && st.top()!='[' || b=='}' && st.top()!='{')
                    return false;
                st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};