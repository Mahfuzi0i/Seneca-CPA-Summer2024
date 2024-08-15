var myday = new Date().getDay();
console.log(myday);

var my_hour = new Date().getHours();
console.log(my_hour);
// declaring
let me = {
  fname: "Abdullah",
  lname: "Al Mahfuz",
  date: "04 june 2024",
  print: function () {
    console.log(`I am ${me.fname} ${me.lname}. Today is- ${me.date}.`);
  },
};
me.print();
console.log(me.fname);
// function to create a new object 
function me2(fname, lname, age) {
  this.name1 = fname;
  this.name2 = lname;
  this.age = age;
  this.date = new Date();
  this.print = function () {
    console.log(
      `I am ${this.name1} ${this.name2} and i am ${this.age}. Today is ${this.date}`
    );
  };
}

let person1 = new me2("aiden", "Prosper", 23);
person1.print();

console.log('---------------------------------');
function person5(name, age) {
    this.myname = name;
    this.age = age;
    this.show = function () {
        console.log(`hello, i am ${this.name} and i am ${this.age} years old.`);
    };
}

person5.prototype.say = function() {
    console.log(`I don't know. i am ${this.age} years old and respond to ${this.name}.`);
};
let c = new person5('Alina', 33);
c.show();


console.log('-------------------------------------');

let someone1 = {
    name: "Ascalanor dubricia",
    color: 'White',
    brand: "Neon",
    id: 'sktt-9900453219'
}

var p1 = `Product available-
            product info\n
            product name: ${someone1.name}
            Brand: ${someone1.brand}
            Color: ${someone1.color}
            id: ${someone1.id}\n`;
console.log(p1);

console.log("=========================================");

let a = ['a', 1, 2, 3, 4, 'b', 'd', 'e'];
console.log(a);
console.log(a.reverse());
console.log('--------------------------------------------');

// Dynamically add of delete objects
let person4 = {};
person4.name = 'Commodore Norrington';
person4.age = 99;
person4.log = new Date();
person4.show = function() {
    console.log(`this is the log of - ${this.log}
                    my name is - ${this.name}
                    and my age - ${this.age}\n`);  
};
person4.show();

