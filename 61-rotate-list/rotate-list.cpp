class Solution {
public:
    ListNode* rot(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

       
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

       
        prev->next = nullptr;
        curr->next = head;
        return curr;
    }

    int l(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; 

        int n = l(head);
        k = k % n;       
        if (k == 0) return head; 

        ListNode* rotatedHead = head;
        for (int i = 0; i < k; i++) {
            rotatedHead = rot(rotatedHead);
        }
        return rotatedHead;
    }
};
