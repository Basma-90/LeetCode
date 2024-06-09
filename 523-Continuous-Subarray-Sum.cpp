class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        if (n < 2) return false; 
        
        if (k == 0) {
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i] == 0 && nums[i + 1] == 0) {
                    return true;
                }
            }
            return false;
        }
        
        unordered_map<int, int> remMap;
        int sum = 0;
        remMap[0] = -1; 
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int remainder = sum % k;
            
            if (remMap.count(remainder) && i - remMap[remainder] >= 2) {
                return true;
            }
         
            if (!remMap.count(remainder)) {
                remMap[remainder] = i;
            }
        }
        
        return false;
    }
};
