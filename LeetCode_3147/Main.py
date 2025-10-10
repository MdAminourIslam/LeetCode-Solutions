class Solution(object):
    def maximumEnergy(self, energy, k):
        """
        :type energy: List[int]
        :type k: int
        :rtype: int
        """
        n = len(energy)
        answer = energy[n - 1]

        for i in range(n - 1, n - k - 1, -1):
            sum = 0
            j = i
            while j >= 0:
                sum += energy[j]
                answer = max(answer, sum)
                j -= k
        return answer