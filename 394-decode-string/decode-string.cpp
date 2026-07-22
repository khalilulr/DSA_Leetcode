class Solution {
public:
    string decodeString(string s) {
        stack<int>st;
        stack<char>stCh;
        int num=0;

        for(auto ch:s){
            if(isdigit(ch)){
                int rem=ch-'0';
                num=num*10+rem;
            }
            else if(ch=='['){
                st.push(num);
                stCh.push(ch);
                num=0;
            }else if(ch!=']'){
                stCh.push(ch);
            }
            else{
                string cur="";
                while(!stCh.empty() && stCh.top()!='['){
                    cur=stCh.top()+cur;
                    stCh.pop();
                }
                stCh.pop();

                int curNum=st.top();
                st.pop();
                string f="";

                for(int i=0;i<curNum;i++){
                    f+=cur;
                }
                
                for(auto curCh:f)
                    stCh.push(curCh);
            }

        }

        string ans="";
        while(!stCh.empty()){
            ans=stCh.top()+ans;
            stCh.pop();
        }

        return ans;

    }
};