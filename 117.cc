/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* cur = root;
        TreeLinkNode* prev;
        TreeLinkNode* next_head;
        while(cur!=NULL) {
            next_head = NULL;
            prev = NULL;
            while (cur != NULL) {
                if (prev != NULL) {
                    if (cur->left != NULL) {
                        prev->next = cur->left;
                        prev = NULL;
                    } else if (cur->right != NULL) {
                        prev->next = cur->right;
                        prev = NULL;
                    }
                }

                if (cur->left != NULL && cur->right!=NULL) {
                    cur->left->next = cur->right;
                }

                if (cur->left != NULL) {
                    prev = cur->left;
                    next_head = !next_head ? cur->left : next_head;
                }

                if (cur->right != NULL) {
                    prev = cur->right;
                    next_head = !next_head ? cur->right : next_head;
                }

                cur = cur->next;
            }

            cur = next_head;
        }
    }
};
