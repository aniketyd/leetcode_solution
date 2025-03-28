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
    int maxLevelSum(TreeNode* root) {
        // if(!root) return {};
        queue <TreeNode*> q;
        q.push(root);
        int lvl=0,ans,max=INT_MIN;

        while(!q.empty())
        {
            int l = q.size(),sum=0;
            lvl++;
            for(int i=0;i<l;i++)
            {
                TreeNode* cn = q.front();
                q.pop();

                if(cn->left)
                q.push(cn->left);
                if(cn->right)
                q.push(cn->right);
                
                sum+=cn->val;
            }
           if(sum>max)
           {
                ans=lvl;
                max=sum;
            }
        }
        return ans;
    }
};