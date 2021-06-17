struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *result = new ListNode(0);
        ListNode *prev = result;
        bool add;
        while (l1 || l2) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + (add ? 1 : 0);
            add = sum > 9;

            prev->next = new ListNode(sum > 9 ? sum - 10 : sum);
            
            prev = prev->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if (add) {
            prev->next = new ListNode(1);
        }

        return result->next;
    }
};