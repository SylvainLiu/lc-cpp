struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow;
        ListNode *l2 = reverse(slow->next);
        slow->next = nullptr;

        merge(head, l2);
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {
        ListNode* l1tmp, l2tmp;
        while (l1 && l2) {
            ListNode *l1tmp = l1->next;
            ListNode *l2tmp = l2->next;

            l1->next = l2;
            l1 = l1tmp;

            l2->next = l1;
            l2 = l2tmp;
        }
    }
};