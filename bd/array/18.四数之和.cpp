#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int first = nums[i];

            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == nums[j - 1]) {
                    continue;
                }
                int second = nums[j];
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    if (first + second + nums[k] + nums[l] == target) {
                        result.push_back({first,second,nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if ((first + second + nums[k] + nums[l] > target)) {
                        l--;
                    } else {
                        k++;
                    }

                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
            }
        }

        return result;
    }
};