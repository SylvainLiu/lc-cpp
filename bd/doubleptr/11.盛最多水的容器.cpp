#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -  1, maxArea = 0;
        while (left < right) {
            int curArea = min(height[left], height[right]) * (right - left);
            maxArea = max (maxArea, curArea);
            
            if (height[left] < height[right]) {
                while (left < right) {
                    left++;
                    if (height[left] > height[left - 1]) break;
                }
            } else {
                while (left < right) {
                    right--;
                    if (height[right] > height[right + 1]) break;
                }
            }
        }
        return maxArea;
    }
};