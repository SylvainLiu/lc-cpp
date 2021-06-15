#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int ans = 0;

        stack<int> stk;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                ans = max(ans, height * (i- stk.top() - 1));
            }
            stk.push(i);
        }
        return ans;
    }
};