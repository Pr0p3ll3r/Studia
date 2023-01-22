<?php
    include_once "../klasy/Baza.php";
    $db = new Baza('localhost', 'root','','klienci');   
    echo $db->select('select Nazwisko,Zamowienie from klienci where Zamowienie regexp "^'.$_POST['jezyk'].'"', ["Nazwisko", "Zamowienie"]);


