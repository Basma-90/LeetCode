class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    string getShortestPrefix(const string& word) {
        TrieNode* currentNode = root;
        string prefix = "";
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                break;
            }
            prefix += ch;
            currentNode = currentNode->children[ch];
            if (currentNode->isEndOfWord) {
                return prefix;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        stringstream ss(sentence);
        string word;
        string result = "";
        
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.getShortestPrefix(word);
        }
        
        return result;
    }
};