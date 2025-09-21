<?php

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function evenNumberBitwiseORs($nums) {
        $answer = 0;
        foreach ($nums as $num) {
            $answer = ($num & 1 ? $answer : $answer | $num);
        }
        return $answer;
    }
}


?>