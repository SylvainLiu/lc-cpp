struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *fast = head, *slow = head;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
            if (!fast) return false;
            
            fast = fast->next;
            if (!fast) return false;

            if (fast == slow) return true;
        }

        return false;
    }
};