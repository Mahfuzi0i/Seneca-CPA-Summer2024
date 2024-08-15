console.log('Hello World');

function validate() {

    // To validate first name- it can not be empty
    let fname = document.getElementById("fname").value.trim();
    // you can also do - let fname = document.form1.fname.value.trim();
    if (fname == "") { // first name is required

        document.getElementById("fname-error").innerHTML = "Please add a proper first name";
        return false;
    }
    // The length of the name must be 5 cahracters
    else if(fname.length < 5) {
        document.getElementById("fname-error").innerHTML = "Must be at least 5 characters";
        return false;
    }
    else {
        
        for (let i=0; i< fname.length; i++) {
            fname = fname.toUpperCase();
            if(fname[i] < "A" || fname[i] > "Z") {
                document.getElementById("fname-error").innerHTML = "First name must be alphabetical";
                return false;
            }
        }
    }

    // Vlaidating age- it cna not be empty
    let age = document.querySelector("#age").value.trim();
    if (age == "") { // age is required

        document.getElementById("age-error").innerHTML = "Please add a proper age, it can not be empty";
        return false;
    }

    // validate age- it must be a number
    else if (parseInt(age) != age) {
        document.getElementById("age-error").innerHTML = "Age must be a number";
        return false;
    }

    //checkbox validation
    if(document.form1.agree.checked == false) {

        alert("You must agree to the terms and conditions");
        return false;
    }
    return true;
}