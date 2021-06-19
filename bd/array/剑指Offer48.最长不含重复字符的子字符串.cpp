#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 1) return s.size();

        int left = 0, right = 0, l = 0;
        unordered_map<char, int> count;
        while (right < s.size()) {
            char r = s[right];
            count[r]++;

            while (count[r] > 1) {
                count[s[left]]--;
                left++;
            }

            l = max(l, right - left + 1);
            right++;
        }

        return l;
    }
};