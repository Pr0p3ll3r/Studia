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
            include_once 'klasy/Baza.php';
            include_once 'klasy/User.php';
            include_once 'klasy/UserManager.php';
            $db = new Baza("localhost", "root", "", "klienci");
            $um = new UserManager();
            //parametr z GET – akcja = wyloguj
            if (filter_input(INPUT_GET, "akcja")=="wyloguj") {
                $um->logout($db);
            }
            //kliknięto przycisk submit z name = zaloguj
            if (filter_input(INPUT_POST, "zaloguj")) {
                if($um->getLoggedInUserById($db)){
                    echo "<p>Użytkownik jest już zalogowany</p>";
                    $um->loginForm(); //Pokaż formularz logowania
                }
                else
                {
                    $userId=$um->login($db); //sprawdź parametry logowania
                    if ($userId > 0) {
                        header("location:testLogin.php");
                    } else {
                        echo "<p>Błędna nazwa użytkownika lub hasło</p>";
                        $um->loginForm(); //Pokaż formularz logowania
                    }
                }
            } else {
                session_start();
                $userId = $um->getLoggedInUserBySession($db, session_id());
                if($userId >= 0){
                    header("location:testLogin.php");
                }
                else{
                    $um->loginForm();
                }
            }
        ?>
    </body>
</html>
