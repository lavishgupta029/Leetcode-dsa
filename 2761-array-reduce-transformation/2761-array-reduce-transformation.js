/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let initVal=init;
    for(let i=0;i<nums.length;i++){
        initVal=fn(initVal, nums[i]);
    }
    return initVal;
};