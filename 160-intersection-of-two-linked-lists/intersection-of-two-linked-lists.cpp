/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* d1=head1;
        ListNode* d2=head2;
        if (head1==nullptr||head2==nullptr)
        return nullptr;
        while(d1!=d2)
        {
            if (d1==nullptr)
            
                d1=head2;
                else
                d1=d1->next;

            
            if (d2==nullptr)
            
                d2=head1;
                else
                d2=d2->next;

            
            

        }return d1;


        
    }
};