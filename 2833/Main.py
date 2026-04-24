class Solution:
    def furthestDistanceFromOrigin(self, moves):
        mn = 0
        mx = 0
        for ch in moves:
            if ch == 'L':
                mn -= 1
                mx -= 1
            elif ch == 'R':
                mn += 1
                mx += 1
            else:
                mn -= 1
                mx += 1
        
        return max(abs(mn), abs(mx))
