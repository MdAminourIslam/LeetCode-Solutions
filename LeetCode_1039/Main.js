/**
 * @param {number[]} values
 * @return {number}
 */
var minScoreTriangulation = function(values) {
    let n = values.length;
    const dp = Array.from( {length: n}, function() {
        return Array(n).fill(-1);
    });

    const dfs = (i, j) => {
        if (j - i < 2) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }

        let minimum = Number.MAX_VALUE;
        for (let k = i + 1; k < j; k++) {
            minimum = Math.min(minimum, values[i] * values[k] * values[j] + dfs(i, k) + dfs(k, j));
        }
        dp[i][j] = minimum;
        return dp[i][j];
    };
    return dfs(0, n - 1);
};
console.log(minScoreTriangulation([1, 2, 3]));
console.log(minScoreTriangulation([3,7,4,5]));
console.log(minScoreTriangulation([1,3,1,4,1,5]));
