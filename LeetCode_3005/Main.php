<?php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxFrequencyElements($nums) {
        $cnt = [];
        foreach($nums as $num) {
            $cnt[$num] += 1;
        }
        $mx = max($cnt);
        $sum = 0;
        foreach($cnt as $c) {
            if ($c == $mx) {
                $sum += $mx;
            }
        }
        return $sum;
    }
}
?>