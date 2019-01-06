class NumArray {
private:
    struct Node {
        int val;
        int s, e;
        Node* left;
        Node* right;
        Node* parent;
        Node(int x) : val(x), s(-1), e(-1), left(NULL), right(NULL), parent(NULL)  {}
    };
    
    int findSum(Node* node, int i, int j) {
        int start = node->s;
        int end = node->e;
        int mid = (start+end)/2;
        if (i == start && j == end) {
            return node->val;
        }
        
        int sum=0;
        if (start <= i && j <= end) {
            int left = (i <= mid) ? findSum(node->left, i, min(mid, j)) : 0;
            int right = (mid < j) ? findSum(node->right, max(mid+1, i), j) : 0;
            
            sum = left+right;
        }
        
        return sum;
    }
    
    vector<Node*> leefNodes;
    Node* head = NULL;
public:
    NumArray(vector<int> nums) {
        if (nums.size() == 0) {
            return;
        }
        
        leefNodes.resize(nums.size());
        head = new Node(0);
        
        head->s = 0;
        head->e = nums.size()-1;
        head->parent = NULL;
        
        queue<Node*> q;
        q.push(head);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            int start = temp->s;
            int end = temp->e;
            
            if (start == end) {
                leefNodes[end] = temp;
                update(start, nums[end]);
            } else {
                int mid = (start+end)/2;
                temp->left = new Node(0);
                temp->left->s = start;
                temp->left->e = mid;
                temp->left->parent = temp;
                
                temp->right = new Node(0);
                temp->right->s = mid+1;
                temp->right->e = end;
                temp->right->parent = temp;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        
    }
    
    void update(int i, int val) {
        if (leefNodes.size() == 0) {
            return;
        }
        
        leefNodes[i]->val = val;
        Node* itr = leefNodes[i]->parent;
        while (itr!=NULL) {
            int l_sum = itr->left? itr->left->val : 0;
            int r_sum = itr->right? itr->right->val : 0;
            itr->val = l_sum + r_sum;
            itr = itr->parent;
        }
    }
    
    int sumRange(int i, int j) {
        if (leefNodes.size() == 0) {
            return 0;
        }
        
        return findSum(head, i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
