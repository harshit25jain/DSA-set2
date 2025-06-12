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
    void reverse(ListNode* &head)
    {
        ListNode* prev=NULL;
        ListNode* forw=NULL;
        ListNode* curr=head;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        head=prev;
    }
    ListNode* removeNodes(ListNode* head) {
        int maxi=INT_MIN;
        reverse(head);
        ListNode* temp=head;
        while(temp && temp->next)
        {
            if(temp->next->val<temp->val)
            {
                temp->next=temp->next->next;
            }else
            temp=temp->next;
        }
        reverse(head);
        return head;
    }
};