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
        function pokaz() {
            $tablicazpliku = file("dane.txt");
            foreach($tablicazpliku as $linia)
            {
                echo "$linia<br>";
            }
        }
        
        function pokaz_zamowienie($tut) {
            $tablicazpliku = file("dane.txt");
            foreach($tablicazpliku as $linia)
            {
                $zam = explode(" ",$linia);
                $zam2 = explode(",", $zam[4]);
                foreach($zam2 as $tut1){
                    if($tut1 == $tut) {
                        echo "$linia<br>";                         
                    }
                }                 
            }      
        }
        
        function walidacja() {
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
                dopliku("dane.txt", $dane);
            } else {
                echo "<br>Nie poprawnie dane: " . $errors;
            }
        }

        function dodaj(){
            echo "<h3>Dodawanie do pliku:</h3>";
            walidacja();
        }

        function dopliku($nazwaPliku, $tablicaDanych) {
            $dane = "";
            foreach($tablicaDanych as $dana)
            {
                if (is_array($dana)) {
                    $dane .= implode(",", $dana). " ";
                } else {
                    $dane .= $dana . " ";
                }
            }         
            $dane.=PHP_EOL; //dodaj koniec linii za pomocą stałej HP
            $plik = fopen($nazwaPliku,"a");
            fwrite($plik, $dane);
            fclose($plik);  
            echo "<p>Zapisano: <br /> $dane</p>";
        }
        
        function statystyki() {
            $plik = file("dane.txt");
            $ile = count($plik);
            echo "Liczba wszystkich zamówień: $ile<br>";
            $ilePowyzej49 = 0;
            $ilePonizej18 = 0;
            foreach($plik as $linia)
            {
                $zam = explode(" ",$linia);
                if($zam[1] < 18)
                {
                    $ilePonizej18++;
                }
                if($zam[1] > 49)
                {
                    $ilePowyzej49++;
                }
            }
            echo "Liczba zamówień od osób w wieku < 18 lat: $ilePonizej18<br>";
            echo "Liczba zamówień od osób w wieku >= 50 lat: $ilePowyzej49";
        }
        ?>
    </body>
</html>
