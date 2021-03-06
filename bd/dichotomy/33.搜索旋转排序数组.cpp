#include <vector>
using namespace std;

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return -1;
        }

        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[l] < nums[mid] && (nums[l] <= target && nums[mid] > target)) {
            return search(nums, target, l, mid - 1);
        }
        else if (nums[mid] < nums[r] && (nums[mid] > target || nums[r] < target)){
            return search(nums, target, l, mid - 1);
        }
        return search(nums, target, mid + 1, r);
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};