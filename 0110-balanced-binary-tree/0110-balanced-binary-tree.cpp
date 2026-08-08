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
private:
    pair<int, bool> dfs(TreeNode* root){
        if(root == NULL){
            return {0, true};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int height = 1 + max(left.first, right.first);

        bool balanced = left.second && right.second && abs(left.first - right.first) <= 1;

        return {height, balanced};

    }
public:
    bool isBalanced(TreeNode* root) {

        return dfs(root).second;

        
    }
};