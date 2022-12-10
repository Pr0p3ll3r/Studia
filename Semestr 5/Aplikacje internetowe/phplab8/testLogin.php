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
            include_once('klasy/UserManager.php');
            include_once('klasy/Baza.php');         
            $db = new Baza("localhost", "root", "", "klienci");
            $um = new UserManager();
            session_start();
            $userId = $um->getLoggedInUser($db, session_id());
            if($userId >= 0){
                $sql = "SELECT * FROM users WHERE id='$userId'";
                if ($result = $db->getMysqli()->query($sql)) {
                    $row = $result->fetch_object(); //pobierz rekord z użytkownikiem
                    echo"<a href='processLogin.php?akcja=wyloguj'>Wyloguj</a>";
                    echo"<h3>Dane zalogowanego użytkownika:</h3>";
                    echo"$row->userName $row->fullName $row->email";
                }
            }
            else {
                header("location:processLogin.php");
            }
        ?>
    </body>
</html>
