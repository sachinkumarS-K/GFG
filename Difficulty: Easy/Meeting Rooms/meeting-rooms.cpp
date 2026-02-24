class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin() , arr.end());
        vector<int>curr = arr[0];
        for(int i = 1 ; i<arr.size() ; i++){
            if(curr[1] > arr[i][0]){
                return false;
            }
            else{
                curr = arr[i];
            }
        }
        return true;
    }
};