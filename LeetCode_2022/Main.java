
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int len = original.length;
        if (len != n * m) {
            return new int[][]{};
        }

        int[][] grid = new int[m][n];
        for (int row = 0, i = 0; i < len; i++) {
            if (i > 0 && i % n == 0) {
                row += 1;
            }
            int col = i % n;
            grid[row][col] = original[i];
        }
        return grid;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}