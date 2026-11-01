class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto token:tokens){
            if(token=="*" || token=="/" ||  token=="-" || token=="+"){
                if(st.size()<2)
                    return -1;

                double cur=st.top();st.pop();
                double prev=st.top();st.pop();

                double result;
                if(token=="/"){
                    result=prev/cur;
                }else if(token=="*")
                    result=prev*cur;
                else if(token=="+")
                    result=prev+cur;
                else result = prev - cur;

                st.push(result);
            }else {
                st.push(stoi(token));
            }
        }
        return st.top();

    }
};