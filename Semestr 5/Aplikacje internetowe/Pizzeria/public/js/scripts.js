/*!
 * Start Bootstrap - Business Casual v7.0.8 (https://startbootstrap.com/theme/business-casual)
 * Copyright 2013-2022 Start Bootstrap
 * Licensed under MIT (https://github.com/StartBootstrap/startbootstrap-business-casual/blob/master/LICENSE)
 */
// Highlights current date on contact page
function currentDay() {
    const listHoursArray = document.body.querySelectorAll('.list-hours li');
    listHoursArray[new Date().getDay() - 1].classList.add(('today'));
}

function pokazMape() {
    const wspolrzedne = {lat: 51.2369, lng: 22.5488};
    const map = new google.maps.Map(document.getElementById("mapa"), {
        zoom: 17,
        center: wspolrzedne,
    });
    const marker = new google.maps.Marker({
        position: wspolrzedne,
        map: map,
    });
}

function scrollFunction() {
    var nav = document.getElementById("mainNav");
    if (document.body.scrollTop > 290 || document.documentElement.scrollTop > 290) {
        nav.style.position = "sticky";
        nav.style.top = "0";
    } else {
        nav.style.position = "static";
        nav.style.top = "-50px";
    }
}