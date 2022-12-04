<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Dane klienta</title>
    </head>
    <body>       
        <h4>Dane klienta </h4>
        <p> Nazwisko: <?php echo $_GET['lastname']; ?> <br/>
            Wiek: <?php echo $_GET['age']; ?> <br/>
            Kraj: <?php echo $_GET['country']; ?> <br/>
            Email: <?php echo $_GET['mail']; ?> <br/>
        </p>
    </body>
</html>
