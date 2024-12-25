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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty()){
            int mx=INT_MIN;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                mx=max(mx,node->val);
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                    
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                   
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};