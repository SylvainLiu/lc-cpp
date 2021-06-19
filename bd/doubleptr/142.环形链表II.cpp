struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next || !head->next->next) return nullptr;
        
        ListNode* fast = head, *slow = head;
        fast = fast->next->next;
        slow = slow->next;
        
        while (fast != slow) {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            } else {
                return nullptr;
            }
            slow = slow->next;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
int main() {
    // ListNode *head5 = new ListNode(5);    
    ListNode *head4 = new ListNode(4);
    ListNode *head3 = new ListNode(0, head4);
    ListNode *head2 = new ListNode(2, head3);
    ListNode *head1 = new ListNode(3, head2);
    head4->next = head2;

    Solution* s = new Solution();
    s->detectCycle(head1);
}