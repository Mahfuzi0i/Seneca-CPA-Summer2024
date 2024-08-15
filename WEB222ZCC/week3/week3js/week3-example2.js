// Regular Expression objects
// The expressions work like the OPS102 regular expressions

var str1 = "Welcome to Toronto";

var reg1 = /to/;
console.log(reg1.test(str1)); // will return a boolean value. tests to see if the to is present in the string

var reg2 = /TO/;
console.log(reg2.test(str1));

var reg3 = /TO/i;
console.log(reg3.test(str1));

var reg4 = /^Toronto/;
console.log(reg4.test(str1));

var reg5 = /Toronto$/;
console.log(reg5.test(str1));
