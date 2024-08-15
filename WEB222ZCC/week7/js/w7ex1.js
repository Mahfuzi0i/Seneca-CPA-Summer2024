console.log("Welcome to JAVA Script");
document.title = "WEEK 7";

function update() {
    let e = document.querySelector("#banner");
    if (e.innerHTML == "WEEK 7 DOM")
        e.innerHTML = "Abdullah Al Mahfuz";

    else 
        e.innerHTML = "WEEK 7 DOM";
}

function addH2Tag() {
    let e = document.createElement('h2');
    e.innerHTML = "Seneca College(polytechniq)";
    // document.querySelector("#content").appendChild(e);
    document.getElementById('content').appendChild(e);
    //document.body.appendChild(e);
}

function addol() {
    let names = ['sam', 'mia', 'tom'];
    let list = document.createElement('ol');
    names.forEach(function(name) {
        let li = document.createElement('li');
        li.innerHTML = name;
        list.appendChild(li);
    });
    document.body.appendChild(list);
    //document.body.appendChild(list);
}

function addLink() {
    let e = document.createElement('a'); // the tag
    e.innerHTML = "Click me ";
    //e.setAttribute("href", "https://educationsnapshots.com/projects/18781/seneca-college-newnham-campus-food-hall/");
    e.setAttribute("target", "_blank");
    e.href = "https://educationsnapshots.com/projects/18781/seneca-college-newnham-campus-food-hall/";

    //document.body.appendChild(e);
    //document.body.insertBefore(e,document.getElementById("banner"));
    document.body.insertBefore(e, document.body.firstChild);
}

function removeElement() {
    document.body.removeChild(document.body.firstChild);
}