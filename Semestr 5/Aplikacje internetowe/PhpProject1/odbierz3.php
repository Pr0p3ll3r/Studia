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
                    echo "<h2>Dane odebrane z formularza</h2>";
            if (isset($_REQUEST['lastname']) && ($_REQUEST['lastname'] != "")) {
                $nazwisko = htmlspecialchars(trim($_REQUEST['lastname']));
                echo "Nazwisko: $nazwisko <br />";
            } 
            else echo "Nie wpisano nazwiska <br />";
            if (isset($_REQUEST['age']) && ($_REQUEST['age'] != "")) {
                $wiek = htmlspecialchars(trim($_REQUEST['age']));
                echo "Wiek: $wiek <br />";
            } 
            else echo "Nie wpisano wieku <br />";
            if (isset($_REQUEST['country']) && ($_REQUEST['country'] != "")) {
                $kraj = htmlspecialchars(trim($_REQUEST['country']));
                echo "Kraj: $kraj <br />";
            } 
            else echo "Nie wpisano kraju <br />";
            if (isset($_REQUEST['mail']) && ($_REQUEST['mail'] != "")) {
                $mail = htmlspecialchars(trim($_REQUEST['mail']));
                echo "Email: $mail <br />";
            } 
            else echo "Nie wpisano emaila <br />";
            echo "Wybrano tutoriale: ";
            foreach($_REQUEST['jezyki'] as $key=>$value) 
            {
                print ("$value ");
            }          
            //$jezyki = htmlspecialchars(join(" ",$_REQUEST['jezyki']));
            //echo "$jezyki";
            if (isset($_REQUEST['method']) && ($_REQUEST['method'] != "")) {
                $metoda = htmlspecialchars(trim($_REQUEST['method']));
                echo "<br>Sposób zapłaty: $metoda <br />";
            }
            else echo "<br>Nie wybrano metody płatności <br />";
            echo "<br><a href='formularz.php'>Powrót do formularza </a>";           
        ?>
    </body>
</html>
