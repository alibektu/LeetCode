class Solution {
private:
  vector<vector<bool>> vis;
  vector<vector<char>>* _grid;
  int n, m;
  int count = 0;

  void travers(vector<vector<char>> &grid, int i, int j) {
    vis[i][j] = 1;
    if (i+1 < n && !vis[i+1][j] && grid[i+1][j] != '0') {
      travers(grid, i+1, j);
    }
    if (i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] != '0') {
      travers(grid, i-1, j);
    }

    if (j+1 < m && !vis[i][j+1] && grid[i][j+1] != '0') {
      travers(grid, i, j+1);
    }
    if (j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] != '0') {
      travers(grid, i, j-1);
    }
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    if (n==0) {
      return 0;
    }
    _grid = &grid;

    m = grid[0].size();
    vis.resize(n);
    for (int i=0;i<n;i++) vis[i].resize(m);

    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (!vis[i][j] && grid[i][j] == '1') {
          travers(grid,i,j);
          count++;
        }
      }
    }

    return count;
  }
};
