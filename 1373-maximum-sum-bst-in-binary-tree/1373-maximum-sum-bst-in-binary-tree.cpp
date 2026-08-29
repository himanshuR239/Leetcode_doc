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
    int ans = 0;
    // {isBST, minVal, maxVal, sum}
    vector<int> traverse(TreeNode* node){
        if(!node){
            return {1, INT_MAX, INT_MIN, 0};
        }

        // Postorder Traversal
        auto left = traverse(node->left);
        auto right = traverse(node->right);

        if(left[0] && right[0] && left[2] < node->val && right[1] > node->val){
            int cur_sum = node->val + left[3] + right[3];
            ans = max(ans, cur_sum);

            return {1, min(node->val, left[1]), max(node->val, right[2]), cur_sum};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        traverse(root);
        return ans;
    }
};