public class Solution {
    public int MaxSumDivThree(int[] nums) {
        int tot = 0;
        List<int> b = new List<int>();
        List<int> c = new List<int>();

        foreach (int x in nums) {
            tot += x;
            if (x % 3 == 1) b.Add(x);
            else if (x % 3 == 2) c.Add(x);
        }

        b.Sort();
        c.Sort();

        if (tot % 3 == 0) return tot;

        if (tot % 3 == 1) {
            int op1 = b.Count > 0 ? tot - b[0] : 0;
            int op2 = c.Count > 1 ? tot - c[0] - c[1] : 0;
            return Math.Max(op1, op2);
        }
        else {
            int op1 = b.Count > 1 ? tot - b[0] - b[1] : 0;
            int op2 = c.Count > 0 ? tot - c[0] : 0;
            return Math.Max(op1, op2);
        }
    }
}
