#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() < k) {
                q.push(nums[i]);
            }
            else {
                if (q.top() < nums[i]) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }

        return q.top();
    }
};

// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/215-shu-zu-zhong-de-di-kge-zui-da-yuan-s-rfvg/