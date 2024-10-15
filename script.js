let outputDiv;
window.onload = function() {
    const button2 = document.querySelector('.generate');
    button2.addEventListener('click', getNvalue);
    outputDiv=document.getElementById('output')
    
};
let n;

const queenfont = '<i class="fas fa-chess-queen" style="color:#000"></i>';

function getNvalue(){

    n=  document.getElementById('nValue').value;
    console.log(n);
    
   if(n>10){
    alert("Value must be less than 10")
    }
    else generateSolution(solveNQueens())
    
}
function solveNQueens() {
    var res = Module.ccall(
        "main",
        "number",
        null,
        null
    );
    if (n <= 0 || isNaN(n)) {
        alert("Please enter a valid number greater than 0");
        return;
    }
    // Call the C++ function solveNQueens from JavaScript using ccall
        let result = Module.ccall(
            'solveNQueens',  // name of the C++ function
            'string',        // return type
            ['number'],      // argument types
            [n]    // arguments (convert to integer)
        );
       
       
        return result
}


let size=0

function generateSolution(encodedString) { 
    let arrangements = encodedString.split('#');
    arrangements = arrangements.filter(ele => ele !== '');

    // Check if n is valid
    if (n < 1) {
        console.error('Invalid value for n:', n);
        return;
    }
        let table = document.createElement('div');
        table.classList.add('table'); // Add class for styling (optional)
        outputDiv.innerHTML=''
        size=arrangements.length

        let numOfarrange=document.createElement('h1');
        numOfarrange.innerText=`For ${n}x${n} board, ${size} arrangements are possible.`
        numOfarrange.classList.add("main-heading")
        outputDiv.appendChild(numOfarrange)
        outputDiv.appendChild(table);
        arrangements.forEach((e,arr) => {
            // console.log(arr);
           
            let lines = e.split('$').filter((ele)=>(ele!=''));
            let sol=document.createElement('div')
            sol.classList.add("sol");
            table.appendChild(sol)
            let heading=document.createElement('h3')
            heading.innerText=arr+1;
            heading.classList.add("table-heading")
            sol.appendChild(heading)
            lines.forEach((line ,j)=> { // Iterate through each line
                let row=document.createElement('div')
                sol.appendChild(row);
                row.classList.add('flex')
                row.classList.add('row')
                
                for (let pawn = 0; pawn < line.length; pawn++) {
                    if (line[pawn] === '.') {
                        let box = document.createElement('div');
                        box.classList.add('box');
                        box.innerText = "-"; // Correct way to set innerText
                        row.appendChild(box);
                        if((pawn+j)%2==0){
                            box.style.backgroundColor='#FF9F1C'
                        }
                    }
                    else{
                        let box = document.createElement('div');
                        box.classList.add('box');
                        box.innerHTML = queenfont; // Correct way to set innerText
                        row.appendChild(box);
                        if((pawn+j)%2==0){
                            box.style.backgroundColor='#FF9F1C'
                        }
                    }
                    // Add code for 'Q' if needed (for Queen placement)
                }
            });
        });
    
}
