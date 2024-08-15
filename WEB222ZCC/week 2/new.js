// 10. Check if a number is between two other numbers.
function checkBetween(num, lower, upper, inclusive = false) {
    var status = inclusive ? (num >= lower && num <= upper) : (num > lower && num < upper);
    return status;
}
console.log(checkBetween(66, 1, 50, true));  