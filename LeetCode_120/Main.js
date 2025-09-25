/**
 * @param {number[][]} triangle
 * @return {number}
 */

const dfs = function(i, j, triangle, dp, n, inf) {
    if (i === n - 1) {
        return triangle[i][j]; 
    }
    if (dp[i][j] !== inf) {
        return dp[i][j];
    }
    const choice1 = dfs(i + 1, j, triangle, dp, n, inf);
    const choice2 = dfs(i + 1, j + 1, triangle, dp, n, inf);

    return dp[i][j] = triangle[i][j] + Math.min(choice1, choice2);
}

var minimumTotal = function(triangle) {
    const n = triangle.length;
    const inf = 1e9;
    
    const dp = Array.from({ length: n }, () => Array(n).fill(inf));

    return dfs(0, 0, triangle, dp, n, inf);
};

console.log(minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]));
console.log(minimumTotal([[-10]]));
