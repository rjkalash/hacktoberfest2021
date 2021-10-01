// JavScript function to create a table on clicking

function loadTable(){
    let table = document.createElement('table');
    table.setAttribute('border', 'solid')
    table.setAttribute('width', '200px')
    let thead = document.createElement('thead');
    let tr = document.createElement('tr');
    let tbody = document.createElement('tbody');
    let idHead = document.createElement('th');
    idHead.innerText = 'ID';
    let nameHead = document.createElement('th');
    nameHead.innerText = 'Name';
    tr.append(idHead, nameHead);
    thead.append(tr);
    table.append(thead);

    document.getElementById("tablediv").append(table);
}