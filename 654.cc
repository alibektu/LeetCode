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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int>> sorted;
        sorted.resize(len);
        for (int i=0; i<len; i++) {
            sorted[i].first = nums[i];
            sorted[i].second = i;
        }
        
        sort(sorted.begin(), sorted.end(), std::greater<pair<int,int>>());
        TreeNode* head = NULL;
        for (int i=0;i<len;i++) {
            if (head == NULL) {
                head = new TreeNode(sorted[i].second);
            } else {
                TreeNode* temp = head;
                cout<<sorted[i].second<<" ";
                while (1) {
                    TreeNode* new_node = new TreeNode(sorted[i].second);
                    if (temp->val > sorted[i].second) {
                        if (temp->left == NULL) {
                            temp->left = new_node;
                            break;
                        } else {
                            temp = temp->left;
                        }
                    } else {
                        if (temp->right == NULL) {
                            temp->right = new_node;
                            break;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
        }
        
        queue<TreeNode*> q;
        q.push(head);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            temp->val = nums[temp->val];
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            
            if (temp->right != NULL) {
                q.push(temp->right);
            }
            
            q.pop();
        }
        
        return head;
    }
};
