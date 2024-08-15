var a = 15; //global variable
console.log("The value of a outside function=", a);  
function doit(){
    console.log("inside function-", a);
    
    var c = 12; //this is a function/local scope.
    console.log("the value of c inside the function,",c);
    b = 19; //a global variable

    {
        var  d = 22;
        let e = 7;
        console.log("the value of e inside the function block",e);
    }
    console.log("the value of d inside the function-",d);
    // console.log("the value of e inside the function outside the block",e); //this is error because variable e is not visible outside the block
}
doit();
console.log("The value of b outside function=", b);
//console.log("the value of c outside function-", c);  //because the scope of this varible is the function/local
