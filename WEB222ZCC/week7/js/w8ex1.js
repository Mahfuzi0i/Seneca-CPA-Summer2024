window.onload = function() { // the function will be executed once all the events have been loaded
    document.getElementById('btn1').onclick = function() {
        alert("This is the method 2 of handling an event");
    };
    
    function showAlert() {
        alert("Hello, My name is Abdullah AL MAhfuz");
    }
    document.getElementById('btn1').onclick = showAlert;
    
    // the 3rd way
    document.getElementById('btn2').addEventListener('click', showAlert);
    document.getElementById('btn2').addEventListener('click', function() {
        alert("Seneca college!");
    });
};



