class Solution {
    public char kthCharacter(int k) {
        StringBuilder cur = new StringBuilder("a");

        while (cur.length() < k) {
            StringBuilder temp = new StringBuilder();

            for (int i = 0; i < cur.length(); i++) {
                int d = cur.charAt(i) - 'a';
                d = (d + 1) % 26;
                temp.append((char) (d + 'a'));
            }

            cur.append(temp);
        }

        return cur.charAt(k - 1);
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
