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
	<form action="odbierz4.php" method="POST">
            <table>
                <tr>
                    <td><label for="lastname">Nazwisko:</label></td>
                    <td><input type="text" id="lastname" name="lastname"/></td>	
		</tr>
		<tr>
                    <td><label for="age">Wiek:</label></td>
                    <td><input type="text" id="age" name="age"/></td>
		</tr>
		<tr>
                    <td><label for="country">Państwo:</label></td>
                    <td><select size="1" id="country" name="country">
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
                    <input type="radio" id="ec" name="method" value="eurocard" /> <label for="ec">eurocard </label>
                    <input type="radio" id="v" name="method" value="visa" /> <label for="v">visa </label>
                    <input type="radio" id="pb" name="method" value="przelew bankowy" /> <label for="pb">przelew bankowy </label><br>
                    <input type="submit" value="Wyślij" />
                    <input type="reset" value="Anuluj" />		
		</form>
    </body>
</html>
