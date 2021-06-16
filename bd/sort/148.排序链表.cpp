struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
public:
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy, *tmp1 = head1, *tmp2 = head2;
        while (tmp1 != nullptr && tmp2 != nullptr)
        {
            if (tmp1->val < tmp2->val)
            {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if (tmp1 != nullptr)
        {
            tmp->next = tmp1;
        }
        else if (tmp2 != nullptr)
        {
            tmp->next = tmp2;
        }
        return dummy->next;
    }
};

class Solution2
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        int length = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            node = node->next;
            length++;
        }
        ListNode *dummy = new ListNode(0, head);
        for (int sub = 1; sub < length; sub <<= 1)
        {
            ListNode *prev = dummy, *cur = dummy->next;
            while (cur != nullptr)
            {
                ListNode *head1 = cur;
                for (int i = 1; i < sub && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }

                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < sub && cur != nullptr && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }

                ListNode *next = nullptr;
                if (cur != nullptr)
                {
                    next = cur->next;
                    cur->next = nullptr;
                }

                ListNode *merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr)
                {
                    prev = prev->next;
                }
                cur = next;
            }
        }
        return dummy->next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp1 = head1, *tmp2 = head2, *tmp = dummy;
        while (tmp1 != nullptr && tmp2 != nullptr)
        {
            if (tmp1->val <= tmp2->val)
            {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if (tmp1 != nullptr)
        {
            tmp->next = tmp1;
        }
        else if (tmp2 != nullptr)
        {
            tmp->next = tmp2;
        }
        return dummy->next;
    }
};