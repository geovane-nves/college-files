javascript
document.addEventListener('DOMContentLoaded', function() {
    console.log(
        'DOMContentLoaded:',
        performance.now().toFixed(2),
        'ms'
    );
});

window.addEventListener('load', function() {
    console.log(
        'Load:',
        performance.now().toFixed(2),
        'ms'
    );
});