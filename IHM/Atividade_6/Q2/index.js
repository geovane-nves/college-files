const ocultado = document.getElementById('oculto');
const mostrar = document.getElementById('mostrar');
const ocultar = document.getElementById('ocultar');

// Inicialmente oculto
ocultado.style.opacity = '0';

mostrar.onclick = function() {
    ocultado.style.opacity = '1';
};

ocultar.onclick = function(){
    ocultado.style.opacity = '0';
}