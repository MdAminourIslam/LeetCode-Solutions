import java.util.*;

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0, j = 0;

        for (int i = 0; i < fruits.length; i++) {
            count.put(fruits[i], count.getOrDefault(fruits[i], 0) + 1);

            while (count.size() > 2) {
                count.put(fruits[j], count.get(fruits[j]) - 1);
                if (count.get(fruits[j]) == 0) {
                    count.remove(fruits[j]);
                }
                j++;
            }

            ans = Math.max(ans, i - j + 1);
        }

        return ans;
    }
}

public class Main {

    public static void main(String[] args) {
        
    }
}
