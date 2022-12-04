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
        include ('klasy/User.php');
        echo "<h2>Id sesji: ". session_id()."</h2><hr>";
        if (isset($_SESSION['user'])) {
            $user_z_sesji = unserialize($_SESSION['user']);
            echo "username: ".$user_z_sesji->getUserName()."<br>";
            echo "fullname: ".$user_z_sesji->getFullName()."<br>";
            echo "email: ".$user_z_sesji->getEmail()."<br>";
            echo "status: ".$user_z_sesji->getStatus()."<br>";        
            echo "<hr><h3>Ciasteczka: <br>";
            foreach($_COOKIE as $key => $value)
            {
                echo "$key: $value<br>";
            }
        }
        /*
        if (isset($_COOKIE[session_name()])){
            setcookie(session_name(),'', time() - 42000, '/');
        }
        */
        session_destroy();
        echo "<hr></h3>";
        echo "<a href='test1.php'>Przejdź do strony 1</a>";
        ?>
    </body>
</html>
