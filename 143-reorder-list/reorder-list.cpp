class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find the middle of the list
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* temp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }

        // Step 3: Merge the two halves
        ListNode* firstHalf = head;
        while (prev) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = prev->next;
            firstHalf->next = prev;
            prev->next = temp1;
            firstHalf = temp1;
            prev = temp2;
        }
    }
};