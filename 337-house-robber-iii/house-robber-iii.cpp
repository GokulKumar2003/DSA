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
    vector<int> find(TreeNode* root){

        if(root == NULL){
            return {0, 0};
        }

        vector<int> left = find(root->left);
        vector<int> right = find(root->right);

        int withRoot = root->val + left[1] + right[1];
        int withOutRoot = max(left[0], left[1]) +
                          max(right[0], right[1]);

        return {withRoot, withOutRoot};
    }
    int rob(TreeNode* root) {
        
        vector<int> maxVal = find(root);

        return max(maxVal[0], maxVal[1]);
    }
};