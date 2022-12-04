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
        <h2>Wybierz technologie, które znasz:</h2>
	<form action="wyniki.php" method="POST">
        <?php
            $tech = ["C", "CPP", "Java", "C#", "Html", "CSS", "XML", "PHP", "JavaScript"];
            foreach($tech as $val) 
            {
                print ("<input type='checkbox' name='jezyki[]' value=$val>$val</input><br>");
            }
        ?>
        <input type="submit" value="Wyślij" />   
        </form>
        <?php
            if (!(file_exists("ankieta.txt"))) {
                $plik=fopen("ankieta.txt","w+");
                foreach($tech as $val)
                {
                    fwrite($plik, $val.":0\n");
                }
                fclose($plik);              
            }
        ?>         
    </body>
</html>
