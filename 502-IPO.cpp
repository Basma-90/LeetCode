#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }

   
        sort(projects.begin(), projects.end());

        multiset<int> availableProjects;
        int i = 0;

       
        while (k--) {
          
            while (i < n && projects[i].first <= w) {
                availableProjects.insert(projects[i].second);
                i++;
            }

            if (availableProjects.empty()) {
                break;
            }

            auto it = availableProjects.end();
            --it;
            w += *it;
            availableProjects.erase(it);
        }

        return w;
    }
};
