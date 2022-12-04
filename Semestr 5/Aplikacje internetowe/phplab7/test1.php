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
        $user = new User('kubus', 'Kubus Puchatek','kubus@stumilowylas.pl', '');
        $user->setStatus('ADMIN');
        $_SESSION['user'] = serialize($user);
        echo "<h2>Id sesji: ". session_id()."</h2><hr>";
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
        echo "<hr></h3>";
        echo "<a href='test2.php'>Przejdź do strony 2</a>";
        ?>
    </body>
</html>
