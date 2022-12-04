function oblicz()
{ 
	//Słówko var - oznacza zmienną; typ tej zmiennej
	//będzie zależał od jej wartości;
	//Pobierz element o id=l1 do zmiennej l1:
	var l1=document.getElementById('l1');
	//pobierz wartość (łańcuch tekstowy) wpisaną w polu
	//formularza o id='l1':
	l1=l1.value;
	//Przekonwertuj (jeśli się uda) l1 do wartości typu int:
	l1=parseInt(l1);
	//Jeśli udała się próba konwersji to l1 zawiera wartość całkowitą
	//Analogicznie realizujemy pobranie wartości z drugiego pola
	// tekstowego, ale tym razem wszystko w jednej instrukcji:
	var l2=parseInt(document.getElementById('l2').value);
	//Teraz już możemy obliczyć sumę i ustawić wartość pola tekstowego
	//o id='suma':
	var s=document.getElementById('suma');
	s.value=l1+l2;
}

function pokaz(id)
{
	var tresc="";
	switch (id)
	{ 
		case 2: tresc += pokazGalerie();break;
		case 3: tresc += pokazPost(); break;
		case 4: tresc += pokazKontakt();break;
		default: tresc += pokazO();
	}
	//pobierz element o wskazanym id i ustaw jego nową zawartość:
	document.getElementById('blok').innerHTML = tresc;
}

function pokazO()
{
	var tresc ='<h2><br />Pierwsze kroki</h2> ';
	//operator += uzupełnia łańcuch kolejną porcją znaków:
	tresc += '<p> W aplikacjach typu SPA (ang. Single Page Application) po przesłaniu pierwszego żądania również dochodzi do odesłania początkowego dokumentu HTML do przeglądarki, jednak po zakończeniu inicjalizacji wszelkie działania użytkownika prowadzą tylko do wysłania żądań asynchronicznie (w tle za pomocą AJAX). Odpowiedziami na te żądania zwykle są tylko fragmenty kodu HTML (zamiast całych dokumentów), a niekiedy wyłącznie dane, które następnie są wstawiane/zamieniane w ramach istniejących elementów dokumentu HTML. Nigdy nie dochodzi do zamiany całego dokumentu HTML.</p>'+
	'<p class="srodek"><img src="zdjecia/zdjecia/baner.jpg" alt="Zdjęcie" /></p>'+
	'<article><h2>Wady SPA</h2><p>'+
	' Czas wytworzenia oraz nakład pracy włożony w stworzenie aplikacji jest o wiele większy, co wiąże za sobą dodatkowe koszta, dlatego tworzenie małych stron jest nieopłacalne - efekt dla strony z jedną zakładką jest niezauważalny. Pozycjonowanie stron wymaga większego nakładu pracy. Obecnie roboty indeksujące Google nie radzą sobie ze stronami tego typu, co wiąże się z koniecznością tworzenia rozwiązań przystosowanych dla robotów. </p></article>';
	//przekaż wynik – gotową zawartość – do miejsca wywołania funkcji:
	return tresc;
}

function pokazGalerie()
{
	var tresc='<h2><br />Moja galeria</h2>';
	tresc+=' <div class="galeria">';
	//wygeneruj kod HTML z obrazami za pomocą pętli for:
	for(i=1;i<=10;i++)
	{
		tresc+='<div class="slajd"> <img src="zdjecia/miniaturki/obraz'+i+'.jpg" /></div>';
	}
	return tresc+'</div>';
}

function pokazKontakt()
{
	var tresc='<h2><br />Kontakt</h2>';
	//uzupełnij treść:
	// tresc+= ...
	return tresc;
}

function pokazPost()
{
	//funkcja generuje kod formularza – dane wpisane w odpowiednie pola przez
	//użytkownika zostaną przekazane mailem na wskazany adres, ale najpierw po
	//zajściu zdarzenia submit (wyślij) – zostanie wywołana funkcja pokazDane()
	tresc='<h2><br />Dodaj post</h2>';
	tresc+='<article class="srodek" ><form action="mailto:b.panczyk@pollub.pl" method="post" onsubmit="return pokazDane();">'+
		'Twój email:<br /> <input type="email" name="email" id="email" required /><br />'+
		'Nazwisko i imię:<br> <input type="text" name="imie" id="imie" required pattern="[A-Za-z ]+" /> <br>'+
		'Telefon:<br> <input type="number" name="telefon" id="telefon" required max="999999999"/> <br>'+
		'<br>Zainteresowania: <br> <input type="checkbox" id="zaint1" name="zaint1" value="Sport"/> Sport'+
		'<input type="checkbox" id="zaint2" name="zaint2" value="Muzyka"/> Muzyka'+
		'<input type="checkbox" id="zaint3" name="zaint3" value="Film"/> Film'+
		'<input type="checkbox" id="zaint4" name="zaint4" value="Inne"/> Inne <br>'+
		'<br>Wiek: <br> <input type="radio" id="wiek1" name="wiek" value="Mniej niż 10"/> Mniej niż 10'+
		'<input type="radio" id="wiek2" name="wiek" value="10-20"/> 10-20'+
		'<input type="radio" id="wiek3" name="wiek" value="21-30"/> 21-30'+
		'<input type="radio" id="wiek4" name="wiek" value="31-40"/> 31-40'+
		'<input type="radio" id="wiek5" name="wiek" value="41-50"/> 41-50'+
		'<input type="radio" id="wiek6" name="wiek" value="Więcej niż 50"/> Więcej niż 50 <br>'+
		'Komentarz: <br /><textarea rows="4" cols="20" id="wiadomosc" name="wiadomosc" required></textarea>'+
		'<br /> <input type="submit" name="wyslij" value="Wyślij" />'+'</form></article>';
	return tresc;
}

function pokazDane()
{
	//Funkcja zbiera dane wpisane w pola formularza i wyświetla okienko
	//typu confirm do zatwierdzenia przez użytkownika:
	var dane="Następujące dane zostaną wysłane:\n";
	var zaint="";
	var wiek="";
	var c = document.getElementsByTagName('input');
		for (var i = 0; i < c.length; i++) {
			if (c[i].type == 'checkbox' && c[i].checked == true) {
				zaint+=c[i].value+" ";
			}
			if (c[i].name == 'wiek' && c[i].checked == true) {
				wiek=c[i].value
			}
		}
	dane+="Email: "+document.getElementById('email').value+"\n"+
	"Nazwisko i imię: "+document.getElementById('imie').value+"\n"+
	"Telefon: "+document.getElementById('telefon').value+"\n"+
	"Zainteresowania: "+zaint+"\n"+
	"Wiek: "+wiek+"\n"+
	"Wiadomość: "+document.getElementById('wiadomosc').value+"\n";
	if (window.confirm(dane)) return true; 
	else return false;
}
