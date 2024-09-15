function myFunction(a, b, n) {
  if (a === 0) console.log(a);
  if (b === 1) console.log(b);

  let sum = a + b;
  if (sum !== 1) console.log(sum);
  if (n <= 0) return;
  else return myFunction(b, sum, --n);
}

myFunction(0, 1, 10);
