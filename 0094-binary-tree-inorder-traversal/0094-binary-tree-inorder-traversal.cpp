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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* thread=curr->left;
                while(thread->right && thread->right!=curr){
                    thread=thread->right;
                }
                if(thread->right==curr){
                    thread->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
                else {
                    thread->right=curr;
                    curr=curr->left;
                    }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
        
    }
};