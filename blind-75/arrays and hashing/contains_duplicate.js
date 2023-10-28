// problem: https://leetcode.com/problems/contains-duplicate/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  if (nums.length === 1) return false;

  const myMap = new Map();
  for (let n of nums) {
    if (!myMap.get(n)) {
      myMap.set(n, 1);
    } else {
      return true;
    }
  }
  return false;
};
