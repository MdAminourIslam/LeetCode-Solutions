/**
 * @param {number} k
 */
var MyCircularDeque = function(k) {
    this.len = k;         
    this.nums = [];      
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function(value) {
    if (this.nums.length < this.len) {
        this.nums.unshift(value);
        return true;
    }
    return false;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function(value) {
    if (this.nums.length < this.len) {
        this.nums.push(value);
        return true;
    }
    return false;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteFront = function() {
    if (this.nums.length > 0) {
        this.nums.shift();
        return true;
    }
    return false;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteLast = function() {
    if (this.nums.length > 0) {
        this.nums.pop();
        return true;
    }
    return false;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getFront = function() {
    if (this.nums.length === 0) return -1;
    return this.nums[0];
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getRear = function() {
    if (this.nums.length === 0) return -1;
    return this.nums[this.nums.length - 1];
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isEmpty = function() {
    return this.nums.length === 0;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isFull = function() {
    return this.nums.length === this.len;
};


/** 
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */