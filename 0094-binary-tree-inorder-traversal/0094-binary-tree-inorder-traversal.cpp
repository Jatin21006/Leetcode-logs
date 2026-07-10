/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int> &ans,stack<TreeNode*> & st){
        if(node==NULL && st.empty())return;
        if(node==NULL){
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            temp=temp->right;
            return inorder(temp,ans,st);
        }
        st.push(node);
        return inorder(node->left,ans,st);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        inorder(root,ans,st);
        return ans;
        
    }
};