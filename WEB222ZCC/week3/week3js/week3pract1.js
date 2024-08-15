var str1 = "Hello, and welcome to Toronto";
var str2 = " I am Abdullah";

console.log(str1.length); // will print 29
console.log(str1.charAt(11)); //will print w
console.log(str1.concat(str2)); // Will add both the strings together
console.log(str1.split(',')); // will print [ 'Hello', ' and welcome to Toronto' ]
console.log(str1.split('')); // will print [
                                    //     'H', 'e', 'l', 'l', 'o', ',',
                                    //     ' ', 'a', 'n', 'd', ' ', 'w',
                                    //     'e', 'l', 'c', 'o', 'm', 'e',
                                    //     ' ', 't', 'o', ' ', 'T', 'o',
                                    //     'r', 'o', 'n', 't', 'o'
                                       //   ]
console.log(str1.substring(11,18)); // 11- w and 17- e (11 - 18 means from 11th index to 18th index, excluding the 18th)
// the uppercase and lowercase convertion
console.log(str1.toUpperCase()); // it creates a copy and makes changes to that copy only, leaving the original unmodified
console.log(str2.toLowerCase());
console.log(str1);

// create letto from the strings
let letto = str1.charAt(2) + str1.charAt(1) + str1.charAt(19) + str1.substring(19,21);
console.log(letto);

let str = "       Hello, I got too much unncessary spaces              ";
console.log(str.trim());

// the Regular expression
console.log(`--------------REGULAR EXPRESSIONS beyond this point ------------------`);
let str4 = "I will test pattern over here";
let regEx = /test/;
console.log(regEx.test(str4));

let regEx1 = /PATTERN/i; // i turns off the case sensitivity of java script
console.log(regEx1.test(str4));

console.log(/hello/.test("i am not here")); // the raw format

// declaring string using constructor and literal
let str5 = "put me through"; // literal string declaration
let str6 = new String("I am the original way"); // using the constructor
console.log(str5);
console.log(str6); // retains the same properties as a normal string would

// string method - split(RegEx) expression
var str7 = "School of ICT-Seneca College";
console.log(str7.split('-'));
console.log(str7.split(/-/));
console.log(str7.split(/[ -]/))

// string method search return -1 if the match isn't found
var str8 = "No mAtch founD";
console.log(str8.search(/no/));

