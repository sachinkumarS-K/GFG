class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        vector<int>ans = {INT_MAX , INT_MIN};
        for(int i : arr){
            ans[0] = min(i , ans[0]);
            ans[1] = max(i , ans[1]);
        }
        
        return ans;
    }
};