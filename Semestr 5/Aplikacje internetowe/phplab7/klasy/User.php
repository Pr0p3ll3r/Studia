<?php

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/PHPClass.php to edit this template
 */

/**
 * Description of User
 *
 * @author student
 */
class User {
    
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;
    
    protected $userName;
    protected $passwd;
    protected $fullName;
    protected $email;
    protected $date;
    protected $status;
    function __construct($userName, $fullName, $email, $passwd)
    {
        $this->userName=$userName;
        $this->passwd= password_hash($passwd, PASSWORD_DEFAULT);
        $this->fullName=$fullName;
        $this->email=$email;
        $this->date=(new DateTime())->format('Y-m-d');
        $this->status=User::STATUS_USER;
    }
    public function show() {
        echo "$this->userName $this->fullName $this->email status: $this->status $this->date<br>";
    }
    public function setUserName($userName) {
        $this->userName=$userName;
    }
    public function getUserName() {
        return $this->userName;
    }
    public function getPasswd() {
        return $this->passwd;
    }

    public function getFullName() {
        return $this->fullName;
    }

    public function getEmail() {
        return $this->email;
    }

    public function getDate() {
        return $this->date;
    }

    public function getStatus() {
        return $this->status;
    }

    public function setPasswd($passwd): void {
        $this->passwd = $passwd;
    }

    public function setFullname($fullName): void {
        $this->fullName = $fullName;
    }

    public function setEmail($email): void {
        $this->email = $email;
    }

    public function setDate($date): void {
        $this->date = $date;
    }

    public function setStatus($status): void {
        $this->status = $status;
    }
    
    function toArray(){
        $arr=[
        "userName" => $this->userName,
        "passwd" => $this->passwd,
        "fullName" => $this->fullName,  
        "email" => $this->email,
        "date" => $this->date,
        "status" => $this->status
        ];
        return $arr;
    }
    
    function saveDB($db){ 
        $dane = $this->toArray();
        $sql = "INSERT INTO users (userName, fullName, email, passwd, status, date) VALUES ('".$dane['userName']."','".$dane['fullName']."','".$dane['email']."'"
                . ",'".$dane['passwd']."','".$dane['status']."','".$dane['date']."')";
        if($db->insert($sql)) print("<br>Dane zostały wpisane");
        else print("Błąd podczas wpisywania danych");
    }
    
    static function getAllUsersFromDB($bd){
        echo "Dane z bazy danych:";
        echo $bd->select("select userName,fullName,email,passwd,status,date from users", ["userName","fullName","email","passwd","status","date"]);
    }
}
