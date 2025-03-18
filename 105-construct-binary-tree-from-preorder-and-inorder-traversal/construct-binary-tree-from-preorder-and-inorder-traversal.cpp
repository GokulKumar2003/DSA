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
    TreeNode* buildTreeHelper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int, int>& inorder_val_to_index){

        if(ps > pe || (is > ie)){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[ps]);
        int ind = inorder_val_to_index[preorder[ps]];
        int numsLeft = ind - is;
        node->left = buildTreeHelper(preorder, ps+1, ps+numsLeft, inorder, is, ind-1, inorder_val_to_index);
        node->right = buildTreeHelper(preorder, ps+numsLeft+1, pe, inorder, ind+1, ie, inorder_val_to_index);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> inorder_val_to_index;
        for(int i=0;i<inorder.size();i++){
            inorder_val_to_index[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorder_val_to_index);
    }
};