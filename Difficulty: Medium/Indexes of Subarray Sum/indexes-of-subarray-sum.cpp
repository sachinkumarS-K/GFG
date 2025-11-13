class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int left = 0, right = 0;
        int sum = 0;
        vector<int> ans;

        while (right < arr.size()) {
            sum += arr[right++];

            while (sum > target && left < right) {
                sum -= arr[left++];
            }

            if (sum == target) {
                ans.push_back(left + 1);   
                ans.push_back(right);      
                return ans;                
            }
        }
        if(ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};
