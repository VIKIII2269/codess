class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head;
        ListNode* s = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < n; i++) {
            if (f == nullptr) {
               
                return head;
            }
            f = f->next;
        }

       
        while (f != nullptr) {
            f = f->next;
            prev = s;
            s = s->next;
        }

    
        if (prev == nullptr) {
           
            head = head->next;
        } else {
            prev->next = s->next;
        }

        delete s;
        return head;
    }
};
