#include<vector>
using namespace std;    

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1, p1 = m - 1, p2 = n - 1, cur = 0;
        while (index >= 0) {
            if (p1 < 0) {
                cur = nums2[p2--];
            } else if (p2 < 0) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[index--] = cur;
        }
    }
};