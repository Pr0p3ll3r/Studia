function oblicz()
{ 
	var kwota=parseFloat(document.getElementById('kwota').value);
	var ileRat=parseInt(document.getElementById('ile').value);
	var procent=parseFloat(document.getElementById('procent').value);
	procent = procent/100;
	var pr_mc = procent/12;
	var r=document.getElementById('rata');
	var od=document.getElementById('odsetki');
	var wartosc=(kwota*pr_mc) / (1-(1/Math.pow(1+pr_mc,ileRat)));
	if(isNaN(wartosc) || !isFinite(wartosc)){
		alert("Wprowadzono błędne dane");
		return;
	}
	r.value=wartosc.toFixed(2);
	od.value=(wartosc*ileRat).toFixed(2);
}
/**
function kalkulator()
{
	var tab = document.getElementsByName("operator");
	var op;

	for(let i=0;i<tab.length;i++){
		if(tab[i].checked) op = tab[i].value;
	}
	var x=parseFloat(document.getElementById("x").value);
	var y=parseFloat(document.getElementById("y").value);
	var wynik;
	var w=document.getElementById("wynik");
		switch(op)
		{
		case "add":
			wynik=x+y;
			break;
		case "sub":
			wynik=x-y;
			break;
		case "mul":
			wynik=x*y;
			break;
		case "div":
			if(y==0)
			{
				alert("Dzielenie przez zero!");
				return;
			}
			wynik=x/y;
			break;
		}
	
	if(isNaN(wynik) || !isFinite(wynik)){
		alert("Wprowadzono błędne dane");
		return;
	}
	w.value=wynik;
}
**/
$(document).ready(function(){
	$("main").css("background-color", "gray");
	$("input").css("font-weight", "bold");
	$(".zielony").css("background-color","#90EE90");
	$("#oblicz").click(function(){
		var tab = $('input[name="operator"]');
		var op;

		for(let i=0;i<tab.length;i++){
			if(tab[i].checked) op = tab[i].value;
		}
		
		var x=parseInt( $('#x').val() );
		var y=parseInt( $('#y').val() );
		var wynik;
		switch(op)
		{
		case "add":
			wynik=x+y;
			break;
		case "sub":
			wynik=x-y;
			break;
		case "mul":
			wynik=x*y;
			break;
		case "div":
			if(y==0)
			{
				alert("Dzielenie przez zero!");
				return;
			}
			wynik=x/y;
			break;
		}
		if (isNaN(wynik)) $('#wynik').val("Błędne dane");
		else $('#wynik').val(wynik);
	});
});