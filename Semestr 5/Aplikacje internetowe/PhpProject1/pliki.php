<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <h2>Formularz zamówienia</h2>
	<form action="pliki.php" method="POST">
            <table>
                <tr>
                    <td><label for="nazw">Nazwisko:</label></td>
                    <td><input type="text" id="nazw" name="nazw"/></td>	
		</tr>
		<tr>
                    <td><label for="wiek">Wiek:</label></td>
                    <td><input type="text" id="wiek" name="wiek"/></td>
		</tr>
		<tr>
                    <td><label for="kraj">Państwo:</label></td>
                    <td><select size="1" id="kraj" name="kraj">
			<option value="Polska">Polska</option>
			<option value="Niemcy">Niemcy</option>
			<option value="Hiszpania">Hiszpania</option></select></td>
		</tr>
                <tr>
                    <td><label for="mail">Adres e-mail:</label></td>
                    <td><input type="text" id="mail" name="mail"/></td>
		</tr>						
		</table>
        <?php
            $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
            echo "<h4>Zamawiam tutorial z języka:</h4>";
            foreach($jezyki as $klucz) 
            {
                print ("<input type='checkbox' name='jezyki[]' value=$klucz>$klucz</input>");
            }
        ?>
            <h4>Sposób zapłaty:</h4>
                   <input type="radio" id="ec" name="zaplata" value="eurocard" /> <label for="ec">eurocard </label>
                   <input type="radio" id="v" name="zaplata" value="visa" /> <label for="v">visa </label>
                   <input type="radio" id="pb" name="zaplata" value="przelew bankowy" /> <label for="pb">przelew bankowy </label><br>
               <input type="reset" value="Wyczyść" />
               <input type="submit" name="submit" value="Zapisz" />
               <input type="submit" name="submit" value="Pokaż" />
               <input type="submit" name="submit" value="PHP" />
               <input type="submit" name="submit" value="CPP" />
               <input type="submit" name="submit" value="Java" />
               <input type="submit" name="submit" value="Statystyki" />           		
        </form>
        <?php
        include_once ("funkcje.php");
        //obsługa akcji (żądań):
        if (filter_input(INPUT_POST, "submit")) {
            $akcja = filter_input(INPUT_POST, "submit");
            switch ($akcja) {
                case "Zapisz":dodaj();break;
                case "Pokaż":pokaz();break;
                case "PHP":pokaz_zamowienie("PHP");break;
                case "CPP":pokaz_zamowienie("CPP");break;           
                case "Java":pokaz_zamowienie("Java");break;  
                case "Statystyki":statystyki();break;
                }
            }
        ?>
    </body>
</html>
