#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result(n);
        result[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            result[i] = min(min(2*result[p2], 3*result[p3]), 5*result[p5]);
            if (result[i] == 2*result[p2]) p2++;
            if (result[i] == 3*result[p3]) p3++;
            if (result[i] == 5*result[p5]) p5++;
        }

        return result[n-1];
    }
};