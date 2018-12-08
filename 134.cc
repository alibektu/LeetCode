class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int max_index = -1, index = -1;
        int sum = 0, total = 0, max_sum=0;
        for (int i=0;i<len*2;i++) {
            int diff = gas[i%len]-cost[i%len];

            total += i < len ? diff : 0;
            sum += diff;

            if (index == i%len && i>=len) {
                break;
            }

            if (sum < 0) {
                sum = 0;
                index = i;
            }

            if (max_sum < sum) {
                max_sum = sum;
                max_index = index;
            }
        }

        if (total < 0) {
            return -1;
        }

        return max_index+1;
    }
};
