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
            function download($patch = '.')
            {
                $katalog = @dir($patch) or die ('Brak dostępu do katalogu.');
                while ($plik_kat = $katalog->read())
                if(is_file($patch.'/'.$plik_kat))
                    echo '<a href="'.$patch.'/'.$plik_kat.'">'.$plik_kat.'</a><br />';
                else if (is_dir($patch.'/'.$plik_kat))
                {
                    echo '<a href="DirTrav.php?patch='.$patch.'/'.$plik_kat.'">'.$plik_kat.'</a><br />';
                }
                $katalog->close();
            }
            if (!isset($_GET['patch']))
                download();
            else
                download(str_replace('..','',$_GET['patch']));//download($_GET['patch']);
        ?>
    </body>
</html>
