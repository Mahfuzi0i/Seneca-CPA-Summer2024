/**
 * The parseFloat() function parses a string (from left to right) and
 * returns a floating point number. If a character can not
 * be converted converted to a number, the function returns 
 * the value up to that point (from left to right). 
 * If the character is a string that can not be converted to
 * a number, the function returns NaN. The function Trim the
 * string before passing
 */
//converting string "" into a number
console.log(parseFloat("15.25"));
let a = 20.55;
console.log(parseFloat(a));

console.log(parseFloat("0.000000000000045"))
console.log(parseFloat("6.7E-15"));
console.log(parseFloat("1 2 3"));
console.log(parseFloat("0.34#445"));
console.log(parseFloat("x456"));

//using parseInt() function to convert string in to a number
console.log(parseInt('17',8));
console.log(parseInt('18.99'));

//using Number() function to convert string into numbers
console.log(Number("12345"));
console.log(Number("1324 549990 9848"));
console.log(Number("1232esx"));
console.log(Number("34#2"));

//using String() function to convert numbers into strings
console.log(String(1243));
let b = 4565;
console.log("After string conversion",(String(b)));
console.log(typeof(b));

//the boolean operators isNaN() function
//print the boolen value for the condition isNaN()
console.log(isNaN("1234"));
console.log(isNaN("1w3"));
console.log(isNaN(65));
console.log(isNaN("+1234"));
console.log(isNaN("12+32"));
console.log(isNaN("-1234"));

//lets see if there is an infinity boolean 
console.log(isFinite(12));
console.log(isFinite(Infinity));
console.log(isFinite(1/0));
console.log(isFinite("hello"));