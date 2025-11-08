class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size() , ans = INT_MIN;
        int preProd = 1 , suffProd = 1;
        int temp = 1;
        for(int i = 0 ; i<n ; i++){
            if(preProd == 0)
                preProd = 1;
            if(suffProd == 0)
                suffProd = 1;
            preProd *= arr[i];
            suffProd *= arr[n-i-1];
            ans = max(ans , max(preProd , suffProd));
        }
        
        return ans;
    }
};