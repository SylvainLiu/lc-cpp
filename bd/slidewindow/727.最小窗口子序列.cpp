#include<limits.h>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        if (s1 == "" || s2 == "") return "";

        int l = 0, r = INT_MAX, i1 = 0, i2 = 0;
        while (i1 < s1.size()) {
            if (s1[i1] == s2[i2]) {
                i2++;
            }
            if (i2 == s2.size()) {
                int tmpr = i1;
                i2--;

                while (i2 >= 0) {
                    if (s1[i1] == s2[i2]) {
                        i2--;
                    }
                    i1--;
                }
                
                i1++;
                i2 = 0;

                if (tmpr - i1 < r - l) {
                    r = tmpr;
                    l = i1;
                }
            }
            i1++;
        }

        return r == INT_MAX ? "" : s1.substr(l, r-l+1);
    }
};