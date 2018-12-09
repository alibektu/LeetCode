class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) {
      return 0;
    }
    int m = board[0].size();
    int count = 0;

    for (int i=0;i<n;i++) {
      int j=0;
      while (j<m) {
        while (j<m && board[i][j] == '.') {
          j++;
        }

        bool ship=false;
        while (j<m && board[i][j] == 'X') {
          if (!ship && i==0) {
            ship = true;
          } else if (!ship && i>0 && board[i-1][j] == '.') {
            ship = true;
          }
          j++;
        }

        count += ship;
      }
    }

    return count;
  }
};

