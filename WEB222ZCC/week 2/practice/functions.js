function greet(name) {
    console.log("heloo", name);
}
greet("Abdullah");

var see = function whatever(mean) {
    console.log("I have this", mean);
}
see(12);

//lets add 2 variables 
function sum (a,b) {
    return a+b;
    
}
console.log(sum(10,20));

var see2 = function sum2 (a,b) {
    return a+b;
    
}
console.log(see2(100,300));

//working with multiple arguments
function multiply() {
    var sum = 1;
    for (var i =0; i<arguments.length; i++) {
        sum *= arguments[i];
    }
    console.log(sum);
}
multiply(2,2,2);
multiply(100,200,300);

//now lets try prompting
//using parseFloat as a conversion
console.log(parseFloat("15. 45"));
