#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 0) return {};
        
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> result = {nums[q.back()]};

        for (int i = k; i < nums.size(); ++i) {
            if (i - k >= q.front()) {
                q.pop_front();
            }
            
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            result.push_back(nums[q.front()]);
        }

        return result;
    }
};