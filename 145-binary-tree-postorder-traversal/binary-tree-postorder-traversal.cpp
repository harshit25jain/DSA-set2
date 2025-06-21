class Solution {
public:
    vector<int> arr;

    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        arr.push_back(root->val);
        return arr;
    }
};

/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        stack<TreeNode*> st;
        vector<int> ans;

        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            
            if (temp->left) st.push(temp->left);
            if (temp->right) st.push(temp->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/