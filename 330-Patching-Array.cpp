class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
      int cnt=0;
      long long ans=1;
      int i=0;

      while(ans<=n){
        if(i<(nums.size()) && nums[i]<=ans){
            ans+=nums[i++];
        }else{
            cnt++;
            ans+=ans;
        }
      }

      return cnt;
    }
};