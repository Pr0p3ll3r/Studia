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
                $lastname = htmlspecialchars(trim($_REQUEST['lastname']));
            } 
            else echo "Nie wpisano nazwiska <br />";
            if (isset($_REQUEST['age']) && ($_REQUEST['age'] != "")) {
                $age = htmlspecialchars(trim($_REQUEST['age']));
            } 
            else echo "Nie wpisano wieku <br />";
            if (isset($_REQUEST['country']) && ($_REQUEST['country'] != "")) {
                $country = htmlspecialchars(trim($_REQUEST['country']));
            } 
            else echo "Nie wpisano kraju <br />";
            if (isset($_REQUEST['mail']) && ($_REQUEST['mail'] != "")) {
                $mail = htmlspecialchars(trim($_REQUEST['mail']));
            } 
            else echo "Nie wpisano emaila <br />";                            
            if (isset($_REQUEST['jezyki']) && ($_REQUEST['jezyki'] != "")) {
                echo "Wybrano tutoriale: ";
                foreach($_REQUEST['jezyki'] as $key=>$value) 
                {
                    print ("$value ");
                } 
                echo "<br>";
            } 
            else echo "Nie wybrano tutoriali<br>";   
            //$jezyki = htmlspecialchars(join(" ",$_REQUEST['jezyki']));
            //echo "$jezyki";
            if (isset($_REQUEST['method']) && ($_REQUEST['method'] != "")) {
                $metoda = htmlspecialchars(trim($_REQUEST['method']));
                echo "Sposób zapłaty: $metoda <br />";
            }
            else echo "<br>Nie wybrano metody płatności <br />";
            if($_REQUEST['lastname'] != "" && $_REQUEST['age'] != "" && $_REQUEST['country'] != "" && $_REQUEST['mail'] != "")
                echo "<h3><a href='klient.php?lastname=$lastname&age=$age&country=$country&mail=$mail'>Dane klienta</a></h3>";           
            echo "<a href='formularz.php'>Powrót do formularza </a>";           
        ?>
    </body>
</html>
