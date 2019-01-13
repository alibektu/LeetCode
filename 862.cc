class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> p;
        p.resize(A.size()+1);
        int n = p.size();
        int min_len = n+1;
        for (int i=0;i<n-1;i++) {
            p[i+1] = p[i] + A[i];
        }

        deque<int> q;
        for (int i=0;i<n;i++) {
            p[i+1] = p[i] + A[i];
            while(!q.empty() && p[i] <= p[q.back()]) {
                q.pop_back();
            }
            
            while(!q.empty() && p[i] >= p[q.front()] + K) {
                min_len = min(min_len, i - q.front());
                q.pop_front();
            }

            q.push_back(i);
        }
        
        return min_len == n+1 ? -1 : min_len;
    }
};
