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
        <?php
            //wykorzystaj lekko zmodyfikowane wcześniej tworzone funkcje
            //pomocnicza funkcja generująca formularz:
            function drukuj_form() {
                $zawartosc = '<div id="tresc">
                <form action="?strona=formularz" method="POST" >
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
                        foreach($jezyki as $klucz) 
                        {
                            $zawartosc .= '<label><input type="checkbox" name="jezyki[]" value="' . $klucz . '">' . $klucz .'</input></label>';
                        }
                        $zawartosc .= '<h4>Sposób zapłaty:</h4>
                               <input type="radio" id="ec" name="zaplata" value="eurocard" /> <label for="ec">eurocard </label>
                               <input type="radio" id="v" name="zaplata" value="visa" /> <label for="v">visa </label>
                               <input type="radio" id="pb" name="zaplata" value="przelew" /> <label for="pb">przelew bankowy </label><br> 
                            <input type="submit" name="submit" value="Dodaj" />
                            <input type="submit" name="submit" value="Pokaż" />
                            <input type="submit" name="submit" value="PHP" />
                            <input type="submit" name="submit" value="CPP" />
                            <input type="submit" name="submit" value="Java" />
                            <input type="submit" name="submit" value="Statystyki" />  
                            <input type="reset" value="Wyczyść" />
                    </form>
                </div> ';
                return $zawartosc;
            }
            function dodajdoBD($bd){
                $args = ['nazw' => ['filter' => FILTER_VALIDATE_REGEXP,
                                    'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/']
                                    ],
                        'wiek' => ['filter' => FILTER_VALIDATE_REGEXP,
                                    'options' => ['regexp' => '/^[0-9]+$/']
                                    ],
                        'mail' => FILTER_VALIDATE_EMAIL,
                        'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
                        'jezyki' => ['filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
                                'flags' => FILTER_REQUIRE_ARRAY],
                        'zaplata' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
                ];
                //przefiltruj dane z GET/POST zgodnie z ustawionymi w $args filtrami:
                $dane = filter_input_array(INPUT_POST, $args);
                //pokaż tablicę po przefiltrowaniu - sprawdź wyniki filtrowania:
                var_dump($dane);
                //Sprawdź czy dane w tablicy $dane nie zawierają błędów walidacji:
                $errors = "";
                foreach ($dane as $key => $val) {
                    if ($val === false or $val === NULL) {
                        $errors .= $key . " ";
                    }
                }
                if ($errors === "") {  
                    $sql = "INSERT INTO klienci (Nazwisko, Wiek, Panstwo, Email, Zamowienie, Platnosc) VALUES ('".$dane['nazw']."','".$dane['wiek']."','".$dane['kraj']."'"
                            . ",'".$dane['mail']."','".implode(",",array_values($dane['jezyki']))."','".$dane['zaplata']."')";
                    if($bd->insert($sql)) print("<br>Dane zostały wpisane");
                    else print("Błąd podczas wpisywania danych");
                } else {
                    echo "<br>Nie poprawnie dane: " . $errors;
                }
            }
            function statystyki($bd) {
                $zawartosc = "";
                if ($result = $bd->getMysqli()->query("select Wiek from klienci")) 
                { 
                    $ile = $result->num_rows; //ile wierszy
                    $zawartosc .= "Liczba wszystkich zamówień: $ile<br>";
                    $ilePowyzej49 = 0;
                    $ilePonizej18 = 0;              
                    while ($row = $result->fetch_object()) {
                        if($row->Wiek < 18)
                        {
                            $ilePonizej18++;
                        }
                        if($row->Wiek > 49)
                        {
                            $ilePowyzej49++;
                        }
                    }
                    $result->close(); /* zwolnij pamięć */
                    $zawartosc .= "Liczba zamówień od osób w wieku < 18 lat: $ilePonizej18<br>";
                    $zawartosc .= "Liczba zamówień od osób w wieku >= 50 lat: $ilePowyzej49";
                } 
                return $zawartosc;
            }
            
            //uchwyt do bazy klienci:
            include_once "klasy/Baza.php";
            $tytul = "Formularz zamowienia";
            $zawartosc = drukuj_form();
            $bd = new Baza("localhost", "root", "", "klienci");
            if (filter_input(INPUT_POST, "submit")) {
                $akcja = filter_input(INPUT_POST, "submit");
                switch ($akcja) {
                    case "Dodaj": dodajdoBD($bd); break;
                    case "Pokaż": $zawartosc .= $bd->select("select * from klienci",["Email", "Zamowienie"]); break;                             
                    case "PHP": $zawartosc .= $bd->select("select Nazwisko,Zamowienie from klienci where Zamowienie regexp '^PHP'", ["Nazwisko","Zamowienie"]); break;   
                    case "CPP": $zawartosc .= $bd->select("select Nazwisko,Zamowienie from klienci where Zamowienie regexp '^CPP'", ["Nazwisko","Zamowienie"]); break;            
                    case "Java": $zawartosc .= $bd->select("select Nazwisko,Zamowienie from klienci where Zamowienie regexp '^Java'", ["Nazwisko","Zamowienie"]); break;   
                    case "Statystyki": $zawartosc .= statystyki($bd); break;
                }
            }
        ?>
    </body>
</html>
