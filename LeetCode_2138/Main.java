package LeetCode_2138;

class Solution {
    public String[] divideString(String s, int k, char fill) {
        //ArrayList<String> res = new ArrayList<>();
        String cur = "";
        int n = s.length();

        int res_size = (n + k - 1) / k, indx = 0;

        String[] res = new String[res_size];

        for (int i = 0; i < s.length(); i++) {
            cur += s.charAt(i);

            if (cur.length() == k) {
                res[indx++] = cur;
                cur = "";
            }
        }

        while (cur.length() > 0 && cur.length() < k) {
            cur += fill;
        }

        if (cur.length() == k) {
            res[indx++] = cur;
        }
        return res;
    }
}

public class Main {
    
}
