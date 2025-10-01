class Calculator {
    
    /** 
     * @param {number} value
     */
    constructor(value) {
        this.value = value;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.value += value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.value -= value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.value *= value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if (value === 0) {
            throw new Error("Division by zero is not allowed");
        }
        this.value /= value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.value **= value;
        return this;
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.value;
    }
}



try {
    const ans1 = new Calculator(10).add(5).subtract(7).getResult(); // 10 + 5 - 7 = 8
    console.log(ans1);
    
    const ans2 = new Calculator(2).multiply(5).power(2).getResult(); // (2 * 5) ^ 2 = 100
    console.log(ans2);
    
    const ans3 = new Calculator(20).divide(0).getResult(); // 20 / 0
    console.log(ans3);
} catch(err) {
    console.log(err.message);
}
