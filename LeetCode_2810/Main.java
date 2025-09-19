

class Solution {
    public String finalString(String s) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'i') {
                res.reverse();
            } else {
                res.append(ch);
            }
        }
        return res.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
