#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        
        int i_start = 0, i_end = matrix.size() - 1;
        int j_start = 0, j_end = matrix[0].size() - 1;
        vector<int> ans;

        while(i_start <= i_end && j_start <= j_end) {
            for (int j = j_start; j <= j_end; j++) {
                ans.push_back(matrix[i_start][j]);
            }
            for (int i = i_start + 1; i <= i_end; i++) {
                ans.push_back(matrix[i][j_end]);
            }
            if (i_start != i_end) {
                for (int j = j_end - 1; j > j_start; j--) {
                ans.push_back(matrix[i_end][j]);
                }
            }
            if (j_start != j_end){
                for (int i = i_end; i > i_start; i--) {
                    ans.push_back(matrix[i][j_start]);
                }
            }
            
            i_start++;
            i_end--;
            j_start++;
            j_end--;
        }
        return ans;
    }
};