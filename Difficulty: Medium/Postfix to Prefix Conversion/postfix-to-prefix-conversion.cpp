// User function Template for C++

class Solution {
  public:
    string postToPre(string exp) {
        // Write your code here
        stack<string>stk;
        for(auto c : exp){
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                stk.push(string(1,c));
            else{
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                string str = c + b + a;
                stk.push(str);
            }
        }
        return stk.top();
    }
};