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
            include_once 'Baza.php';
            $ob = new Baza('localhost','root','','test');
            if (isset($_POST['id']))
                if ($ob->delete('DELETE FROM strony WHERE id="'.$ob->protect_int($_POST['id']).'"'))
                    echo 'Skasowano rekord o id='.$_POST['id'];
            else
                echo 'Nie można skasować rekordu!';
        ?>
    </body>
</html>
