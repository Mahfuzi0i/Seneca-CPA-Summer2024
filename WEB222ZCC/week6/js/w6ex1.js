console.log("External JS code");

let e = document.getElementById('id1');
e.innerHTML = 'Abdullah AL Mahfuz';

// Updating using live js
e = document.getElementById('id2');
e.innerHTML = "<h3>SENECA COLLEGE</h3>"

// Updating using external js
let names = ['Mira', 'sam', 'Mohammed', 'olaf'];

let output = '<ul>';
for(let i = 0; i < names.length; i++){
    output += '<li>' + names[i] + '</li>';
}
output += '</ul>';
e = document.getElementById('id3').innerHTML = output;