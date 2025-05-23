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
    unordered_map<TreeNode*,int>mi,mx,sum;
    int ans=0;
    bool isBst(TreeNode* root){
        if(root->left==NULL&&root->right==NULL){
            mi[root]=root->val;
            mx[root]=root->val;
            sum[root]=root->val;
            ans=max(ans,root->val);
            return true;
        }
        bool b1=true,b2=true;
        if(root->left!=NULL)
        b1=isBst(root->left);
        if(root->right!=NULL)
        b2=isBst(root->right);
        if(!b1||!b2){
         return false;
        }
        if(!((((root->val)<mi[root->right])||(root->right==NULL))&&((((root->val)>mx[root->left]))||(root->left==NULL))))
        return false;
        sum[root]=sum[root->left]+sum[root->right]+root->val;
        
        ans=max(ans,sum[root]);
        if(root->right!=NULL)
        mx[root]=mx[root->right];
        else mx[root]=root->val;
        if(root->left!=NULL)
        mi[root]=mi[root->left];
        else
        mi[root]=root->val;
          return true;
    }
    int maxSumBST(TreeNode* root) {
        if(root==NULL)return 0;
        isBst(root);
        return ans;
    }
};