class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
        int k=primes.size();
        heap.push(1);
        int max_int = 2147483647;
        
        int ith=-1;
        for (int i=0; i<n; i++) {
            int top = heap.top();heap.pop();
            if (ith == top) {
                i--;
                continue;
            }
            ith = top;
            // cout<<ith<<endl;
            for (int j=0; j<k; j++) {
                if (ith <= (max_int/primes[j]) -1)
                    heap.push(ith*primes[j]);
            }
        }
        
        return ith;
    }
};
