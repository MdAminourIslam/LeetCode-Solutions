class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int mn = 0, mx = 0;

        for (int i = 0; i < moves.length(); i++) {
            char ch = moves.charAt(i);
            
            if (ch == 'L') {
                mn -= 1;
                mx -= 1;
            } else if (ch == 'R') {
                mn += 1;
                mx += 1;
            } else {
                mn -= 1;
                mx += 1;
            }
        }

        return Math.max(Math.abs(mn), Math.abs(mx));
    }
}