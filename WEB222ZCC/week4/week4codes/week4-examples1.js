// Date Object
// Create ddate object with a specific date and time.
var date1 = new Date(1996, 6, 6);
var date2 = new Date(2001, 4, 10, 11, 13, 15, 0);
var date3 = new Date("Sept 12, 2017");
console.log(date1 + "\n" + date2 + "\n" + date3);

//////////////////The OUTPUT////////////////////////////
// Sat Jul 06 1996 00:00:00 GMT-0400 (Eastern Daylight Saving Time)
// Thu May 10 2001 11:13:15 GMT-0400 (Eastern Daylight Saving Time)
// Tue Sep 12 2017 00:00:00 GMT-0400 (Eastern Daylight Saving Time)

// The random function 
// Will generate 10 random number between 0,1 (excluding the 1)
for (let i =0; i<10; i++) {
    console.log(Math.random())
}

// Generate 10 random numbers betweeen 0 and 5 (excluding 5) 
console.log("---------------------------------");
let minimum = 0;
let maximum = 5;
for (let i=0; i<10; i++) {
    console.log(Math.random()*(maximum - minimum)); // will generate floating numbers
}
// Generate 10 random numbers between 15 to 20 (excluding 20)
console.log("---------------------------------");
 minimum = 15;
 maximum = 20;
for (let i=0; i<10; i++) {
    console.log(Math.random()*(maximum - minimum)+minimum); // will generate floating numbers
}
// Generate 10 random integer numbers from 15 to 20 (excluding 20)
console.log("---------------------------------");
 minimum = 15;
 maximum = 20;
for (let i=0; i<10; i++) {
    console.log(Math.floor((Math.random()*(maximum - minimum)+minimum))); // will generate floating numbers
}

// Generate 10 random integer numbers from 15 to 20 (including 20)
console.log("---------------------------------");
 minimum = 15;
 maximum = 20;
for (let i=0; i<10; i++) {
    console.log(Math.floor((Math.random()*(maximum - minimum + 1)+minimum))); // will generate floating numbers
}