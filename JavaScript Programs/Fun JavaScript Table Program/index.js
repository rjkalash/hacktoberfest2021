console.log("Hello");

function addTd(id, tr){
    let col = document.createElement('td');
    col.innerText = id;
    tr.append(col);
}

function createBasicTable(){
    let table = document.createElement('table');
    table.setAttribute('id', 'studentsTable');
    return table;
}

function addTr(thead){
    let theadTr = document.createElement('tr');
    thead.append(theadTr);
    return theadTr;
}

function loadTable(){
    let table = createBasicTable();
    table.setAttribute('border', 'solid')
    table.setAttribute('width', '200px')
    // table.setAttribute('class', 'table table-danger')
    let thead = document.createElement('thead');
    let theadTr = addTr(thead);

    addTd("ID", theadTr);
    addTd("Name", theadTr);

    table.append(theadTr);

    let tbody = document.createElement('tbody');

    students.forEach(element => {
        let dataRow = document.createElement('tr');
        addTd(element.id, dataRow);
        addTd(element.name, dataRow);
        tbody.append(dataRow);
    })
    table.append(tbody);
    document.getElementById("tablediv").append(table);
    
}

let setButtonClass = function() {
    // TODO - change the style of the students table to table-danger
    let table = document.getElementById('studentsTable');
    table.setAttribute('class', 'table table-danger');
}

let attachEvents = function() {
    // TODO Write code here to attach event listener to "Change table style" button
    console.error("No node written here.")
    document.getElementById('styleButton').addEventListener("click", () => console.log("Click"))
}

attachEvents();