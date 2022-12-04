<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Galeria</title>
    </head>
    <body>
        <?php
        function galeria($rows, $cols)
        {
            print("<table>");
            $nazwa='obraz';
            $numer=1;
            for($i=0;$i<$rows;$i++)
            {
               print("<tr>");
               for($j=0;$j<$cols;$j++)
               {               
                    print("<th><img src='obrazki/$nazwa$numer.JPG' alt='$nazwa$numer' /></th>");
                    $numer++;
               } 
               print("</tr>");
            }
            print("</table>");
        }
        galeria(3,3);
        ?>
    </body>
</html>
