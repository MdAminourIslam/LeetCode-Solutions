class Solution {
    public String makeFancyString(String s) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (res.length() < 2) {
                res.append(s.charAt(i));
            } else {
                int sz = res.length();
                if (res.charAt(sz - 1) == res.charAt(sz - 2) && res.charAt(sz - 1) == s.charAt(i)) {
                    continue;
                } else {
                    res.append(s.charAt(i));
                }
            }
        }
        return res.toString();
    }
}