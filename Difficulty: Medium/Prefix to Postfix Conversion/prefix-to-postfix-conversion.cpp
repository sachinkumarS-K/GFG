// User function Template for C++

class Solution {
  public:
    string preToPost(string exp) {
        stack<string>stk;
        int i = exp.size()-1;
        while(i >= 0){
            char c = exp[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                stk.push(string(1,c));
            else{
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                string str = a + b + c;
                stk.push(str);
            }
            i--;
        }
        
        return stk.top();
    }
};