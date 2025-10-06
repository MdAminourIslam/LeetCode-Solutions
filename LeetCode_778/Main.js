//Brute force Approach
//TC: O(n * n * n * n) = O(n ^ 4)

/**
 * @param {number[][]} grid
 * @return {number}
 */
var swimInWater = function(grid) {
    let n = grid.length;
    let answer = -1;
    function dfs(i, j, visited, value) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > value) {
            return;
        }
        if (i + 1 == n && j + 1 == n) {
            answer = value;
            return;
        }
        visited[i][j] = 1;
        dfs(i + 1, j, visited, value);
        dfs(i - 1, j, visited, value);
        dfs(i, j + 1, visited, value);
        dfs(i, j - 1, visited, value);

    }
    let visited = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; ; i++) {
        visited = Array.from({ length: n }, () => Array(n).fill(0));
        dfs(0, 0, visited, i);

        if (answer != -1) {
            return i;
        }
    }
    return -1;
};


//Optimized Binary Search Version:
/**
 * @param {number[][]} grid
 * @return {number}
 */
var swimInWater = function(grid) {
    let n = grid.length;

    function canReach(mid) {
        if (grid[0][0] > mid) return false; 
        let visited = Array.from({ length: n }, () => Array(n).fill(0));
        function dfs(i, j) {
            if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid) {
                return;
            }
            visited[i][j] = 1;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        }
        dfs(0, 0);
        return visited[n - 1][n - 1] === 1; 
    }

    // Binary Search on answer
    let low = 0;
    let high = n * n - 1;
    let answer = high;

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (canReach(mid)) {
            answer = mid;     
            high = mid - 1;   
        } else {
            low = mid + 1;    
        }
    }
    return answer;
};
