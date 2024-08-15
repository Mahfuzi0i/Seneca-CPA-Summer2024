

var heading = ["ID", "NAME", "PROGRAM"];
var students = [
    {id:1, name:"Sam", prog:"CS"},
    {id:2, name:"Mia", prog:"CIS"},
    {id:3, name:"Mira", prog:"CADZ"}
];

window.onload = function() {

    document.getElementById("btn").onclick = function () {
        let table = document.createElement('table');

    let firstRow = document.createElement('tr');
    for (let i in heading) {
        let cell = document.createElement('th');
        cell.innerHTML = heading[i];
        firstRow.appendChild(cell);
    }
    table.appendChild(firstRow);

    for (let i = 0; i<students.length; i++) {

        let row = document.createElement('tr');
        for (let key in students[i]) {
            let cell = document.createElement('td');
            cell.innerHTML = students[i][key];
            row.appendChild(cell);
        }
        table.appendChild(row);
    }
    document.getElementById('content').appendChild(table);
    };
    
};