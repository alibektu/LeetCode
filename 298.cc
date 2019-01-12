/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    int max_len = 0;
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    void find_longest(TreeNode * root, int len) {
        max_len = max(max_len, len);
        
        if (root->left != NULL) {
            find_longest(root->left, root->left->val - root->val == 1? len + 1 : 1);
        }
        if (root->right != NULL) {
            find_longest(root->right, root->right->val - root->val == 1? len + 1 : 1);
        }
    }
    int longestConsecutive(TreeNode * root) {
        find_longest(root, 1);
        return max_len;
    }
};
