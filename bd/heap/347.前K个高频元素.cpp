#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp (pair<int, int>& i, pair<int, int>& j) {
        return i.second > j.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occurrences;
        for (int i : nums) {
            occurrences[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (pair<int,int> i : occurrences) {
            if (q.size() == k) {
                if (i.second > q.top().second) {
                    q.pop();
                    q.push(i);
                }
            }
            else {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().first);            
            q.pop();
        }

        return result;
    }
};