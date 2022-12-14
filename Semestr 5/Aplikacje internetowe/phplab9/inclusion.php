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
            if (isset($_GET['plik']))
            {
                $plik=str_replace('\\','/',$_GET['plik']);
                $plik=str_replace('.','/',$plik);
                $filearr=explode('/',$plik);
                $plik=$filearr[count($filearr)-1];
                include($plik.'.txt');
            }
            else
                echo 'Nie podano pliku!';
        ?>
    </body>
</html>
