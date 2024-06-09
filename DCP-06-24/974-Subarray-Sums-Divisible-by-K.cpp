class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>remMap;
        long long sum=0;
        int count=0;
        remMap[0]=1;
        for(auto it : nums){
            sum+=it;
            int remainder=(sum%k +k)%k;

            if(remMap.find(remainder) != remMap.end()){
                  count+=remMap[remainder];
            }

            remMap[remainder]++;

        }

        return count;
    }
};