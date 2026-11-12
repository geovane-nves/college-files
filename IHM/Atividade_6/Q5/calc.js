const valor1 = document.getElementById('n1');
const valor2 = document.getElementById('n2');
const tipo = document.getElementById('tipo');

let total

function calc() {
    if (!valor1.value && !valor2.value && !tipo.value) {
        document.getElementById('resultado').style.color = "red";
        return document.getElementById('resultado').innerHTML = 'erro, digite números, e o sinal da operação';
    }
        
    switch (tipo.value) {
        case "+" : total  = parseInt(valor1.value) + parseInt(valor2.value); break;
        case "-" : total = parseInt(valor1.value) - parseInt(valor2.value); break;
        case "x" : total = parseInt(valor1.value) * parseInt(valor2.value); break;
        case "%" : total = parseInt(valor1.value) / parseInt(valor2.value); break;

    }
    document.getElementById('resultado').innerHTML = total;
}
