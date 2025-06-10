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
    vector<int> nextLargerNodes(ListNode* head) {
        
        // store in vector
        ListNode* temp = head;
        vector<int> ll;
        while (temp) {
            ll.push_back(temp->val);
            temp = temp->next;
        }

        stack<int> st;
        for (int i = 0; i<ll.size(); i++) {
            // remove all greater element
            while (!st.empty() && ll[i] > ll[st.top()]) {
               ll[st.top()] = ll[i];
               st.pop();
            }
            // push index
            st.push(i);
        }

        // mark all element on index to 0
        while (!st.empty()) {
            ll[st.top()] = 0;
            st.pop();
        }

        return ll;
    }
};