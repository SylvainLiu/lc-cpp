#include<unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1 == "" || s2 == "") return false;

        unordered_map<char, int> need;
        for (char c : s1) {
            need[c]++;
        }

        int left = 0, right = 0, count = 0;
        while (right < s1.size()) {
            char r = s1[right];
            need[r]--;
            count++;

            while (need[r] < 0) {
                char l = s1[left];
                need[l]++;
                left++;
                count--;
            }

            if (count == s2.size()) {
                return true;
            }
        }
        return false;
    }
};