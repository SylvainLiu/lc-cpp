#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                
                int left = stk.top();
                int curWidth = i - left - 1;
                int curHeight = min(height[left], height[i]) - stk.top();
                ans += curWidth * curHeight;
            }

            stk.push(i);
        }
        return ans;
    }
};