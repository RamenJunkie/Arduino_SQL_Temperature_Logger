<?php
    // Connect to MySQL
    include('dbconnect.php');

    {
	$dateget = date("Y-m-d");
    	// Prepare the SQL statement
 	   $SQL = "INSERT INTO housetemps.temperature (sensor ,celsius, humidity, datestamp) VALUES ('".$_GET["serial"]."', '".$_GET["temperature"]."', '".$_GET["humid"]."', '$dateget')";

 	   // Execute SQL statement
 	   mysql_query($SQL);
    }

    // Go to the review_data.php (optional)
    header("Location: index.php");
?>
