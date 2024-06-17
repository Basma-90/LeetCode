class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;

        int cnt = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                cnt =cnt+ (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        }

        return cnt;
    }
};
