/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let mx = neededTime[0], sum = neededTime[0], answer = 0;
    
    for (let i = 1; i < colors.length; i++) {
        if (colors[i] == colors[i - 1]) {
            mx = Math.max(mx, neededTime[i]);
            sum += neededTime[i];
        } else {
            answer += sum - mx;
            sum = mx = neededTime[i];
        }
    }

    answer += sum - mx;
    return answer;
};