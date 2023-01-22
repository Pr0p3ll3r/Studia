<?php
    include_once "../klasy/Baza.php";
    $db = new Baza('localhost', 'root','','klienci');
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
        $sql = "INSERT INTO klienci (Nazwisko, Wiek, Panstwo, Email, Zamowienie, Platnosc) VALUES ('" . $dane['nazw'] . "','" . $dane['wiek'] . "','" . $dane['kraj'] . "'"
                . ",'" . $dane['mail'] . "','" . implode(",", array_values($dane['jezyki'])) . "','" . $dane['zaplata'] . "')";
        if ($db->insert($sql)){
            echo "<br>Dane zostały wpisane";
        }
        else{
            print "Błąd podczas wpisywania danych";
        }
    } else {
        echo "<br>Nie poprawnie dane: " . $errors;
    }