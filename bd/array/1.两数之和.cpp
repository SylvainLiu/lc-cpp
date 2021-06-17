#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (hash.find(target - cur) != hash.end()) {
                return {i, hash.find(target - cur)->second};
            };
            hash[cur] = i;
        }
        return {};
    }
};