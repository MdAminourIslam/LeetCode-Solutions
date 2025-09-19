import java.util.ArrayList;

class Solution {
    public int helper(String s, int x, int y) {
        int cnt_a = 0;
        int cnt_b = 0;
        int ab = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'a') {
                cnt_a += 1;
            } else {
                if (cnt_a > 0) {
                    ab += 1;
                    cnt_a -= 1;
                } else {
                    cnt_b += 1;
                }
            }
        }
        int ans1 = (ab * x) + Math.min(cnt_a, cnt_b) * y;

        cnt_a = cnt_b = 0;
        int ba = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'a') {
                if (cnt_b > 0) {
                    ba += 1;
                    cnt_b -= 1;
                } else {
                    cnt_a += 1;
                }
            } else {
                cnt_b += 1;
            }
        }
        int ans2 = (ba * y) + Math.min(cnt_a, cnt_b) * x;
        return Math.max(ans1, ans2);
    }
    public int maximumGain(String s, int x, int y) {
        ArrayList<String> str = new ArrayList<>();
        StringBuilder cur = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'b') {
                cur.append(s.charAt(i));
            } else {
                str.add(cur.toString());
                cur.setLength(0);
                //cur = cur.delete(0, cur.length() - 1);
            }
        }
        if (!cur.isEmpty()) {
            str.add(cur.toString());
        }
        int ans = 0;
        for (int i = 0; i < str.size(); i++) {
            ans += helper(str.get(i) , x, y);
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}