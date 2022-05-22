/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
// BFS
class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    void bfs(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'O')
            return;
        board[x][y] = 'A'; // 把遍历到的'O'都变为'A'
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'O')
                {
                    q.push({nx, ny});
                    board[nx][ny] = 'A';
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = (int)board.size(), m = (int)board[0].size();
        // 类似于[1254]统计封闭岛屿的数目，从四个边界开始
        for (int i = 0; i < n; ++i)
        {
            bfs(board, i, 0); // 以左边界的'O'作为被解救的起点
            bfs(board, i, m - 1); // 以右边界的'O'作为被解救的起点
        }
        for (int j = 0; j < m; ++j)
        {
            bfs(board, 0, j); // 以上边界的'O'作为被解救的起点
            bfs(board, n - 1, j); // 以下边界的'O'作为被解救的起点
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O'; // 被解救成功，还原为'O'
                else if (board[i][j] == 'O') // 类似[1254]里的封闭岛屿，不与边界/外界联通
                    board[i][j] = 'X';
            }
        }

    }
};
// @lc code=end

