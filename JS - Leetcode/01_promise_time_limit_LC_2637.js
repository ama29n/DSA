// Task is to return a time limited version of an asynchronous function

// https://leetcode.com/problems/promise-time-limit/description/ 

var timeLimit = function(fn, time) {
	return async function(...args) {
        return new Promise((resolve, reject) => {
            setTimeout(() => reject("Time Limit Exceeded"), time);
            fn(...args).then(resolve).catch(reject);
        });
    }
};