class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        sort(hand.begin(),hand.end());
        
        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        for (int i = 0; i < hand.size(); ) {
            int curr = hand[i];
            
            if (freq[curr] == 0) {
                i++;
                continue;
            }

            for (int j = 0; j < groupSize; j++) {
                if (freq[curr + j] == 0) {
                    return false;
                }
                freq[curr + j]--;
            }
        }

        return true;
    }
};