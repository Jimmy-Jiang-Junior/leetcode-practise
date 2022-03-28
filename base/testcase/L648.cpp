#include <cstdio>
#include <unordered_map>
#include <gtest/gtest.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool flag;
};

class Solution {
    TrieNode* root;
public:
    Solution() {
        root = new TrieNode();
    }
    // 典型的字典树插入操作
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (cur->children.count(c) <= 0) {
                TrieNode* node = new TrieNode();
                cur->children.insert(make_pair(c, node));
            }
            cur = cur->children[c];
        }
        cur->flag = true;
    }

    // 对输入字符串进行处理, 如果字典里有root返回root, 否则返回原字符串
    string findRoot(string word) {
        TrieNode* cur = root;
        string result;
        bool isRoot = false; // 是否为root的判断需要注意处理
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (cur->children.count(c) <= 0) {
                break;
            }
            cur = cur->children[c];
            result += c;
            if (cur->flag) {
                isRoot = true;
                break;
            }
        }

        return isRoot ? result : word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (int i = 0; i < dictionary.size(); i++) {
            insert(dictionary[i]);
        }
        int left = 0;
        int right = 0;
        int len = sentence.length();
        string result;
        while (right < len) {
            while ((sentence[right] != ' ') && (right < len)) {
                right++;
            }
            string sub = sentence.substr(left, right - left);
            result += findRoot(sub);
            if (right == len) {
                break;
            }
            result += ' '; // 末尾空格的处理需要注意
            right++;
            left = right;
        }

        return result;
    }
};

TEST(L648, CASE_001)
{
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string expectStr = "the cat was rat by the bat";

    class Solution s;
    string result = s.replaceWords(dictionary, sentence);
    EXPECT_STREQ(expectStr.c_str(), result.c_str()); // gtest似乎只能比较c类型的字符串
    printf("%s\n", result.c_str());
}

TEST(L648, CASE_002)
{
    vector<string> dictionary = {"a","b","c"};
    string sentence = "aadsfasf absbs bbab cadsfafs";
    string expectStr = "a a b c";

    class Solution s;
    string result = s.replaceWords(dictionary, sentence);
    EXPECT_STREQ(expectStr.c_str(), result.c_str()); // gtest似乎只能比较c类型的字符串
    printf("%s\n", result.c_str());
}