#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0) return vector<int>();
        if (words.size() == 0) return vector<int>();

        unordered_map<string, int> counts;
        for (string word : words) {
            counts[word]++;
        }

        int num = words.size();
        int step = words[0].size();
        vector<int> result;

        for (int i = 0; i < step; i++) {
            int cur_num = 0, left = i, right = i;
            unordered_map<string, int> cur_count;

            while (right + step - 1 < s.size()) {
                string w = s.substr(right, step);
                right += step;

                if (counts[w] == 0) {
                    left = right;
                    cur_count.clear();
                    cur_num = 0;
                }
                else
                {
                    cur_count[w]++;
                    cur_num++;
                    while (cur_count[w] > counts[w]) {
                        string lw = s.substr(left, step);
                        left += step;
                        cur_count[lw]--;
                        cur_num--;
                    }

                    if (cur_num == num) {
                        result.push_back(left);
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();

    vector<string> words = {"foo","bar"};
    vector<int> result = s->findSubstring("barfoothefoobarman", words);
}