/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* p=nullptr;
        ListNode* n;
        if (head==nullptr||head->next==nullptr)
        return head;
        while (curr!=nullptr)
        {
           n=curr->next;
           curr->next=p;
           p=curr;
           curr=n;
            
        }        
        return p;
    }
};