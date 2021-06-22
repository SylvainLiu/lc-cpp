#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int** dp = new int*[nums.size()];
        dp[0] = new int[2]{0, nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = new int[2];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};