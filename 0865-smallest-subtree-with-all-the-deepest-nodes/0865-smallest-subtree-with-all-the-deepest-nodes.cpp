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
    int getMaxD(TreeNode* root){
        if(!root) return 0;
        return 1 + max(getMaxD(root->left), getMaxD(root->right));
    }

    TreeNode* solve(TreeNode* root, int d, int maxD){
        if(!root) return NULL;
        if(d == maxD) return root;

        TreeNode* left = solve(root->left, d+1, maxD);
        TreeNode* right = solve(root->right, d+1, maxD);

        if(left && right) return root;
        return left ? left : right;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxD = getMaxD(root);

        return solve(root, 1, maxD);
    }
};