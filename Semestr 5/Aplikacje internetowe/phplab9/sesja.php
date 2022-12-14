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
            session_start();
            if (!isset($_SESSION['our_own']))
            {
                session_regenerate_id();
                $_SESSION['our_own'] = true;
            }
            echo 'ID: '.session_id().'<br />';
            if (isset($_GET['PHPSESSID']))
                echo 'PHPSESSID: '.$_GET['PHPSESSID'].'<br />';
        ?>
    </body>
</html>
