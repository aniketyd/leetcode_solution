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
    int d=0;
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        return max(dfs(root->left),dfs(root->right))+1;
    }
    TreeNode* ans;
    int dfs2(TreeNode* root,int level){
        if(root==NULL)return 0;
        int lft=dfs2(root->left,level+1);
        int rght=dfs2(root->right,level+1);
        if(lft+level==d&&rght+level==d){
             ans=root;
        }
        return max(lft,rght)+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        d=dfs(root);
      dfs2(root,1);
        return ans;
    }
};