#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int length = temperatures.size();
        vector<int> ans(length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while((!stk.empty()) && temperatures[i] > temperatures[stk.top()]){
                int pre = stk.top();
                ans[pre] = i - pre;
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};