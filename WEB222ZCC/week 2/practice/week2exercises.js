/**
 * This week is all about functions. There are 2 types of functions.
 * 1. User-defined functions
 * 2. Global functions.
 * there are 3 methods of functions definitions
 * 1. function declaration
 * 2. function expression
 * 3. arrow function
 */
//function declarion
function square(n) {
    return n*n;
}
console.log("This is how you do function declarion-", square(10));
console.log();

//function expression
let sq = function all(name) {
    console.log("this function prints", name);
}
sq("Mahfuz");
sq("MUath AlZghOOl");
console.log();

//arrow expression
let add = (a,b,c) => a+b+c;
console.log("The arrow expression--", add(10,5,5));
console.log("");
//lets try to master arrow expressions
let root = (b) => Math.sqrt(b);
console.log("The square root is-", root(25),"\n");

let C = (c) => c*(9/5) + 32;
console.log("the temps in F is-", C(23),"\n");