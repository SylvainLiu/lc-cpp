#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> map;
        for (auto& i : intervals) {
            ++map[i[0]];
            --map[i[1]];
        }
        int ans = 0, count = 0;
        for (auto& i : map) {
            count += i.second;
            ans = max(ans, count);
        }
        return ans;
    }
};