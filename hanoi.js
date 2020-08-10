//The positions
const pos1 = document.querySelector('#pos1');
const pos2 = document.querySelector('#pos2');
const pos3 = document.querySelector('#pos3');
const pos4 = document.querySelector('#pos4');
const pos5 = document.querySelector('#pos5');
const pos6 = document.querySelector('#pos6');
const pos7 = document.querySelector('#pos7');
const pos8 = document.querySelector('#pos8');
const pos9 = document.querySelector('#pos9');
    const positions = document.querySelectorAll('.pos');
//The discs
const d1 = document.querySelector('#d1');
const d2 = document.querySelector('#d2');
const d3 = document.querySelector('#d3');
    const disks = document.querySelectorAll('.d');

let draggedItem=null;

for(let i=0; i<disks.length; i++){
    const disk=disks[i];
    disk.addEventListener('dragstart', function(){
        draggedItem=disk;
        setTimeout(function(){
            disk.style.display='none';
        },0)
    });
    disk.addEventListener('dragend', function () {
        setTimeout(function () {
            disk.style.display = 'block';
            draggedItem = null;
        }, 0)
    })
    
    for(let j=0; j<positions.length; j++){
        const position=positions[j];
        position.addEventListener('dragover', function(e){
            e.preventDefault();
        });
        position.addEventListener('dragenter', function (e) {
            e.preventDefault();
        });
        position.addEventListener('drop', function (e) {
            this.append(draggedItem);
        });
    }
}





