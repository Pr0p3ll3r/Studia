<?php

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/PHPClass.php to edit this template
 */

/**
 * Description of UserManager
 *
 * @author Kuba
 */
class UserManager {
    function loginForm() {
        ?>
        <h3>Formularz logowania</h3><p>
        <form action="processLogin.php" method="post">
        <table>
                <tr>
                    <td>
                        <label>Login: <input type="text" id="login" name="login"/></label>
                    </td>	
		</tr>
		<tr>
                    <td>
                        <label>Hasło: <input type="password" id="passwd" name="passwd"/></label>
                    </td>
		</tr>
		<tr>     
        </table>
        <input type="submit" value="Zaloguj" name="zaloguj" />
        <input type="reset" value="Anuluj"/>
        </form></p> <?php
    }
    function login($db) {
        //funkcja sprawdza poprawność logowania
        //wynik - id użytkownika zalogowanego lub -1
        $args = [
            'login' => FILTER_SANITIZE_ADD_SLASHES,
            'passwd' => FILTER_SANITIZE_ADD_SLASHES
            ];
        //przefiltruj dane z GET (lub z POST) zgodnie z ustawionymi w $args filtrami:
        $dane = filter_input_array(INPUT_POST, $args);
        //sprawdź czy użytkownik o loginie istnieje w tabeli users
        //i czy podane hasło jest poprawne
        $login = $dane["login"];
        $passwd = $dane["passwd"];
        $userId = $db->selectUser($login, $passwd, "users");
        if ($userId >= 0) { //Poprawne dane
            session_start();
            //usuń wszystkie wpisy historyczne dla użytkownika o $userId
            $sql = "DELETE FROM logged_in_users WHERE userId=$userId";
            $db->delete($sql);
            //ustaw datę - format("Y-m-d H:i:s");
            $date = date("Y-m-d H:i:s");
            //pobierz id sesji i dodaj wpis do tabeli logged_in_users
            $id = session_id();
            $sql = "INSERT INTO logged_in_users VALUES ('$id', '$userId', '$date')";
            $db->insert($sql);
        }
        return $userId;
    }
    function logout($db) {
        session_start();
        $id = session_id();
        $_SESSION = [];
        if (filter_input( INPUT_COOKIE,session_name() )) {
            setcookie(session_name(), '', time() - 42000, '/'); }
        session_destroy();       
        $sql = "DELETE FROM logged_in_users WHERE sessionId='$id'";
        $db->delete($sql);
    }
    function getLoggedInUser($db, $sessionId) {
        //wynik $userId - znaleziono wpis z id sesji w tabeli logged_in_users
        //wynik -1 - nie ma wpisu dla tego id sesji w tabeli logged_in_users
        $userId = -1;
        $sql = "SELECT * FROM logged_in_users WHERE sessionId='$sessionId'";
        if ($result = $db->getMysqli()->query($sql)) {
            $ile = $result->num_rows;
            if ($ile == 1) {
                $row = $result->fetch_assoc(); //pobierz rekord z użytkownikiem
                $userId = $row['userId'];
            }
        }
        return $userId;         
    }
}
