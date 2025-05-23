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
    unordered_map<TreeNode*,int>dp;
    void bfs(TreeNode* root,TreeNode* parent){
        if(root->left==NULL&&root->right==NULL){
           dp[parent]=1;
           return;
        }
        if(root->left!=NULL)
        bfs(root->left,root);
        if(root->right!=NULL)
        bfs(root->right,root);
        if(dp[root]==0){
            if(!dp[root->right]&&!dp[root->left]){
               dp[parent]=1;
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL)return 0;
        bfs(root,NULL);
        int ans=0;
        for(auto val:dp)
        if(val.second==1)
        ans++;
        return ans;
       
    }
};