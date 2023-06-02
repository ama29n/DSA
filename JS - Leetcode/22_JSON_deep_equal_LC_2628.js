// https://leetcode.com/problems/json-deep-equal/description/ 

var areDeeplyEqual = function(o1, o2) {
    if(o1 === o2) {
        return true;
    }
    if(o1 === null && o2 === null) {
        return true;
    }
    if(o1 === null || o2 === null) {
        return false;
    }
    if(Array.isArray(o1) || Array.isArray(o2)) {
        if(!Array.isArray(o1) || !Array.isArray(o2)) {
            return false;
        }
        if(o1.length !== o2.length) {
            return false;
        }
        for(let i = 0; i < o2.length; i++) {
            if(!areDeeplyEqual(o1[i], o2[i])) {
                return false;
            }
        }
        return true;
    }
    if(typeof o1 === "object" || typeof o2 === "object") {
        if(typeof o1 !== "object" || typeof o2 !== "object") {
            return false;
        }
        if(Object.keys(o1).length !== Object.keys(o2).length) {
            return false;
        }
        for(const key in o1) {
            if(!areDeeplyEqual(o1[key], o2[key])){
                return false;
            }
        }
        return true;
    }
    return false;
};