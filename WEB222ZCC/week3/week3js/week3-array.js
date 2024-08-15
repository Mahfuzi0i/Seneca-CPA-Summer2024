// It is recommended to use literal array declaration
let arr = [10, 20, 'Different', true, false, "can hold anything"];
console.log(arr);

// this is array declaration using constructor
let arr1 = new Array("this is not recommended", 10, 20, true, false);
console.log(arr1);

console.log(arr.pop()); // The pop() method removes an entry from the end of the array and returns the removed element.
console.log(arr);  // it modies the main array unlike the other string methods where it creates a copy of the string and leaves the original untouched

console.log("\n");
// lets try more elaborately
let arr2 = ['Red', "Green", "Blue", "Yellow", "Pink", "Magenta"];
console.log(`the original array ${arr2}`)
let first = arr2.shift(); // the shift function takes away the 1st entry of the array
let last = arr2.pop(); // The pop function takes away the last entry in the array
console.log(arr2); // after the modification
console.log(`the 1st element taken ${first}`);
console.log(`the last element taken ${last}`);

// use push() function to add new element at the end of the array
let newentry = arr2.push("Cyan");
console.log(`added new element using the push function-- ${arr2}`);

// using more of push function
let arr3 = ["Icon", "new", "cool", "Access"];
console.log("The original array--", arr3);
console.log("After the push function--");
additionalarr = arr3.push("NEW23", "WEB222");
console.log(arr3);

// using reverse array
let reverseArray = arr3.reverse();
console.log(reverseArray);
console.log(arr3);
console.log(arr3.reverse()); // reverse the reverse to get the original

let x = [11,'a', 15, 13, "blue", 24, 35.05];
console.log(x.sort());
console.log(x.pop());
console.log(x.shift());

