#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n * m == 0) return n + m;

        int D[n+1][m+1];
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int i = 0; i < m + 1; i++) {
            D[0][i] = i;
        }
        
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left_down, min(left, down));
            }
        }

        return D[n][m];
    }
};