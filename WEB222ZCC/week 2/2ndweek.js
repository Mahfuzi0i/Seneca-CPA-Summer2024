console.log("welcome to week 2");
//function delaration
function greeting1() {
    console.log("hello there, i am Abdullah");
}
greeting1();

function greeting2(){
    return "Hello there";
}
let str = greeting2();
console.log(str);
console.log(greeting2());
console.log(greeting1());

//function parameter passing
function greeting3(name){
    //return "Hello, my name is "+name;
    return `Hello ${name}`;
}
console.log(greeting3("Mahfuz"));
console.log(greeting3(5));
console.log(greeting3());

//passing 
function greeting4(name = "sam"){ //if we dont pass any argument then sam will be the value
    //return "Hello, my name is "+name;
    return `Hello ${name}`;
}
console.log(greeting4());
console.log(greeting4("tom")); //it will ignore default value sam because argument is given

// function sum1(num1,num2){
//     if(!num1 || !num2){
//         throw Error("You must pass the first and 2nd number-")
//     }
//     //if(!num2){
//         //throw Error("You must pass the second number-")
//     //}
//     //return num1 + num2;
// }
// console.log(sum1(100,100));
// console.log(sum1('3'+'5'));
// console.log(sum1('hi','Muath'));

// console.log(sum1(3));
// console.log(sum1(3,5,9));

function sum2(){
    // if(!num1 || !num2){
    //     throw Error("You must pass the first and 2nd number-")
    // }
    
    return arguments[0]+arguments[1];
}
console.log(sum2(100,300));
console.log(sum2(100,300,200));

//a general sum function
function sum3(){
    var s = 0;
    for (let i = 0; i<arguments.length; i++){
        s+=arguments[i];
    }
    return s;
}
console.log(sum3(12,10,10));
console.log(sum3(10,10,20,20,100));

//functional expressions
let m = sum3();
console.log(m);
console.log(typeof(m));
console.log(typeof(sum3));

let f = sum3; //rename function sum3 to f
console.log(f(10,15));

//f = 22;
console.log(f(3,10));

const f2 = function (){
    return "good afternoon";
};
console.log(f2());

//f2 = 88;  you cann ot do that
let f3 = f2;
console.log(f3());

function average(f,n){
    return f(6,4,5)/n;
}
console.log(average(sum3,3));

//Arrow function expression (=> is the arrow)
const sum4= (num1,num2)=>num1 + num2;
console.log(sum4(10,11));

const f4 = ()=> "good afternoon";
console.log(f4());