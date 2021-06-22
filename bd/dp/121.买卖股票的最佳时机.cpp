#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = INT_MIN, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            result = max(prices[i] - minPrice, result);
        }
        return result;
    }
};