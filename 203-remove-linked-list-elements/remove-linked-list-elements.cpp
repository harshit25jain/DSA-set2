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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* pre = head;
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == 1 && temp->val == val) {
                head = head->next;
                temp = temp->next;
            } else {
                while (temp->val != val && temp->next != NULL) {
                    pre = temp;
                    temp = temp->next;
                }
                if (temp->val == val) {
                    pre->next = temp->next;
                }
                temp = temp->next;
                cnt++;
            }
        }
        return head;
    }
};