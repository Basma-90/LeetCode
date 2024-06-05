class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> minFreq;
        for (char ch : words[0]) {
            minFreq[ch]++;
        }
        for (int i = 1; i < words.size(); ++i) {
            unordered_map<char, int> charCount;
            for (char ch : words[i]) {
                charCount[ch]++;
            }
 
            for (auto& pair : minFreq) {
                pair.second = min(pair.second, charCount[pair.first]);
            }
        }

   
        vector<string> ans;
        for (auto& pair : minFreq) {
            for (int i = 0; i < pair.second; ++i) {
                ans.push_back(string(1, pair.first)); 
            }
        }

        return ans;
    }
};
