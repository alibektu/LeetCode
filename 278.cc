// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        while (r>l) {
            int mid = (l+r) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = (l+r+1)/2;
            }
        }
        
        return (l+r)/2;
    }
};
