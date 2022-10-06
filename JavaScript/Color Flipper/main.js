const colors = ["Green", "Red", "rgba(133, 122, 200)", "#f15025", " #6f42c1",   " #0d6efd","#f8f9fa " ,"#fff " ,"  #ffc107" ," #fd7e14 " ," #dc3545 " ,"  #d63384" ,"#6f42c1 " ," #6610f2" ," #0d6efd" ,"#198754 " ,"  #20c997" ," #0dcaf0"," #000 " ,"#212529 " ," #343a40" ," #495057" ," #6c757d " ,"  #adb5bd" ," #ced4da " ," #dee2e6 " ," #e9ecef "  ];

const btn = document.getElementById('btn');
const color = document.querySelector(".color");

btn.addEventListener('click', function() {
    const randomNumber = getRandomNumber();
    document.body.style.backgroundColor = colors[randomNumber];
    color.textContent = colors[randomNumber];
})

function getRandomNumber() {
    return Math.floor(Math.random() * colors.length);
}