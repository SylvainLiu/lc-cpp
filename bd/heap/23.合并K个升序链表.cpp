#include<queue>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return merge2Lists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        if (!a || !b) return a ? a : b;
        ListNode head, *cur = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                cur->next = aPtr;
                aPtr = aPtr->next;
            } else {
                cur->next = bPtr;
                bPtr = bPtr->next;
            }
            cur = cur->next;
        }
        cur->next = aPtr ? aPtr : bPtr;
        return head.next;
    }
};

class Solution {
    public:
        struct status {
            int val;
            ListNode *ptr;
            bool operator < (const status *other) const {
                return val > other->val;
            }
        };

        priority_queue<status> q;

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            for (auto node: lists) {
                if (node) q.push({node->val, node});
            }
            ListNode head, *tail = &head;
            while(!q.empty()) {
                auto f = q.top(); q.pop();
                tail->next = f.ptr;
                tail = tail->next;
                if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
            }
            return head.next;
        }
};