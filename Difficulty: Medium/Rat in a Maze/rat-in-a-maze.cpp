class Solution {
  public:

    void solve(int i, int j, vector<vector<int>>& maze,
               string temp, vector<string>& ans) {

        int n = maze.size();

        // destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(temp);
            return;
        }
        maze[i][j] = 0;

        vector<char> dir = {'D','L','R','U'};
        vector<int> row = {1, 0, 0, -1};
        vector<int> col = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nRow = i + row[k];
            int nCol = j + col[k];

            if (nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < n &&
                maze[nRow][nCol] == 1) {

                solve(nRow, nCol, maze, temp + dir[k], ans);
            }
        }

        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        if (maze[0][0] == 0) return ans;

        solve(0, 0, maze, "", ans);
        return ans;
    }
};
