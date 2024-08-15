let arr2 = [5,10];
console.log(arr2.shift());

arr2[4] = 55;
console.log(arr2);

// Using the constructor
let arr3 = new Array("Hello", 5);
console.log(arr3);

// The join function
var myArray = ["Red", "Green", "Blue", "Yellow"];
console.log( myArray );  // ["Red", "Green", "Blue", "Yellow"]
 
console.log( myArray.join()    ); // "Red,Green,Blue,Yellow", pass nothing it will take in the comma
console.log( myArray.join(' ') ); // "Green Blue Yellow"
console.log( myArray.join("&") ); // "Red&Green&Blue&Yellow"

// The reverse function
var myArray = ["Red", "Green", "Blue", "Yellow"];
console.log( myArray );  // [ "Red", "Green", "Blue", "Yellow" ]          

myArray = myArray.reverse();
console.log( myArray );  // [ "Yellow", "Blue", "Green", "Red" ]

// The sort object-- it will sort based on the ASCII code
var array1 = ["Red", 2, "Green", "15", "Blue", 101, "Yellow"];
var array2 = [99, 2, 38, 15, 66, 101, 200];

console.log( array1.sort() );  // [101, "15", 2, "Blue", "Green", "Red", "Yellow"]
console.log( array2.sort() );  // [101, 15, 2, 200, 38, 66, 99]

// The slice function gets a subarray from the original array
// Syntax:  
// arrayName.slice(index1, index2)
// Index2: not included

var colors = ["Red", "Green", "Blue", "Yellow", "White"];
var subclrs   = colors.slice(1, 3)

console.log( colors );   // [ "Red", "Green", "Blue", "Yellow", "White" ]
console.log( subclrs );  // [ "Green", "Blue" ]

// LOOP through an array
console.log("-------------------------------");
let arr = [4,6,2];
for(let i =0; i<arr.length; i++)
    {
        console.log(`arr[${i}]=${arr[i]}`);
    }

function print(e) {
    console.log(e);
}
//print(5);

// The use of forEach function
arr.forEach(print);
console.log("-------------------------------");
arr.forEach((e) => console.log(e))
console.log("-------------------------------");
function multiplyby5(e) {
    return e*=5;
}
//console.log(multiplyby5(8));

// The use of map function
let arr4= arr.map(multiplyby5);
console.log(arr4);

console.log("-------------------------------");
arr = [5,7,2,9,8];
for (let i =0; i<arr.length;i++) {
    if (arr[i]%2 == 0) {
        console.log(arr[i]); // Prints 2
        break;
    }
}

console.log("-------------------------------");
arr = [5,7,2,9,8];
function isEven(e) {
    return e%2 == 0;
}
// function isOdd(e) {
//     return e%2 != 0;
// }
console.log(arr.find(isEven)); // prints 2

console.log("-------------------------------");
console.log(arr.filter(e=>e%2 == 0));
