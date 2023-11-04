// problem: https://leetcode.com/problems/valid-anagram/

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  const slen = s.length;
  const tlen = t.length;
  if (slen !== tlen) return false;

  const myMap = new Map();
  for (let i = 0; i < slen; i++) {
    if (!myMap.get(s[i])) {
      myMap.set(s[i], 1);
    } else {
      const count = myMap.get(s[i]);
      myMap.set(s[i], count + 1);
    }
  }

  for (let i = 0; i < tlen; i++) {
    if (!myMap.get(t[i])) return false;
    else {
      if (myMap.get(t[i]) === 0) {
        return false;
      } else {
        const count = myMap.get(t[i]);
        myMap.set(t[i], count - 1);
      }
    }
  }
  return true;
};
