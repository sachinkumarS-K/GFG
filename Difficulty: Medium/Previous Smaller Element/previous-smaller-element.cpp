class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>stk;
        int n = arr.size();
        vector<int>ans(n , -1);
        
        for(int i = 0 ; i<n ; i++){
            while(!stk.empty() && stk.top() >= arr[i]){
                stk.pop();
            }
            if(!stk.empty())
                ans[i] = stk.top();
            stk.push(arr[i]);
        }
        
        return ans;
    }
};