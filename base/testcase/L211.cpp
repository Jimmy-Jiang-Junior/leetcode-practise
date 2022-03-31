#include <cstdio>
#include <unordered_map>
#include <gtest/gtest.h>
using namespace std;

struct TrieNode {
    // 使用unordered_map这道题无法通过
    vector<TrieNode*> children; // 直接使用C的数组会更加节省时间
    bool flag;
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        flag = false;
    }
};

class WordDictionary {
    TrieNode* root;
    string wordGlobal;
    int wordLen;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word[i] - 'a';
            if (cur->children[c] == NULL) {
                TrieNode* node = new TrieNode();
                cur->children[c] = node;
            }
            cur = cur->children[c];
        }
        cur->flag = true;
    }

    bool dfsSearch(TrieNode* node, int index) {
        if (node == NULL) {
            return false;
        }
        bool matched = false;
        char c = wordGlobal[index];
        if (index == wordLen) {
            return node->flag;
        }
        
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL) {
                    matched |= dfsSearch(node->children[i], index + 1);
                    if (matched) {
                        break;
                    }
                }
            }
        } else {
            if (node->children[c - 'a'] != NULL) {
                matched |= dfsSearch(node->children[c - 'a'], index + 1);
            }
        }

        return matched;
    }
    
    bool search(string word) {
        wordGlobal = word; // 将word使用全局变量存储可以节省时间
        wordLen = word.length();
        return dfsSearch(root, 0);
    }
};