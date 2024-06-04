class Solution {
public:
    int longestPalindrome(std::string s) {
        
        if (s.size() == 1) {
            return 1;
        }

        string t=s;
        std::reverse(t.begin(),t.end());
        if(t==s){
            return s.size();
        }

     
        std::unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        int len = 0;
        bool f = false;

        for (const auto& it : mp) {
            if (it.second % 2 == 0) {
                len += it.second;  
            } else {
                len += it.second - 1;  
                f = true;  
            }
        }

       
        if (f) {
            len += 1;
        }

        return len;
    }
};
