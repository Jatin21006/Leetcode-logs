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
    int solve(TreeNode* root, int &ans){
        if(!root)return 0;
        int lh=solve(root->left,ans);
        int rh=solve(root->right,ans);
        int sum=root->val;
        if(lh>0)sum+=lh;
        if(rh>0)sum+=rh;
        ans=max(ans,sum);
        return max(max(root->val+lh,root->val+rh),root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans=INT_MIN;
        int h=solve(root,ans);
        return ans;
        
    }
};