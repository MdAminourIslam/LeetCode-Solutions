<?php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function triangleNumber($nums) {
        sort($nums);
        $n = count($nums);
        $result = 0;

        for ($k = $n - 1; $k >= 2; $k--) {
            $i = 0;
            $j = $k - 1;

            while ($i < $j) {
                if ($nums[$i] + $nums[$j] > $nums[$k]) {
                    $result += $j - $i; // all pairs (i..j-1, j, k) valid
                    $j--;
                } else {
                    $i++;
                }
            }
        }

        return $result;
    }
}

// Test
$sol = new Solution();
$nums = [48,66,61,46,94,75];
echo $sol->triangleNumber($nums); 
?>
