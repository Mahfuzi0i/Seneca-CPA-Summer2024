function buildArray(min, max) {
    let i;
    let arr=[];
    for (i=0; min <= max ; i++) {
        arr[i] = min;
        min ++;
    }
    return arr;
}
console.log(buildArray(5,10));
/////////////////////////////////////////////////

// with function expression
const buildArray2 = function (min, max) {
    let i;
    let arr=[];
    for (i=0; min <= max ; i++) {
        arr[i] = min;
        min ++;
    }
    return arr;
}
console.log(buildArray2(5,10));

// using arrow expression

// with function expression
const buildArray3 = (min, max) => {
    let i;
    let arr=[];
    for (i=0; min <= max ; i++) {
        arr[i] = min;
        min ++;
    }
    return arr;
}
console.log(buildArray3(5,10));