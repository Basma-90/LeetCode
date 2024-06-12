class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3];

        for(int i=0;i<nums.size();++i){
            freq[nums[i]]++;
        }

        vector<int>ans;
        for(int i=0;i<3;i++){
            while(freq[i]--){
               ans.push_back(i);
            }
        }

 nums=ans;
    }
};