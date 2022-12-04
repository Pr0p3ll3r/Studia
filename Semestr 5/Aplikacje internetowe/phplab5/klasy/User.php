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
    public function setUserName($username) {
        $this->username=$username;
    }
    public function getUserName() {
        return $this->username;
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
    
    static function getAllUsers($plik){
        $tab = json_decode(file_get_contents($plik));
        //var_dump($tab);
        foreach ($tab as $val){
            echo "<p>".$val->userName." ".$val->fullName." ".$val->date."
            </p>";
        }
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
    
    function save($plik){
        $tab = json_decode(file_get_contents($plik),true);
        array_push($tab,$this->toArray());
        file_put_contents($plik, json_encode($tab));
    }
    
    function saveXML($plik){
        $xml = simplexml_load_file('users.xml');
        $xmlCopy=$xml->addChild("user");
        $xmlCopy->addChild("userName", $this->userName);
        $xmlCopy->addChild("passwd", $this->passwd);
        $xmlCopy->addChild("fullName", $this->fullName);
        $xmlCopy->addChild("email", $this->email);
        $xmlCopy->addChild("date", $this->date);
        $xmlCopy->addChild("status", $this->status);
        $xml->asXML('users.xml');
    }
    
    static function getAllUsersFromXML($plik){
        $allUsers = simplexml_load_file('users.xml');
        echo "<ul>";
        foreach ($allUsers as $user):
            $userName=$user->userName;
            $fullName=$user->fullName;
            $date=$user->date;
            echo "<li>$userName, $fullName, $date </li>";
        endforeach;
        echo "</ul>";
    }       
}
