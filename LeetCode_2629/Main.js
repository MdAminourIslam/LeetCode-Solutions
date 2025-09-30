/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    const fun = functions;

    return function(x) {
        for (let i = fun.length - 1; i >= 0; i--) {
            x = fun[i](x);
        }
        return x;
    };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */