// Return a curried version of a function i.e., sum(a + b) --> sum(a)(b)

// https://leetcode.com/problems/curry/description/ 

var curry = function(fn) {
    return function curried(...args) {
        if(args.length >= fn.length) {
            return fn(...args);
        } else {
            return function (...next) {
                return curried(...args, ...next);
            }
        }
    };
};