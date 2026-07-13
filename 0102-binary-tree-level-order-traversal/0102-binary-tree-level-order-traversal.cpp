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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<vector<TreeNode*>> q;
        q.push({root});
        while(!q.empty() && !q.front().empty()){
            vector<TreeNode*> temp=q.front();
            vector<int> add;
            q.pop();
            q.push({});
            for(TreeNode* node:temp){
                add.push_back(node->val);
                if(node->left)q.front().push_back(node->left);
                if(node->right)q.front().push_back(node->right);

            }
            ans.push_back(add);

        }
        return ans;
        
    }
};