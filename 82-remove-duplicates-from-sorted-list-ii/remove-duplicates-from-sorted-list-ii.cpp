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
ListNode* insert(ListNode* head ,int x)
{
    ListNode* temp=new ListNode(x);
    temp->next=head;
    return temp;
}
ListNode* reverse(ListNode*head)
{
    ListNode* curr=head;
    ListNode* prev=NULL;
    while (curr!=NULL)
    {ListNode*next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;






    }
    return prev;
}


    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        unordered_map<int,int>m;
        ListNode* temp=head;
         ListNode* ret=head;
        ListNode* run=head;
        while(temp!=NULL)
        {m[temp->val]++;
temp=temp->next;
        }
        ListNode* r=NULL;
      while(run!=NULL)
      {if(m[run->val]<2)
      {r=insert(r,run->val);

      }
      run=run->next;
      



      }
      return reverse(r);

    }
};
                            