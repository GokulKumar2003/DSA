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
    void dfs(TreeNode* node, TreeNode* parent, int& ans, set<TreeNode*>& s){

        if(node == NULL){
            return;
        }

        dfs(node->left, node, ans, s);
        dfs(node->right, node, ans, s);

        if((parent == NULL && s.find(node) == s.end())
            || (node->left && s.find(node->left) == s.end()) ||(node->right && s.find(node->right) == s.end())){
                ans++;
                s.insert(node);
                s.insert(parent);
                if(node->left){
                    s.insert(node->left);
                }
                if(node->right){
                    s.insert(node->right);
                }
            }
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        set<TreeNode*> s;

        dfs(root, NULL, ans, s);
        return ans;
    }
};