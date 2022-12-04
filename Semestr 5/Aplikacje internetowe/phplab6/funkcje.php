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
        function pokaz($bd) {
            echo $bd->select("select Nazwisko,Zamowienie from klienci", ["Nazwisko","Zamowienie"]);
        }
        
        function pokaz_zamowienie($bd, $tut) {
            echo $bd->select("select Nazwisko,Zamowienie from klienci where Zamowienie regexp '^$tut'", ["Nazwisko","Zamowienie"]);      
        }
        
        function statystyki($bd) {
            if ($result = $bd->getMysqli()->query("select Wiek from klienci")) 
            { 
                $ile = $result->num_rows; //ile wierszy
                echo "Liczba wszystkich zamówień: $ile<br>";
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
                echo "Liczba zamówień od osób w wieku < 18 lat: $ilePonizej18<br>";
                echo "Liczba zamówień od osób w wieku >= 50 lat: $ilePowyzej49";
            }                     
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
        ?>
    </body>
</html>
