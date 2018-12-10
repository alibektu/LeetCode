/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* temp = root;
      if (root == NULL) {
        return root;
      }

      if (p->val > q->val) {
        swap(p, q);
      }

      while (1) {
        if (p->val < temp->val && q->val < temp->val) {
          temp = temp->left;
        } else if (p->val > temp->val && q->val > temp->val) {
          temp = temp->right;
        } else {
          return temp;
        }
      }
    }
};
