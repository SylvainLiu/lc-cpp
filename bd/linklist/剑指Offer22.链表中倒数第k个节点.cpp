struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return nullptr;
        
        ListNode *slow = head, *fast = head;
        for (int i = 1; i < k; i++) {
            slow = slow->next;
            if (!slow) return nullptr;
        }

        while (slow->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};