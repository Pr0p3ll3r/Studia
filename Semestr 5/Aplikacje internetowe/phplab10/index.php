<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Project/PHP/PHPProject.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            require_once("klasy/strona.php");
            $strona_akt = new Strona();
            //sprawdź co wybrał użytkownik:
            if (filter_input(INPUT_GET, 'strona')) {
                $strona = filter_input(INPUT_GET, 'strona');
                switch ($strona) {
                    case 'galeria':$strona = 'galeria'; break;
                    case 'formularz':$strona = 'formularz'; break;
                    case 'onas':$strona = 'onas'; break;
                    default:$strona = 'glowna';
                }
            } else {
                $strona = "glowna";
            }
            $plik = "skrypty/" . $strona . ".php";
            if (file_exists($plik)) {
                require_once($plik);
                $strona_akt->ustaw_tytul($tytul);
                $strona_akt->ustaw_zawartosc($zawartosc);
                $strona_akt->wyswietl();
            }
        ?>
    </body>
</html>
