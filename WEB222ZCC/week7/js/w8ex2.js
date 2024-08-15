function showTime() {
    var currentDate = new Date();
    document.getElementById("output").innerHTML = currentDate.toLocaleTimeString();
}

//window.onload = showTime;
window.onload = function() {
    showTime();
    let t;
    document.getElementById("btn").onclick= function() {
        
        if(this.value=="START") {
            t = setInterval(showTime, 1000); // the number in miliseconds
            this.value="STOP";
        }
        else if(this.value=="STOP") {
            clearInterval(t);
            this.value="START";
        }
        
    };
    
    
};