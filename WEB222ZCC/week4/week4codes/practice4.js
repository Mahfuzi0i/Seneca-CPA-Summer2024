function addDollars(number) {
  return number.map((e) => "$" + e);
}

console.log(addDollars([1, 2, 3, 4, 5]));

// using arrow expression
const addDollars2 = (number) => number.map((f) => "$" + f);
console.log(addDollars([1, 2, 3, 4, 5]));
