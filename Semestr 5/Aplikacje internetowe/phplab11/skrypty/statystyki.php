<?php
    include_once "../klasy/Baza.php";
    $db = new Baza('localhost', 'root','','klienci');
    $zawartosc = "";
    if ($result = $db->getMysqli()->query("select Wiek from klienci")) {
        $ile = $result->num_rows; //ile wierszy
        $zawartosc .= "Liczba wszystkich zamówień: $ile<br>";
        $ilePowyzej49 = 0;
        $ilePonizej18 = 0;
        while ($row = $result->fetch_object()) {
            if ($row->Wiek < 18) {
                $ilePonizej18++;
            }
            if ($row->Wiek > 49) {
                $ilePowyzej49++;
            }
        }
        $result->close(); /* zwolnij pamięć */
        $zawartosc .= "Liczba zamówień od osób w wieku < 18 lat: $ilePonizej18<br>";
        $zawartosc .= "Liczba zamówień od osób w wieku >= 50 lat: $ilePowyzej49";
    }
    echo $zawartosc;
