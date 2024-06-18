class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
         vector<pair<int,int>>vec;
        for(int i=0;i<difficulty.size();++i){
           vec.push_back({difficulty[i],profit[i]});
        }

        
       sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second; 
        }
        return a.first < b.first;
        });
        sort(worker.begin(),worker.end());
        int p=0;
        int b=0;
        int i=0;

        for(auto it :worker){
            while(i<vec.size() && vec[i].first<=it){
                b=max(b,vec[i].second);
                i++;
            }
            p+=b;
        }

return p;
    }
};