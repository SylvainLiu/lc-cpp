#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int num : nums) {
            if (map[num]) {
                return num;
            }
            map[num] = true;
        }
        return -1;
    }
};