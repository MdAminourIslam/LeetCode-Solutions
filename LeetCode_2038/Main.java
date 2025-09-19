class Solution {
    public boolean winnerOfGame(String colors) {
        int alice = 0, bob = 0;
        int cnta = 0, cntb = 0;

        for (char color : colors.toCharArray()) {
            if (color == 'A') {
                cnta++;
                bob += Math.max(0, cntb - 2);
                cntb = 0;
            } else {
                cntb++;
                alice += Math.max(0, cnta - 2);
                cnta = 0;
            }
        }

        bob += Math.max(0, cntb - 2);
        alice += Math.max(0, cnta - 2);

        return alice > bob;
    }
}


public class Main {
    public static void main(String[] args) {
        
    }
}