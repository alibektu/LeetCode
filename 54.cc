class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> result;

      int n = matrix.size();
      if (n==0) {
        return result;
      }
      int m = matrix[0].size();

      int l = 0, r = m-1;
      int t = 0, b = n-1;
      while (result.size() != n*m) {
        for (int i=l;i<=r;i++) {
          result.push_back(matrix[t][i]);
        }

        for (int i=t+1;i<=b;i++) {
          result.push_back(matrix[i][r]);
        }

        for (int i=r-1; t!=b && i>=l;i--) {
          result.push_back(matrix[b][i]);
        }

        for (int i=b-1; l!=r && i>t;i--) {
          result.push_back(matrix[i][l]);
        }

        l++, r--;
        t++, b--;
      }

      return result;
    }
};
