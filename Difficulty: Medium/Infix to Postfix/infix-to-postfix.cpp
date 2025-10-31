class Solution {
  public:
    int getPriority(char ch){
        if(ch == '^')
            return 3;
        else if(ch == '*' || ch == '/')
            return 2;
        else if(ch == '+' || ch == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        string ans = "";
        stack<char>stk;
        
        for(auto c : s){
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                ans += c;
            } 
            else if (c == '(') {
                stk.push(c);
            } 
            else if(c == ')'){
                while (!stk.empty() && stk.top() != '(') {
                    ans += stk.top();
                    stk.pop();
                }
                if (!stk.empty()) stk.pop();
            }
            else{
                while (!stk.empty() && stk.top() != '(' &&
                      (getPriority(stk.top()) > getPriority(c) ||
                      (getPriority(stk.top()) == getPriority(c) && c != '^'))) {
                    ans += stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }
         while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};
