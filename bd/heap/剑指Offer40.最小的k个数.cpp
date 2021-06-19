#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k==0) return {};
        
        priority_queue<int> q;
        for (int i = 0; i < arr.size(); ++i) {
            if (q.size() < k) {
                q.push(arr[i]);
            }
            else {
                if (arr[i] < q.top()) {
                    q.push(arr[i]);
                    q.pop();
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};