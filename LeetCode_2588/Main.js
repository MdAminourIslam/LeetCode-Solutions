var beautifulSubarrays = function(nums) {
    let count = new Map();
    count.set(0, 1);
    let xor = 0, subArray = 0;

    for (let num of nums) {
        xor ^= num;
        subArray += count.get(xor) || 0;
        count.set(xor, (count.get(xor) || 0) + 1);
    }

    return subArray;
};
