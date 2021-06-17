#include<utility>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) :val(val), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        if (left == right) return head;

        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy, *pre = dummy;
        ListNode *l, *r, *next;
        for (int i = 1; i <= right; i++) {
            cur = cur->next;
            if (!cur) {
                return head;
            }
            if (i == left - 1) {
                pre = cur;
            }
            if (i == right) {
                r = cur;
            }
        }

        l = pre->next;
        next = r->next;

        tie(l, r) = reverse(l, r);

        pre->next = l;
        r->next = next;
        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(prev != tail) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail, head};
    }
};

int main(){
    ListNode *head5 = new ListNode(5);    
    // ListNode *head4 = new ListNode(4, head5);
    ListNode *head3 = new ListNode(3, head5);
    // ListNode *head2 = new ListNode(2, head3);
    // ListNode *head1 = new ListNode(1, head2);

    Solution* s = new Solution();
    ListNode* result = s->reverseBetween(head3, 1, 2);
    return 0;
}