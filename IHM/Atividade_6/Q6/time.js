let segundos = 0;
let intervalo = null;
let min = 0;
let horas = 0;

const display = document.getElementById('tempo');
const botao = document.getElementById('btn');

botao.onclick = function() {
    if (intervalo === null) {
        botao.innerText = 'Parar';

        intervalo = setInterval(() => {
            segundos++;
            display.innerText = horas + 'h ' + min + 'm ' + segundos + 's';

            if(segundos == 60){
                min++;
                segundos = 0;
            }

            if(min == 60){
                horas++;
                min = 0;
                segundos = 0;
            }

        }, 1000);
    } else {
        clearInterval(intervalo);
        intervalo = null;
        botao.innerText = 'Continuar';
    }    
};
