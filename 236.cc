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
    if (root == NULL) {
      return NULL;
    }

    unordered_map<TreeNode*, TreeNode*> parent_map;
    unordered_map<TreeNode*, bool> vis;
    queue<TreeNode*> qs;

    qs.push(root);
    parent_map[root] = NULL;

    while (!qs.empty()) {
      TreeNode* temp = qs.front(); qs.pop();

      if (temp->left != NULL) {
        parent_map[temp->left] = temp;
        qs.push(temp->left);
      }

      if (temp->right != NULL) {
        parent_map[temp->right] = temp;
        qs.push(temp->right);
      }
    }


    TreeNode* temp = q;
    while (temp != NULL) {
      vis[temp] = true;
      temp = parent_map[temp];
    }

    temp = p;
    while (temp != NULL) {
      if (vis[temp]) {
        return temp;
      }

      temp = parent_map[temp];
    }
  }
};
