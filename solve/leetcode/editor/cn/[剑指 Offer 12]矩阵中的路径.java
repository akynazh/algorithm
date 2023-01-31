//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
//
// Related Topics 数组 回溯 矩阵 👍 724 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)
