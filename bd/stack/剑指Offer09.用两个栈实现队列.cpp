#include<stack>
using namespace std;

class CQueue
{
public:
    stack<int> stkIn;
    stack<int> stkOut;
    
    CQueue()
    {
    }

    void appendTail(int value) {
        stkIn.push(value);
    }

    int deleteHead() {
        if (stkOut.empty()) { 
            while (!stkIn.empty()) {
                stkOut.push(stkIn.top());
                stkIn.pop();
            }
        }

        if (stkOut.empty()) { return -1;}
            
        int top = stkOut.top();
        stkOut.pop();
        return top;
    }
};