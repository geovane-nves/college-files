const textarea = document.getElementById('texto');
const botao = document.getElementById('salvar');
const resultado = document.getElementById('resultado');

botao.addEventListener('click', () => {
    const texto = textarea.value.trim();

    const paragrafo = document.createElement('p');

    paragrafo.textContent = texto;

    resultado.appendChild(paragrafo);

    textarea.value = '';
});