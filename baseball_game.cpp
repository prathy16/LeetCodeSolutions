# https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int ret = 0;
        
        for(string op: ops){
            if(op == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            
            else if(op == "D"){
                st.push(2*st.top());
            }
            
            else if(op == "C"){
                st.pop();
            }
            
            else{
                st.push(stoi(op));
            }
        }
        
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        
        return ret;
    }
};
