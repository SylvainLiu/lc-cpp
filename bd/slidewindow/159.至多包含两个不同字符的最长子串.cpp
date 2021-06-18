#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() == 0) return 0;

        int left = 0, right = 0, count = 0, longest = 0;
        unordered_map<char, int> current;
        while (right < s.size()) {
            char r = s[right];
            if (current[r] > 0) {
                current[r]++;
            }
            else if (count < 2) {
                current[r]++;
                count++;
            } else {
                while (current[s[left]] > 0) {
                    current[s[left]]--;
                    if (current[s[left++]] == 0) {
                        break;
                    }
                }
                current[r]++;
            }

            longest = max(longest, right - left + 1);
            right++;            
        }

        return longest;
    }
};