function validateForm() {

    let fname = document.getElementById("fname").value.trim();
    let lname = document.getElementById("lname").value.trim();
    let age = document.getElementById("age").value.trim();
    let email = document.getElementById("email").value.trim();
    let namePattern = /^[a-zA-Z ]+$/; // it can only contain alphabet letters
    let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/; 
    // First name validation
    if(fname == "") {
        document.getElementById("fname-error").innerHTML="Fname can not be just empty spaces";
        return false;
    }
    else if(!namePattern.test(fname)) {
        document.getElementById("fname-error").innerHTML="Name can only contain alphabetical characters";
        return false;
    }

    // Last name validation
    if(lname == "") {
        document.getElementById("lname-error").innerHTML="Lname can not be just empty spaces"
        //alert("Lname can not be just empty spaces");
        return false;
    }
    else if(!namePattern.test(lname)) {
        document.getElementById("lname-error").innerHTML="Name can only contain alphabetical characters";
        return false;
    }

    // The Age validator
    if(age == "") {
        alert("Age can not be just empty spaces");
        return false;
    }
    else if(parseInt(age) != age) {
        alert("Age must be a number");
        return false;
    }
    else if(age <= 0) {
        alert("Please add a positive number for age");
        return false;
    }

    // Email validation
    if(email == "") {
        alert("Email can not be just empty spaces");
        return false;
    }
    else if(!emailPattern.test(email)) {
        document.getElementById("email-error").innerHTML="Please provide a valid email";
        return false;
    }

    // validate term and conditions
    if(document.prep.agree.checked==false) {
        //alert("Please accept the terms and conditions");
        document.getElementById("agree-error").innerHTML="You must agree to the terms and conditions";
        return false;
    }
    return true; // Alllow submission if all checks out
}

