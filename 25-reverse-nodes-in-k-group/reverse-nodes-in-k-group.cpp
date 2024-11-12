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
void rev(ListNode* head) {
        ListNode* curr=head;
        ListNode* p=nullptr;
        ListNode* n;
        if (head==nullptr||head->next==nullptr)
        return ;
        while (curr!=nullptr)
        {
           n=curr->next;
           curr->next=p;
           p=curr;
           curr=n;
            
        }        
        
    }
    ListNode* find(ListNode* temp,int k)
    {
        k=k-1;
        while (k>0&&temp!=nullptr)
        {
            temp=temp->next;
            k--;
        }return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int s) {
        
        ListNode* temp=head;      
          ListNode* pn;

        
        while(temp!=nullptr)
        {
         ListNode* k=find(temp,s);
         if (k==nullptr)

         {if(pn)
         pn->next=temp;
            break;
         }ListNode* nn=k->next;
         k->next=nullptr;
         rev(temp);
         if (temp==head)
         head=k;
         else 
         pn->next=k;

         pn=temp;
         temp=nn;
        }return head;
    }
};