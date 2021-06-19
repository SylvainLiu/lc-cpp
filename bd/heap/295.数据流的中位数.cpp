#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        while (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        return left.size() > right.size() ? (double)left.top() : (left.top() + right.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */