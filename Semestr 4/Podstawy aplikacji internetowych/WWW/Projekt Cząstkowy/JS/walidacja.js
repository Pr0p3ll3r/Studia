function sprawdzPole(pole_id,obiektRegex) {
	//Funkcja sprawdza czy wartość wprowadzona do pola tekstowego
	//pasuje do wzorca zdefiniowanego za pomocą wyrażenia regularnego
	//Parametry funkcji:
	//pole_id - id sprawdzanego pola tekstowego
	//obiektRegex - wyrażenie regularne
	//---------------------------------
	var obiektPole = document.getElementById(pole_id);
	if(!obiektRegex.test(obiektPole.value)) return (false);
	else return (true);
}

function sprawdz_radio(nazwa_radio){
	//Funkcja sprawdza czy wybrano przycisk radio
	//z grupy przycisków o nazwie nazwa_radio
	//---------------------------------------
	var obiekt=document.getElementsByName(nazwa_radio);
		for (i=0;i<obiekt.length;i++){ 
			wybrany=obiekt[i].checked;
			if (wybrany) return true; 
	}
	return false;
}

function sprawdz_box(box_id)
{
	//Funkcja sprawdza czy przycisk typu checkbox
	//o identyfikatorze box_id jest zaznaczony
	//----------------------------------------
	var obiekt=document.getElementById(box_id);
	if (obiekt.checked) return true;
	else return false;
}

function sprawdzWartoscRadio(nazwa_radio)
{
	var obiekt=document.getElementsByName(nazwa_radio);
		for (i=0;i<obiekt.length;i++){ 
			if (obiekt[i].checked) return obiekt[i].value; 
	}
	return "";
}

function sprawdz()
{ 
	//Funkcja realizujaca sprawdzanie całego fomularza
	//wykorzystując funkcje pomocnicze
	//--------------------------------
	var ok=true; //zmienna informująca o poprawnym wypełnieniu formularza
	//Definicje odpowiednich wyrażeń regularnych dla sprawdzenia
	//poprawności danych wprowadzonych do pól tekstowych
	obiektNazw = /^[a-zA-Z]{2,20}$/; //wyrażenie regularne dla nazwiska
	obiektEmail = /^([a-zA-Z0-9])+([.a-zA-Z0-9_-])*@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-]+)+/;
	obiektWiek = /^[1-9][0-9]{1,2}$/;
	//Sprawdzanie kolejnych pól formularza.
	//w przypadku błędu - pojawia się odpowiedni komunikat
	if (!sprawdzPole("lastname",obiektNazw))
	{ 
		ok=false;
		document.getElementById("lastname_error").innerHTML = "Wpisz poprawnie nazwisko!";
	}
	else document.getElementById("lastname_error").innerHTML = "";
	if (!sprawdzPole("age",obiektWiek))
	{ 
		ok=false;
		document.getElementById("age_error").innerHTML = "Wpisz poprawnie wiek!";
	}
	else document.getElementById("age_error").innerHTML = "";
	if (!sprawdzPole("email",obiektEmail))
	{ 
		ok=false;
		document.getElementById("email_error").innerHTML = "Wpisz poprawnie email!";
	}
	else document.getElementById("email_error").innerHTML = "";
	if (!sprawdz_box("c") && !sprawdz_box("php") && !sprawdz_box("java"))
	{ 
		ok=false;
		document.getElementById("produkt_error").innerHTML = "Musisz wybrać produkt!";
	}
	else document.getElementById("produkt_error").innerHTML = "";
	if (!sprawdz_radio("zaplata"))
	{ 
		ok=false;
		document.getElementById("zaplata_error").innerHTML = "Musisz wskazać sposób płatności!";
	}
	else document.getElementById("zaplata_error").innerHTML = "";
	

	var dane="Dane z wypełnionego przez Ciebie formularza:\n";
	var produkt="";
	var zaplata="";
	if (sprawdz_box("c"))
	{ 
		produkt+=document.getElementById("c").name+" ";
	}
	if (sprawdz_box("php"))
	{ 
		produkt+=document.getElementById("php").name+" ";
	}
	if (sprawdz_box("java"))
	{ 
		produkt+=document.getElementById("java").name;
	}
	zaplata+=sprawdzWartoscRadio("zaplata");
	dane+="Nazwisko: "+document.getElementById('lastname').value+"\n"+
	"Wiek: "+document.getElementById('age').value+"\n"+
	"Kraj: "+document.getElementById('country').value+"\n"+
	"Email: "+document.getElementById('email').value+"\n"+
	"Wybrane produkty: "+produkt+"\n"+
	"Sposób zapłaty: "+zaplata+"\n";
	if (ok) window.confirm(dane); 
	return ok;
}
