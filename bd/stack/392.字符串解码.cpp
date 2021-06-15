#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getDigits(string &s, size_t &ptr){ 
        string ret = "";
        while(isdigit(s[ptr])){
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector<string> &v) {
        string ret;
        for (const auto &s: v){
            ret += s;
        }
        return ret;
    }

    string decodeString(string s){
        vector<string> stk;
        size_t ptr = 0;

        while(ptr < s.size()){
            char cur = s[ptr];
            if (isdigit(cur)){
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                stk.pop_back();

                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);

                while(repTime--) t += o;
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};