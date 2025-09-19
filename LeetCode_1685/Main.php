<?php

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function getSumAbsoluteDifferences($nums) {
        $n = count($nums);

        $prefix = [];
        array_push($prefix, $nums[0]);
        for ($i = 1; $i < $n; $i++) {
            array_push($prefix, $prefix[$i - 1] + $nums[$i]);
        }

        $answer = [];

        for ($i = 0; $i < $n; $i++) {
            if ($i == 0) {
                $answer[$i] = $prefix[$n - 1] - $prefix[$i] - $nums[$i] * ($n - 1);
            } else if ($i + 1 == $n) {
                $answer[$i] = $nums[$i] * ($n - 1) - $prefix[$i - 1];
            } else {
                $answer[$i] = $nums[$i] * $i - $prefix[$i - 1] + $prefix[$n - 1] - $prefix[$i] - $nums[$i] * ($n - $i - 1);
            }
        }

    }
}

?>