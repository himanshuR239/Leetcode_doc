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
    priority_queue<int, vector<int>, greater<int>> pq;

    int dfs(TreeNode* root, int k){
        if(!root) return 0;

        int ls = dfs(root->left, k);
        int rs = dfs(root->right, k);

        if(ls == -1 || rs == -1 || ls != rs) return -1;

        pq.push(ls + rs + 1);

        if(pq.size() > k) pq.pop();

        return ls + rs + 1;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root, k);

        if(pq.size() < k) return -1;
        return pq.top();
    }
};