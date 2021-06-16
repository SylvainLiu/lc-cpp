#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n+1, 0);

        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        deque<int> q;
        int j = 0;
        int res = n + 1;
        while (j <= n) {
            while (!q.empty() && sum[j] < sum[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && sum[j] >= sum[q.front()] + k){
                res = min(res, j - q.front());
                q.pop_front();
            }
            q.push_back(j);
            j++;
        }

        return res == n + 1 ? -1 : res;
    }
};