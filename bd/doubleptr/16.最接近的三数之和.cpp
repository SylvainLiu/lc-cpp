#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        sort(nums.begin(), nums.end());

        int absDiff = INT_MAX, sum = 0;
        for (int i = 0; i < nums.size();i++){
            int t = target - nums[i];
            
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int tmpSum = nums[j] + nums[k];
                int tmpDiff = tmpSum - target;

                if (tmpDiff > 0) k--;
                else if (tmpDiff < 0) j++;
                else return target;

                if (abs(tmpDiff) < absDiff) {
                    sum = tmpSum + nums[i];
                    absDiff = abs(tmpDiff);
                }
            }
        }

        return sum;
    }
};