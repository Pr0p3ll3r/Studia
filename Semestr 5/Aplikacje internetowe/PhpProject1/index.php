<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Project/PHP/PHPProject.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Pierwszy skrypt w PHP</title>
    </head>
    <body>
        <?php
        echo "<h2>Pierwszy skrypt PHP</h2>";
        $n=4567;
        $x=10.123456789;
        echo "Domyślny format: n=$n, x=$x<br> Zaokrąglenie do liczby całkowitej x=".round($x).",<br>";
        printf("z trzema cyframi po kropce x=%.3f",$x);
        ?>
    </body>
</html>
