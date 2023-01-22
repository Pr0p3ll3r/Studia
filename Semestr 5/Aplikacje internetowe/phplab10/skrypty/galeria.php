<?php
    $tytul = "Galeria";
    $zawartosc = "<table>";
    $nazwa = 'obraz';
    $numer = 1;
    for ($i = 0; $i < 2; $i++) {
        $zawartosc .= "<tr>";
        for ($j = 0; $j < 5; $j++) {
            $zawartosc .= "<th><img src='zdjecia/$nazwa$numer.JPG' alt='$nazwa$numer' /></th>";
            $numer++;
        }
        $zawartosc .= "</tr>";
    }
    $zawartosc .= "</table>";
?>