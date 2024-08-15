// The most important thing about the functions is that they 
// NEVER modify the original value!!
// it creates a copy of the original, modifies that based on its instructions and prints that

// length is a property of javascript
let a = "My name is Abdullah";
console.log(a.length);
// we can also specify the index position from a string
console.log(a.charAt(3)); // The character at 3rd position 
console.log(a.charAt(11)); // The character at 11th position
// we can concatinate 2 stings (using the concat() function)
let b = " I like ";
let c = "fishing*";
console.log(a.concat(b,c));
// We use index of function to detect where a certain character from a string is
let d = "Oxygen";
console.log(d.indexOf("3")); // will return -1 if the string doesn't exist
console.log(d.indexOf('y')); // will return the index of y, which is 2
// Lets use split function
console.log(d.split(`y`)); // split it by "y". it will take y, remove it and create an array to hold the separated values
console.log(d.split(' ')); // Will just take the whole word and put it inside the array
console.log(d.split(''));

// We can use functions to convert lowercase letters to uppercase and vice versa
let e = "i was lowercase";
console.log("before using the function to uppercase- ", e);
console.log("after using uppercase function- ", e.toUpperCase());
console.log("after using lowercase function- ", e.toLowerCase());

console.log("Why am i such a loser");
let f = "    hello, my name   is abdullah    ";
console.log(f.trim());
console.log(10*"hello");
console.log(isNaN(10*`hello`));

let str1 = "My summer courses are: ";
let str2 = "OOP244ZFF";
let str3 = "EAC234NBB";
let str4 = "SFT221ZCC";
let str5 = "DBS221ZCC";
let str6 = "WEB222ZDD";

console.log(str1.concat(str2,",",str3,",",str4,",",str5,",",str6));

// The substring function to return a certain part of the main string
let g = "Absolutely";
console.log(g.substring(1,4));
console.log(g.charAt(2) + g.substring(4,7));

let h = "why are you crying?";
console.log("The original string-", h);
console.log("I have modified it to say__");
console.log(h.substring(0,2)+h.charAt(9)+h.substring(5,7));

// the original string declaration using the constructor
let x = new String("\nI am the original way to String");
console.log(x.substring(0,8));

///////Another recap
/**
 * There are essentially 2 types of string declaration
 * 1. Literal string i.e. let x = "Hello";
 * 2. Constructor string i.e. let y = new String("hello");
 * When we use the literal string , the compiler converts it to the constructor and then proceeds as string
 */

let i = "Hello";
console.log(i.charAt(0)); // To find a character at specific index
console.log(i.length);
console.log(i.indexOf("o"));
