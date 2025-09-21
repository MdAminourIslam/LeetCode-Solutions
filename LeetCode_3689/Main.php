<?php

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function maxTotalValue($nums, $k) {
        $mx = max($nums);
        $mn = min($nums);
        return ($mx - $mn) * $k;
    }
}

?>