/*!
* Start Bootstrap - Business Casual v7.0.8 (https://startbootstrap.com/theme/business-casual)
* Copyright 2013-2022 Start Bootstrap
* Licensed under MIT (https://github.com/StartBootstrap/startbootstrap-business-casual/blob/master/LICENSE)
*/
// Highlights current date on contact page
function currentDay() {
    const listHoursArray = document.body.querySelectorAll('.list-hours li');
    listHoursArray[new Date().getDay()-1].classList.add(('today'));
}
	
function pokazMape() {
	const wspolrzedne = { lat: 51.2369, lng: 22.5488};
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

function dodajMenu(nazwa, skladniki, numer) {
	var item = {};
	var rozmiarSelect = document.getElementById(numer);
	var selectWartosc = rozmiarSelect.options[rozmiarSelect.selectedIndex].value;
	var wartosci = selectWartosc.split('-');
	item.nazwa = nazwa;
	item.rozmiar = wartosci[0];
	item.skladniki = skladniki;
	item.ilosc = 1;
	item.cena = parseInt(wartosci[1]);
	item.wlasna = false;
	sessionStorage.setItem(nowyKlucz(), JSON.stringify(item));
	cenaKoszyk();
}

function dodajKreator() {
	if(!sprawdz()) return false;
	
	var rozmiar = "";
	var skladniki = [];
	var ilosc = document.getElementById("ilosc").value;
	var cena = 0;
	var rozmiarRadio = document.getElementsByName("rozmiar");
	var skladnikiBox = document.getElementsByName("skladnik");
	
	if(rozmiarRadio[0].checked) 
	{
		cena = 28;
		rozmiar = rozmiarRadio[0].value;
	}
	else 
	{
		cena = 32;
		rozmiar = rozmiarRadio[1].value;
	}
		
	for(let i=0;i<skladnikiBox.length;i++)
	{
		if(skladnikiBox[i].checked) 
		{
			cena += 2;
			skladniki.push(skladnikiBox[i].id);
		}
	}
	cena *= ilosc;
	
	var item = {};
	item.nazwa = "Własna";
	item.rozmiar = rozmiar;
	item.skladniki = skladniki;
	item.ilosc = ilosc;
	item.cena = cena;
	item.wlasna = true;
	sessionStorage.setItem(nowyKlucz(), JSON.stringify(item));
	cenaKoszyk();
	resetForm();
}

function cenaKoszyk() {
	var cena = 0;
	for(let i=0;i<sessionStorage.length;i++)
	{
		var retrieveItem = JSON.parse(sessionStorage.getItem(sessionStorage.key(i)));
		cena += retrieveItem.cena;
	}
	var koszyk = document.getElementById("koszykCena");
	var koszykPrzycisk = koszyk.parentElement;
	if(cena == 0)
		koszykPrzycisk.classList.add("disabled");
	else
		koszykPrzycisk.classList.remove("disabled");
	koszyk.innerHTML = cena + " zł";
}

function pokazKoszyk() {
	cenaKoszyk();
	var koszyk = document.getElementById("koszyk");
	var zawartoscKoszyka = "";
	var wartoscZamowienia = 0;
	for(let i=0;i<sessionStorage.length;i++)
	{
		var klucz = sessionStorage.key(i);	
		var item = JSON.parse(sessionStorage.getItem(klucz));
		wartoscZamowienia += parseInt(item.cena);
		var skladniki="";
		for(let j=0;j<item.skladniki.length;j++)
		{
			var s = item.skladniki[j];
			if(s.includes("_"))
			{
				s = s.replace(/_/, " ");
			}
			skladniki += "<br>" + s;
		}
		if(item.wlasna)
		{
			zawartoscKoszyka += "<tr> <td class='col-md-1'>" + item.ilosc + "x</td> <td class='col-md-3'>" + item.nazwa + skladniki + "</td> <td class='col-md-2'>" + item.rozmiar + "cm</td> <td class='col-md-2'> <button class='btn btn-primary bi-plus' onclick='zmienIloscKoszyk(\"" + klucz + '\",' + true + ")'></button> <button class='btn btn-primary bi-dash' onclick='zmienIloscKoszyk(\"" + klucz + '\",' + false + ")'></button> </td> <td class='col-md-2'>" + item.cena + "zł</td> <td class='col-md-2'> <button class='btn btn-primary bi-pen' onclick='wczytajEdytor(\"" + klucz + "\")'></button> <button class='btn btn-primary bi-trash' onclick='usunItem(\"" + klucz + "\")'></button> </td> </tr>";
		}
		else
		{
			zawartoscKoszyka += "<tr> <td class='col-md-1'>" + item.ilosc + "x</td> <td class='col-md-3'>" + item.nazwa + skladniki + "</td> <td class='col-md-2'>" + item.rozmiar + "cm</td> <td class='col-md-2'> <button class='btn btn-primary bi-plus' onclick='zmienIloscKoszyk(\"" + klucz + '\",' + true + ")'></button> <button class='btn btn-primary bi-dash' onclick='zmienIloscKoszyk(\"" + klucz + '\",' + false + ")'></button> </td> <td class='col-md-2'>" + item.cena + "zł</td> <td class='col-md-2'> <button class='btn btn-primary bi-trash' onclick='usunItem(\"" + klucz + "\")'></button> </td> </tr>";
		}
	}
	zawartoscKoszyka += "<tr> <td colspan='6'><h5><b>Razem do zapłaty: " + wartoscZamowienia + "zł</b></h5></td></tr>"	;
	koszyk.innerHTML = zawartoscKoszyka;
}

function zmienIloscKoszyk(klucz, dodaj) {
	var item = JSON.parse(sessionStorage.getItem("" + klucz));
	var ilosc = item.ilosc;
	var cena = item.cena / item.ilosc;
	if(dodaj)
		item.ilosc++;
	else
		if(item.ilosc > 1)
			item.ilosc--;
	item.cena = cena * item.ilosc;
	sessionStorage.setItem(klucz, JSON.stringify(item));
	pokazKoszyk();
}

function usunItem(klucz){
	sessionStorage.removeItem("" + klucz);
	if(sessionStorage.length==0) window.location.assign("menu.html");
	pokazKoszyk();
}

function nowyKlucz() {
	if(sessionStorage.length==0) return "item0";
	var klucz=sessionStorage.key(sessionStorage.length-1);
	var id = parseInt(klucz.substr(4));
	while(sessionStorage.hasOwnProperty("" + klucz))
	{
		id++;
		klucz = 'item' + id;
	}
	return klucz;
}

function zapiszEdycje(klucz) {
	if(!sprawdz()) return false;
	var item = JSON.parse(sessionStorage.getItem("" + klucz));
	
	var rozmiar = "";
	var skladniki = [];
	var ilosc = document.getElementById("ilosc").value;
	var cena = 0;
	var rozmiarRadio = document.getElementsByName("rozmiar");
	var skladnikiBox = document.getElementsByName("skladnik");
	
	if(rozmiarRadio[0].checked) 
	{
		cena = 28;
		rozmiar = rozmiarRadio[0].value;
	}
	else 
	{
		cena = 32;
		rozmiar = rozmiarRadio[1].value;
	}
		
	for(let i=0;i<skladnikiBox.length;i++)
	{
		if(skladnikiBox[i].checked) 
		{
			cena += 2;
			skladniki.push(skladnikiBox[i].id);
		}
	}
	cena *= ilosc;
	
	item.rozmiar = rozmiar;
	item.skladniki = skladniki;
	item.ilosc = ilosc;
	item.cena = cena;
	sessionStorage.setItem(klucz, JSON.stringify(item));
	wczytajKoszyk();
}

function wczytajDanePizzy(klucz) {
	var item = JSON.parse(sessionStorage.getItem("" + klucz));	

	var ilosc = document.getElementById("ilosc");
	var rozmiarRadio = document.getElementsByName("rozmiar");
	var skladnikiBox = document.getElementsByName("skladnik");
	var cena = document.getElementById("cena");
	
	ilosc.value = item.ilosc;
	
	for(let i=0;i<rozmiarRadio.length;i++)
	{
		if(rozmiarRadio[i].value == item.rozmiar) 
		{
			rozmiarRadio[i].checked = true;
		}
	}
	
	for(let i=0;i<item.skladniki.length;i++)
	{
		for(let j=0;j<skladnikiBox.length;j++)
		{
			if(skladnikiBox[j].id == item.skladniki[i])
			{
				skladnikiBox[j].checked = true;
				break;
			}
		}
	}
	
	cena.innerHTML = "Cena pizzy: " + item.cena + "zł";
	document.getElementById("formPizza").onchange = function() {aktualizujCene()};
	document.getElementById("zapisz").onclick = function() {zapiszEdycje(klucz)};
}

function sprawdz() {
	var skladniki = document.getElementsByName("skladnik");
	var error_skladniki = document.getElementById("error_skladniki");
	var x=0;
	for(let i=0;i<skladniki.length;i++)
	{
		if(skladniki[i].checked) x++;
	}

	if (x==0) 
	{			
		error_skladniki.innerHTML = "Musisz wybrać przynajmniej jeden składnik";
		return false;
	}
	else
	{
		error_skladniki.innerHTML = "";
		return true;
	}
}

function resetForm() {
	document.getElementById("formPizza").reset();
	aktualizujCene();
	document.getElementById("error_skladniki").innerHTML = "";
}

function aktualizujCene() {
	var ilosc = document.getElementById("ilosc").value;
	var cena = 0;
	var rozmiar = document.getElementsByName("rozmiar");
	if(rozmiar[0].checked) cena = 28;
	else cena = 32;
	var skladniki = document.getElementsByName("skladnik");
	for(var i=0;i<skladniki.length;i++)
	{
		if(skladniki[i].checked) cena += 2;
	}
	var cenaText = document.getElementById("cena");
	cena *= ilosc;
	cenaText.innerHTML = "Cena pizzy: " + cena + "zł";
}

function wczytajEdytor(klucz) {
	var tresc = document.getElementById("tresc");
	fetch('edytor.txt')
	.then( response => response.text())
	.then( data=> tresc.innerHTML = data)
	.then(responseJson => wczytajDanePizzy(klucz))
}

function wczytajKoszyk() {
	var tresc = document.getElementById("tresc");
	fetch('koszyk.txt')
	.then( response => response.text())
	.then( data=> tresc.innerHTML = data)
	.then((responseJson) => pokazKoszyk(responseJson))
}

function sprawdzZamowienie()
{ 
	var ok=true;
	obiektNazw = /^[a-zA-Z]{2,20}$/;
	obiektNumer = /^([0-9]{1,3})$/;	
	obiektTelefon = /^([0-9]{9})$/;
	obiektImie = /^[a-zA-Z]{3,20}$/;
	obiektEmail = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
	obiektNip = /^([0-9]{10})$/;
	var klasy = "form-control form-control-sm";
	
	var miasto = document.getElementById("miasto");
	var ulica = document.getElementById("ulica");
	var numer = document.getElementById("numer");
	var nrM = document.getElementById("numerM");
	var telefon = document.getElementById("telefon");
	var imie = document.getElementById("imie");
	var email = document.getElementById("email");
	var nip = document.getElementById("nip");
	miasto.className = klasy;
	ulica.className = klasy;
	numer.className = klasy;
	nrM.className = klasy;
	telefon.className = klasy;
	imie.className = klasy;
	email.className = klasy;
	nip.className = klasy;
	
	if (!sprawdzPole(miasto,obiektNazw))
	{ 
		ok=false;
		miasto.classList.add("is-invalid");
	}
	miasto.classList.add("is-valid");
	
	if (!sprawdzPole(ulica,obiektNazw))
	{ 
		ok=false;
		ulica.classList.add("is-invalid");
	}
	ulica.classList.add("is-valid");
	
	if (!sprawdzPole(numer,obiektNumer))
	{ 
		ok=false;
		numer.classList.add("is-invalid");
	}
	else numer.classList.add("is-valid");
	
	if(nrM.value != "")
		if (!sprawdzPole(nrM,obiektNumer))
		{ 
			ok=false;
			nrM.classList.add("is-invalid");
		}
		else nrM.classList.add("is-valid");
	
	if (!sprawdzPole(telefon,obiektTelefon))
	{ 
		ok=false;
		telefon.classList.add("is-invalid");
	}
	else telefon.classList.add("is-valid");
	
	if(imie.value != "")
		if (!sprawdzPole(imie,obiektImie))
		{ 
			ok=false;
			imie.classList.add("is-invalid");
		}
		else imie.classList.add("is-valid");
	
	if (!sprawdzPole(email,obiektEmail))
	{ 
		ok=false;
		email.classList.add("is-invalid");
	}
	else email.classList.add("is-valid");
	
	if(nip.value != "")
		if (!sprawdzPole(nip,obiektNip))
		{ 
			ok=false;
			nip.classList.add("is-invalid");
		}
		else nip.classList.add("is-valid");
	
	if (ok) 
	{
		document.getElementById("container").innerHTML = "<div id='tresc' class='cta-inner bg-faded rounded'> <h2 class='section-heading'> <span class='section-heading-lower fw-bold text-center'>Zamówienie zostało złożone pomyślnie</span> </h2></div>"
		sessionStorage.clear();
		cenaKoszyk();
	}
	return ok;
}

function sprawdzPole(obiektPole,obiektRegex) {
	if(!obiektRegex.test(obiektPole.value)) return (false);
	else return (true);
}

function sprawdzKoszyk() {
	if(sessionStorage.length==0)
		document.getElementById("zamawiam").disabled = true;
	else
		document.getElementById("zamawiam").disabled = false;
}