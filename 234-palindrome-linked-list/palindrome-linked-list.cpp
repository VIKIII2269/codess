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
    bool isPalindrome(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while (f!=nullptr&&f->next!=nullptr)
        {
            s=s->next;
            f=f->next->next;

        }
        ListNode* curr=s;
        ListNode* p=nullptr;
        ListNode* n;

        while (curr!=nullptr)
        {
            n=curr->next;
            curr->next=p;
            p=curr;
            curr=n;

        }
        ListNode* temp=head;
                ListNode* temp2=p;

        
        while(temp2!=nullptr)
        {if(temp->val!=temp2->val)
            return false;
temp=temp->next;
        temp2=temp2->next;

        }
        return true;
    }
};