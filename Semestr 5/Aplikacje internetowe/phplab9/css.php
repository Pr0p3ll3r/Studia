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
        <form action="css.php" method="post">
            <textarea name="tekst"></textarea><br />
            <input type="submit" name="wyslij" value="Wyślij" />
        </form>
        <div>
            <?php
            if (filter_input(INPUT_POST,'wyslij')){
                echo htmlspecialchars($_POST['tekst'])."<br>";//echo $_POST['tekst'];
                echo strip_tags($_POST['tekst'])."<br>";
                echo filter_input(INPUT_POST, 'tekst', FILTER_SANITIZE_FULL_SPECIAL_CHARS);
            }
            ?>
        </div>
    </body>
</html>
