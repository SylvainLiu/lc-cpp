#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int two = INT_MIN;
        stack<int> stk3;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < two) {
                return true;
            }
            while (!stk3.empty() && stk3.top() < nums[i]) {
                two = stk3.top();
                stk3.pop();
            }
            stk3.push(nums[i]);
        }

        return false;
    }
};