#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> set;
        int m = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (set.find(s[i]) != set.end()) {
                set.erase(s[left++]);
            }
            set.insert(s[i]);
            m = max(i - left + 1, m);
        }
        return m;
    }
};

int main() { 
    Solution* s = new Solution();
    int result = s->lengthOfLongestSubstring("abcabcbb");
    cout << result << endl;
}