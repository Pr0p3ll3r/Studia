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
            $odp = filter_input(INPUT_POST, 'jezyki' , FILTER_SANITIZE_FULL_SPECIAL_CHARS, FILTER_REQUIRE_ARRAY);
            if(!empty($odp)) {            
                $tablicaDanych = file("ankieta.txt");
                $plik = fopen("ankieta.txt", "w");
                foreach($tablicaDanych as $linia) {
                    if ($linia == "") {
                        continue;
                    }       
                $linia = trim($linia, PHP_EOL);
                $tab = explode(":",$linia);
                    foreach($odp as $val) {
                        if($val == $tab[0]) {
                            $tab[1]++;
                        }
                    }
                    fwrite($plik, $tab[0].":".$tab[1].PHP_EOL);
                }
                fclose($plik);  
            }
        
            echo "<h2>Wyniki</h2>";
            $tablicaDanych = file("ankieta.txt");
            foreach($tablicaDanych as $linia) {
                echo "$linia<br>";
            }
        ?>
        <br><a href="ankieta.php">Powrót do formularza</a>
    </body>
</html>
