#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int totalSize = nums.size();

        vector<long long> leftSum(totalSize, 0);
        priority_queue<int> maxHeap;
        long long sum = 0;

        // Left side: minimal sum of n numbers up to index i
        for (int i = 0; i < totalSize; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (i >= n - 1) {
                leftSum[i] = sum;
            }
        }

        vector<long long> rightSum(totalSize, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;

        // Right side: maximal sum of n numbers starting from index i
        for (int i = totalSize - 1; i >= 0; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (i <= 2 * n) {
                rightSum[i] = sum;
            }
        }

        long long answer = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            answer = min(answer, leftSum[i] - rightSum[i + 1]);
        }
        return answer;
    }
};