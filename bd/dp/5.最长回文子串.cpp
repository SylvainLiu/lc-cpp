#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";

        int max = 0, left = 0;
        int** dp = new int*[s.size()];
        for (int i = s.size() - 1; i >= 0; --i) {
            dp[i] = new int[s.size()];
            for (int j = i; j < s.size(); ++j) {
                if (i <= j && s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1] == 1)) {
                    dp[i][j] = 1;
                    if (max < j - i + 1) {
                        left = i;
                        max = j - i + 1;
                    }
                }
            }
        }

        return s.substr(left, max);
    }
};