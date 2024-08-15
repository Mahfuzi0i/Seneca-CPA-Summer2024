//Number1
let label = "Senecacollege";
let tld = "ca";
let domainName = label + "." + tld;
console.log("The answer of the 1st exercise- ", domainName);
console.log("");

//Number2
console.log("exercise2- ")
let isSeneca;
if (domainName === "Senecacollege.ca") {
    isSeneca = true;
}
else {
    isSeneca = false;
}
console.log(isSeneca);
console.log("");

//Number3
console.log("exercise3- ")
let isNotSeneca;
if (domainName === "Senecacollege.ca") {
    isNotSeneca = false;
}
else {
    isNotSeneca = true;
}
console.log(isNotSeneca);
console.log("");

//Number14
var num = 20;
let isEven
if (num%2 == 0) {
    isEven = true;
}
else {
    isEven = false;
}
console.log("is the number even---", isEven);
console.log("");

//Number16
let radius = 10;
let area = Math.PI * (radius **2);
console.log("The area of the circle for the given radius-", area);
console.log("");
console.log(5**3);
console.log("");

//Number17
console.log("The temperature in celcius to farenheight");
let temperatureInCelcius = 45;
let temperatureInFarenheight = temperatureInCelcius * (9/5) + 32;
console.log(temperatureInCelcius + "C", "Is equal to", temperatureInFarenheight +"F");
console.log("");

//Number18
console.log("Convesrting feet into meeters");
let heightInFeet = 6;
let heightInMeters = heightInFeet * 0.3048;
console.log(heightInFeet + "f", "is equal to", heightInMeters);
console.log("");

//number19
let seconds = 368;
let minutes = parseInt(seconds/60);
let remainingseconds = seconds %60;
console.log(seconds, "Seconds", "is equal to", minutes, "M and ", remainingseconds,"S");
console.log("");

//Number21
let day = 6;
switch(day){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        console.log("WEEKDAY");
        break;
    case 6:
    case 7:
        console.log("WEEKEND");
        break;
    default:
        console.log("Invalid date");
        break;
}
console.log("");

//Number22
function isPositive(num){
    if (num >= 0){
        return true;
    }
    else {
        return false;
    }
}
console.log(isPositive(-120));
console.log();

//Number23
function isLeapYear(year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

console.log("The year is a leap year",isLeapYear(2024));
console.log("");