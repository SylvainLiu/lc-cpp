#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            if (!merged.size() || merged.back()[1] < l) {
                merged.push_back({l, r});
            } else {
                merged.back()[1] = max(merged.back()[1], r);
            }
        }
        return merged;
    }
};