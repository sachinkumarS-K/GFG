// User function Template for C++

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
    string preToInfix(string exp) {
        // Write your code here
        stack<string>stk;
        int i = exp.size()-1;
        while(i >= 0){
            char c = exp[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                stk.push(string(1,c));
            }
            else{
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                string str = "(" + b + c + a + ")";
                stk.push(str);
            }
                        
            i--;
        }
        string str = stk.top();
        reverse(str , 0 , str.size()-1);
        return str;
    }
};