function checkAges(number1, number2) {
    return number1.every((e) => e > number2)
}

console.log(checkAges([16, 18, 22, 32, 56], 19));
console.log(checkAges([16, 18, 22, 32, 56], 6));