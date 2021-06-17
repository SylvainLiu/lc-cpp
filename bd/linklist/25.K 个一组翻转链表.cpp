#include<iostream>
#include<utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        while (head) {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }
            ListNode *next = tail->next;

            tie(head,tail) = reverse(head,tail);

            pre->next = head;
            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode *prev = tail->next;
        ListNode *cur = head;
        while(tail != prev) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail, head};
    }
};