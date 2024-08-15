// String objects
var str1 = "Welcome to Toronto";
var str2 = 'Abdullah';
var str3 = `Hello ${str2}`;

var str4 = new String("See you!"); // Original way to declare string, String is the constructor
               // S capital, be careful
console.log(str3);
console.log(str1.length); // The length of str1 variable


console.log(str1.charAt(5)); // check the character at any position usinf a property
console.log(str1[5]); // same thing using shotcuts
console.log(str1.charCodeAt(5)); // the ASCII code for the value in 5th position of str1

var str5 = "HELLO ".concat("Sam"); // using concat function to concaanation
console.log(str5);

console.log("Hello ".concat("Sam ").concat("and Tom.")); // concatanating multiple strings
console.log("Hello ".concat("sAM", " TOM")); // Another way to use these

str1 = "Welcome to Toronto";
console.log(str1.indexOf('to')); // will return the index position from where the string was found
console.log(str1.lastIndexOf('To'));
console.log(str1.indexOf('TO')); // return -1 to tell you that the string doesn't exist
console.log(str1.lastIndexOf('to')); // will return the index position of the last occuracnce of the given string

var words = str1.split(' ');
console.log(words);  // creates an array to hold the words

var chars = str1.split('');
console.log(chars);

var arr = str1.split('to');
console.log(arr);

// To extract a substring from a string- use substring
console.log(str1.substring(3,6));  // 3 to 6. but not including the 6th element
console.log(str1.substring(3));  // starting from 3 to all the way to the end

console.log(str1.substr(3,6));

//convert a string to capital letter use toUpperCase
console.log(str1.toUpperCase()); // creates a new string where the str1 is all uppercase letter
console.log(str1.toLowerCase()); // creates a new string where the str1 is all lowercase letter

var str6 = "     Hello Mauth   "; // if you want to remove the whitespaces before and after
console.log(str6.trim());  // will create a new string where the strings whitespaces before and after are removed
console.log(str6);  // str6 remains unchanged

console.log(str6.trim().toUpperCase(). charAt(0));  // H

String.prototype.greeting = function() {
    return "Hello " +this; // this keyword is for the current string that is being passed
};

str2 = 'Abdullah';
console.log(str2.greeting());
console.log("XXXX".greeting());

String.prototype.reverse = function() {
    var rev = '';
    for (var i = this.length - 1; i>=0; i--) {
        rev += this[i];
    }
    return rev; // this keyword is for the current string that is being passed
};
console.log(str1.reverse());