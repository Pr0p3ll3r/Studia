/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/javascript.js to edit this template
 */

//Fetch API
document.addEventListener('DOMContentLoaded', () => {
    var bonas = document.getElementById('onas');
    bonas.addEventListener("click", () => {
        console.log("Strona O nas");
        pokazOnas();
    });
    var bgaleria = document.getElementById('galeria');
    bgaleria.addEventListener("click", () => {
        console.log("Galeria zdjęć");
        pokazGalerie();
    });
    var bglowna = document.getElementById('index');
    bglowna.addEventListener("click", () => {
        console.log("Główna");
        pokazGlowna();
    });
    var bformularz = document.getElementById('formularz');
    bformularz.addEventListener("click", () => {
        console.log("Formularz");
        pokazFormularz();
    }); 
});

function pokazOnas() {
    fetch("http://localhost/phplab11/skrypty/onas.php")
            .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('main').innerHTML = data;
            })
            .catch((error) => {
                console.log(error);
            });
}

function pokazGalerie() {
    fetch("http://localhost/phplab11/skrypty/galeria.php")
            .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('main').innerHTML = data;
            })
            .catch((error) => {
                console.log(error);
            });
}

function pokazGlowna() {
    fetch("http://localhost/phplab11/skrypty/kontakt.php")
            .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('main').innerHTML = data;
            })
            .catch((error) => {
                console.log(error);
            });
}

function pokazFormularz() {
    fetch("http://localhost/phplab11/skrypty/formularz.php")
            .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('main').innerHTML = data;
                var formElem = document.getElementById("formZamowienia");
                formElem.addEventListener("submit", dodaj);
                var bpokaz = document.getElementById('pokaz');
                bpokaz.addEventListener("click", () => {
                    console.log("Pobranie wszystkich zamówień");
                    pokaz();
                });
                var bstatystyki = document.getElementById('statystyki');
                bstatystyki.addEventListener("click", () => {
                    console.log("Pobranie statystyk");
                    pokazStatystyki();
                });
                var bpokazPhp = document.getElementById('PHP');
                bpokazPhp.addEventListener("click", () => {
                    console.log("Pobranie zamówień PHP");
                    pokazWybrany("PHP");
                });
                var bpokazCpp = document.getElementById('CPP');
                bpokazCpp.addEventListener("click", () => {
                    console.log("Pobranie zamówień CPP");
                    pokazWybrany("CPP");
                });
                var bpokazJava = document.getElementById('Java');
                bpokazJava.addEventListener("click", () => {
                    console.log("Pobranie zamówień Java");
                    pokazWybrany("Java");
                });
            })
            .catch((error) => {
                console.log(error);
            });
}

function dodaj(e) {
    e.preventDefault();
    const formData = new FormData();
    formData.append("nazw", document.getElementById('nazw').value);
    formData.append("wiek", document.getElementById('wiek').value);
    formData.append("mail", document.getElementById('mail').value);
    formData.append("kraj", document.getElementById('kraj').value);
    let jezyki = document.querySelectorAll('input[name="jezyki[]"]:checked');
    for (var i = 0; i < jezyki.length; i++) {
        formData.append('jezyki[]', jezyki[i].value);
    } 
    let zaplata = document.querySelector('input[name="zaplata"]:checked');
    if(zaplata){
        formData.append("zaplata", zaplata.value);
    } 
    
    fetch("http://localhost/phplab11/skrypty/dodaj.php", {
        method: "post",
        body: formData
    })
            .then(response => response.text())
                .then(response => {
                    console.log("Dodano zamówienie:");
                    console.log(response);
                    document.getElementById('daneFormularz').innerHTML = response;
            })
            .catch((error) => {
                console.log(error);
            });
}

function pokaz() {
    fetch("http://localhost/phplab11/skrypty/pokaz.php")
            .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('daneFormularz').innerHTML = data;
            })
            .catch((error) => {
                console.log(error);
            });
}

function pokazWybrany(jezyk) {  
    fetch("http://localhost/phplab11/skrypty/pokazWybrany.php", {
            method: 'POST',
            headers: {
              'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: new URLSearchParams({
              'jezyk': jezyk
            })
        })
        .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('daneFormularz').innerHTML = data;
            })
            .catch((error) => {
                console.log(error);
            });
}

function pokazStatystyki() {
    fetch("http://localhost/phplab11/skrypty/statystyki.php")
            .then((response) => {
                if (response.status !== 200) {
                    return Promise.reject('Coś poszło nie tak!');
                }
                return response.text();
            })
            .then((data) => {
                document.getElementById('daneFormularz').innerHTML = data;

            })
            .catch((error) => {
                console.log(error);
            });
}