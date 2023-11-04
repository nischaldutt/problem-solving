// problem: https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const myMap = new Map();
  const len = nums.length;

  for (let i = 0; i < len; i++) {
    const currentValue = nums[i];
    const neededValue = target - currentValue;

    if (myMap.get(neededValue) === undefined) {
      myMap.set(currentValue, i);
    } else {
      return [myMap.get(neededValue), i];
    }
  }

  return [];
};
