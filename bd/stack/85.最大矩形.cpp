#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int ans = 0;
        vector<int> line(matrix[0].size() + 2, 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                line[j + 1] = (matrix[i][j] == '0') ? 0 : line[j + 1] + 1;
            }
            ans = max(ans, maxRectangleArea(line));
        }
        return ans;
    }

    int maxRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                ans = max(ans, height * (i - stk.top()-1));
            }
            stk.push(i);
        }
        return ans;
    } 
};