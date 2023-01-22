<?php
    include_once "../klasy/Baza.php";
    $db = new Baza('localhost', 'root','','klienci');
    echo $db->select("select * from klienci", ["Email", "Zamowienie"]);