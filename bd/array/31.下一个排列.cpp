#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if (i >= 0) {
            for (int j = nums.size() - 1; j >= 0; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> v = {5,1,1};
    s->nextPermutation(v);
}