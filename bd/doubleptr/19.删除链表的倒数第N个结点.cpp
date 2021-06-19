struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode *prev = new ListNode(0, head);
        ListNode *fast = prev, *slow = prev;
        for (int i = 0; i < n && fast; ++i) {
            fast = fast->next;
        }

        if (!fast) return head;

        while (fast -> next) {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow->next) {
            slow->next = slow->next->next;
        }
        return prev->next;
    }
};