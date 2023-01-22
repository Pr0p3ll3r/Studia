<?php
echo "<h1>Formularz zamowienia</h1>";
echo '<div> <form method="post" id="formZamowienia">
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
                            <h4>Zamawiam tutorial z języka:</h4>';
    $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
    foreach ($jezyki as $klucz) {
        echo '<label><input type="checkbox" name="jezyki[]" value="' . $klucz . '">' . $klucz . '</input></label>';
    }
    echo '<h4>Sposób zapłaty:</h4>
                        <input type="radio" id="ec" name="zaplata" value="eurocard" /> <label for="ec">eurocard </label>
                        <input type="radio" id="v" name="zaplata" value="visa" /> <label for="v">visa </label>
                        <input type="radio" id="pb" name="zaplata" value="przelew" /> <label for="pb">przelew bankowy </label><br> 
                    <input type="submit" value="Dodaj" />
                    <input type="button" id="pokaz" value="Pokaż" />
                    <input type="button" id="PHP" value="PHP"/>
                    <input type="button" id="CPP" value="CPP" />
                    <input type="button" id="Java" value="Java" />
                    <input type="button" id="statystyki" value="Statystyki" />  
                    <input type="reset" value="Wyczyść" />
                    </div> </form> <div id="daneFormularz"></div>';