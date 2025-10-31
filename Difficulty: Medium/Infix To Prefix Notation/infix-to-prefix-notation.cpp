class Solution {
  public:
    void reverse(string &str , int l , int h){
        for(int i = 0 ; i<str.size() ; i++){
            if(str[i] == ')')
                str[i] = '(';
            else if(str[i] == '(')
                str[i] = ')';
        }
        while(l < h){
            swap(str[l++] ,str[h--]);
        }
    }
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
    string infixToPrefix(string &str) {
        reverse(str , 0 , str.size()-1);
        string ans = "";
        stack<char>stk;
        for(auto c : str){
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                ans += c;
            else if(c == '(')
                stk.push(c);
            else if(c == ')'){
                while(!stk.empty() && stk.top() != '('){
                    ans += stk.top();
                    stk.pop();
                }
                if(!stk.empty())
                    stk.pop();
            }
            else{
                while(!stk.empty() && stk.top() != '(' &&
                      (getPriority(stk.top()) > getPriority(c) ||
                      (getPriority(stk.top()) == getPriority(c) && c == '^'))){
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
        
        reverse(ans , 0 , ans.size()-1);
        return ans;
    }
};
