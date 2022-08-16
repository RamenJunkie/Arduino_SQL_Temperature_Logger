<?php
$MyUsername = "YOURSQLUSERNAME";  // enter your username for mysql
$MyPassword = "YOURPASSWOR?Ddg";  // enter your password for mysql
$MyHostname = "localhost";      // this is usually "localhost" unless your database resides on a different server

$dbh = mysql_pconnect($MyHostname , $MyUsername, $MyPassword);
$selected = mysql_select_db("housetemps",$dbh);
?>
