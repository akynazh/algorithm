class Solution {
    private char[][] board;
    private String word;
    private int m;
    private int n;
    private final boolean[][] visited = new boolean[6][6];
    private final int[] dx = {-1, 0, 0, 1};
    private final int[] dy = {0, -1, 1, 0};
    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.word = word;
        m = board.length;
        n = board[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    private boolean dfs(int x, int y, int idx) {
        if (board[x][y] != word.charAt(idx))
            return false;
        if (idx + 1 == word.length()) return true;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int xdx = x + dx[i], ydy = y + dy[i];
            if (xdx >= 0 && xdx < m && ydy >= 0 && ydy < n && !visited[xdx][ydy]) {
                if (dfs(xdx, ydy, idx + 1)) {
                    return true;
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
}

//runtime:102 ms
//memory:39.5 MB
