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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode *>q;
        q.push(root);
        int s=0;
        while(!q.empty()){
            auto node=q.front();
            if(node->val>=low && node->val<=high)
            s+=node->val;
            // cout<<node->val<<" ";
            // if(val>=low && val<=high) s+=val;
            q.pop();
            if(node->val>high){
                if(node->left)
                q.push(node->left);
            }
            else if(node->val<low){
                if(node->right)
                q.push(node->right);
            }
            else{
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
        }
        return s;
    }
};
