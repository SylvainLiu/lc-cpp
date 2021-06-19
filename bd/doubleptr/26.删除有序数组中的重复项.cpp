#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int fast = 1, slow = 1;
        while (fast < nums.size()) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast++];
            } else {
                fast++;
            }
        }
        return slow;
    }
};