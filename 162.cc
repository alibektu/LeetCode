class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() -1;
        
        if (r == 0) {
            return 0; 
        }else if (r==1) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        
        while (r-l > 1) {
            int mid= (l+r)/2;
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid;
            }
            cout<<l<<" "<<r<<endl;
        }
        
        return nums[l] > nums[r]? l : r;
    }
};
