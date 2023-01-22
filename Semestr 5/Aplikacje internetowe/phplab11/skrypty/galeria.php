<?php
    echo "<h1>Galeria</h1>";
    echo "<table>";
    $nazwa='obraz';
    $numer=1;
    for($i=0;$i<2;$i++)
        {
            echo "<tr>";
            for($j=0;$j<5;$j++)
            {               
                echo "<th><img src='zdjecia/$nazwa$numer.JPG' alt='$nazwa$numer' /></th>";
                $numer++;
            } 
            echo "</tr>";
        }
    echo "</table>";