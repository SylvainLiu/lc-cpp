#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (string word: wordDict) {
            set.insert(word);
        }

        int dp[s.size() + 1];
        dp[0] = 1;
        for (int i = 1; i <= set.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] == 1 && set.find(s.substr(j, i - j)) != set.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};