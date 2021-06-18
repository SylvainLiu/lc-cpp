struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        
        int length = 0;
        ListNode *slow = head, *fast = head;

        while (fast) {
            fast = fast->next;
            length++;
        }

        int n = k % length;
        // if (n == 0) return head;

        int i = 0;
        fast = head;
        while (i < n) {
            fast = fast->next;
            i++;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};