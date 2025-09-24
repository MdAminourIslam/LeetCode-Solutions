<?php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function sumOfUnique($nums) {
        $cnt = [];
        for ($i = 1; $i <= 100; $i++) {
            $cnt[$i] =  0; 
        }

        foreach ($nums as $num) {
            $cnt[$num]++;
        }

        $sum = 0;
        for ($i = 1; $i <= 100; $i++) {
            if ($cnt[$i] === 1) {
                $sum += $i;
            }
        }

        return $sum;
    }
}
?>
