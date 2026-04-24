public class Solution {
    public int FurthestDistanceFromOrigin(string moves) {
        int mn = 0, mx = 0;
        
        foreach (char ch in moves) {
            if (ch == 'L') {
                mn -= 1;
                mx -= 1;
            } 
            else if (ch == 'R') {
                mn += 1;
                mx += 1;
            } 
            else {
                mn -= 1;
                mx += 1;
            }
        }
        
        return Math.Max(Math.Abs(mn), Math.Abs(mx));
    }
}
