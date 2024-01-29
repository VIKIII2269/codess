class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            n++;
            tail = tail->next;
        }

        k = k % n;

        if (k == 0) {
            return head;
        }

        tail->next = head;

        ListNode* newHead = head;
        for (int i = 0; i < n - k - 1; i++) {
            newHead = newHead->next;
        }

        ListNode* rotatedHead = newHead->next;
        newHead->next = nullptr;

        return rotatedHead;
    }
};
