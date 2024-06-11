class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mp(1001, 0);
        vector<int> ans;

        for (int num : arr1) {
            mp[num]++;
        }

        for (int num : arr2) {
            while (mp[num]-- > 0) {
                ans.push_back(num);
            }
        }

        for (int i = 0; i < mp.size(); ++i) {
            while (mp[i]-- > 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
