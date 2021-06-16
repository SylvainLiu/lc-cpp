#include<algorithm>
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        int* nums = new int[k];
        nums[0] = 1;
        int i3 = 0, i5 = 0, i7 = 0;

        for (int i = 1; i < k; ++i) {
            nums[i] = min(min(nums[i3] * 3, nums[i5] * 5), nums[i7] * 7);
            if (nums[i3] * 3 == nums[i]) {
                ++i3;
            } 
            if (nums[i5] * 5 == nums[i]) {
                ++i5;
            } 
            if (nums[i7] * 7 == nums[i]) {
                ++i7;
            }
        }
        return nums[k-1];
    }
};