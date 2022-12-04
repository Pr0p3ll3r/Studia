<?php

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/PHPClass.php to edit this template
 */

/**
 * Description of RegistrationForm
 *
 * @author student
 */
class RegistrationForm {
    protected $user;
    function __construct(){ 
        ?>
            <h3>Formularz rejestracji</h3><p>
            <form action="index.php" method="post">
            Nazwa użytkownika: <br/><input name="userName" /><br/>
            Imię i nazwisko: <br/><input name="fullName" /><br/>
            Hasło: <br/><input name="passwd" type="password" /><br/>
            Email: <br/><input name="email" />
            <input type="submit" name="submit" value="Rejestruj"/><input type="reset" value="Anuluj"/>
            </form></p>
        <?php
    }
    function checkUser($db){
        $args = [
        'userName' => ['filter' => FILTER_VALIDATE_REGEXP,
        'options' => ['regexp' => '/^[a-zA-Z0-9]{5,}$/']
        ],
        'fullName' => ['filter' => FILTER_VALIDATE_REGEXP,
        'options' => ['regexp' => '/^[A-Za-ząęłńśćźżó-]+([\ A-Za-ząęłńśćźżó-]+)*$/']
        ],
        'passwd' => ['filter' => FILTER_VALIDATE_REGEXP,
        'options' => ['regexp' => '/^[0-9A-Za-z#?!@$%^&*_-]{8,}/']
        ],
        'email' => FILTER_VALIDATE_EMAIL,
        ];
        //przefiltruj dane:
        $errors = "";
        $dane = filter_input_array(INPUT_POST, $args);
        foreach ($dane as $key => $val) {
            if ($val === false or $val === NULL) {
                $errors .= $key . " ";
            }
        }
        if ($errors === "") {
        //Dane poprawne – utwórz obiekt user
            $this->user=new User($dane['userName'], $dane['fullName'],
            $dane['email'],$dane['passwd']);
            $this->user->saveDB($db);
        } else {
            echo "<p>Błędne dane:$errors</p>";
            $this->user = NULL;
        }
        return $this->user;
    }
}
