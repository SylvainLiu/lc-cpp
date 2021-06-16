#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDay = 0;
        unordered_map<int, vector<int>> m;

        for (vector<int>& event: events) {
            maxDay = max(maxDay, event[1]);
            m[event[0]].push_back(event[1]);
        }

        int res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= maxDay; ++i) {
            if (m.find(i) != m.end()) {
                for (int day : m[i]) {
                    q.push(day);
                }
            }
            while (!q.empty() && q.top() < i) {
                q.pop();
            }
            if (!q.empty()) {
                res++;
                q.pop();
            }
        }

        return res;
    }
};