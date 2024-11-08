let outputDiv;

window.onload = function() {
    const button2 = document.querySelector('.generate');
    button2.addEventListener('click', getNvalue);
    outputDiv = document.getElementById('output');
};

let n;
const queenfont = '<i class="fas fa-chess-queen" style="color:#000"></i>';

function getNvalue() {
    n = document.getElementById('nValue').value;
    console.log(n);
    
    if (n > 10) {
        alert("Value must be less than 10");
    } else {
        generateSolution(solveNQueens());
    }
}

function solveNQueens() {
    if (n <= 0 || isNaN(n)) {
        alert("Please enter a valid number greater than 0");
        return;
    }
    // Call the C++ function solveNQueens from JavaScript using ccall
    return Module.ccall(
        'solveNQueens',   // C++ function name
        'string',         // return type
        ['number'],       // argument types
        [n]               // arguments
    );
}

let size = 0;

function generateSolution(encodedString) { 
    let arrangements = encodedString.split('#').filter(ele => ele !== '');

    // Check if n is valid
    if (n < 1) {
        console.error('Invalid value for n:', n);
        return;
    }

    // Create table for display
    let table = document.createElement('div');
    table.classList.add('table');  // Add class for styling (optional)
    outputDiv.innerHTML = '';
    size = arrangements.length;

    // Display number of possible arrangements
    let numOfArrange = document.createElement('h1');
    numOfArrange.innerText = `For ${n}x${n} board, ${size} arrangements are possible.`;
    numOfArrange.classList.add("main-heading");
    outputDiv.appendChild(numOfArrange);
    outputDiv.appendChild(table);

    arrangements.forEach((arrangement, arrIndex) => {
        let lines = arrangement.split('$').filter(line => line !== '');
        
        let sol = document.createElement('div');
        sol.classList.add("sol");
        table.appendChild(sol);

        // Display arrangement heading
        let heading = document.createElement('h3');
        heading.innerText = arrIndex + 1;
        heading.classList.add("table-heading");
        sol.appendChild(heading);

        lines.forEach((line, rowIndex) => {
            let row = document.createElement('div');
            row.classList.add('flex', 'row');
            sol.appendChild(row);

            for (let colIndex = 0; colIndex < line.length; colIndex++) {
                let box = document.createElement('div');
                box.classList.add('box');
                
                // Set cell content and color
                if (line[colIndex] === '.') {
                    box.innerText = "-";
                } else {
                    box.innerHTML = queenfont;
                }
                row.appendChild(box);

                // Alternate background color for chessboard pattern
                if ((colIndex + rowIndex) % 2 === 0) {
                    box.style.backgroundColor = '#FF9F1C';
                }
            }
        });
        // Add code for 'Q' if needed (for queen placement and interactive gaming experience)
    });
}