// User defined objects
// Create User defined objects using literals
// anything between curly braces is an object
let person1 = {
    //string  : Any other value(string, number, bool)
    firstName : "Abdullah",
    "last name" : "Mahfuz", // for multi word must use "" 
    age : 19,
    lastAccess : new Date(),
    address : {streetNumber : 19, streetname: "ALL DRIVE", city : "Toronto"},
    print : function() {
        console.log(`My name is ${person1.firstName} ${this["last name"]}, and i am ${person1.age} olD.`)
    }

};

// JavaScript objects are associative arrays (or map, or dictionary - 
// an data structure composed of a collection of key/value pairs), 
// augmented with prototypes. 


console.log(person1.firstName); // way 1
console.log(person1["firstName"]); // way 2, if you are using way 2 you must put "" between the key

console.log(person1["last name"]); // If the key name is multiwords (it has space in between) then you must use way2
console.log(person1.age);

// access the object inside of  an object
console.log(person1.address.city);
console.log(person1.lastAccess);
 // access the function inside the object
person1.print();


// Create objects using function constructors
// here, we can not use multiword key/property
function personV2(first = "xxxx", last = "yyyyy", age=18) {
    this.firstName = first; // The firstName now has the parameter first
    this.lastName = last;
    this.age = age;
    this.print = function() {
        console.log(`My name is ${this.firstName} ${this.lastName}, and i am ${this.age} olD.`)
    }


}
let person = new personV2('john', 'doe', 25);
person.print();

let p1 = new personV2("Sam", "witty", 33);
let p2 = new personV2("sassy", "likky", 23);
let p3 = new personV2(); // will take the value

console.log(p3.firstName);
console.log(p1.firstName);
console.log(p1["firstName"]);
p1.print();

personV2.prototype.height = "188 cm";
console.log(p1.height);
console.log(p2.height);
console.log(p3.height);

// If you want to modfy the height
p2.height = "156 cm";
console.log(p2.height);

console.log("-------------------------");
 //let p4 = person1;  // p4 now points to person1.
 let p4 = Object.create(person1); // creates a copy of the person1 and doesn't modify the original materilas
 person1.print();
 p4.print(); 

 console.log("-------------------------");
 p4.firstName = "YYYY";
 person1.print();  // it modied the main objects
 p4.print();


