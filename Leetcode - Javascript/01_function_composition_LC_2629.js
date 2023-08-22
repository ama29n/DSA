/*
 * @param {Function[]} functions
 * @return {Function}
 */

// https://leetcode.com/problems/function-composition 

var compose = function(arr) {
	return function(x) {
        for(let i = arr.length - 1; i >= 0; i--) {
            x = arr[i](x);
        }
        return x;
    }
};

var compose = function(arr) {
	return function(x) {
        return arr.reduceRight((acc, fn) => {
            return fn(acc);
        }, x)
    }
};

/*
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */