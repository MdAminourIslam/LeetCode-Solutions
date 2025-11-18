public class Solution {
    public bool IsOneBitCharacter(int[] bits) {
        int n = bits.Length - 1;
        int indx = 0;

        while (indx < n) {
            if (indx + 1 < n) {
                if (bits[indx] == 0)
                    indx += 1;
                else
                    indx += 2;
            } else {
                if (bits[indx] == 1)
                    return false;
                else
                    return true;
            }
                
        }
        return true;
    }
}