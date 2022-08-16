<?php
    // Start MySQL Connection
    include('dbconnect.php');
?>

<html>
<head>
    <title>Arduino Temperature Log</title>
    <style type="text/css">
        .table_titles, .table_cells_odd, .table_cells_even {
                padding-right: 20px;
                padding-left: 20px;
                color: #000;
        }
        .table_titles {
            color: #FFF;
            background-color: #666;
        }
        .table_cells_odd {
            background-color: #CCC;
        }
        .table_cells_even {
            background-color: #FAFAFA;
        }
        table {
            border: 2px solid #333;
        }
        body { font-family: "Trebuchet MS", Arial; }
    </style>
</head>

    <body>
        <h1>Arduino Temperature Log</h1>

	<p>Select Date: 
	<?php

		$sql = "SELECT DISTINCT datestamp FROM temperature ORDER BY datestamp DESC";
		$result = mysql_query($sql);

		echo "<select name='datestamp' onchange='location = this.options[this.selectedIndex].value;'";
		while ($row = mysql_fetch_array($result)) {
			$current = $row['datestamp'];
			echo "<option value='index.php?dateselect=$current'>$current</option>";
		}
		echo "</select>";
	?>

    <table border="0" cellspacing="0" cellpadding="4">
      <tr>
        <!--    <td class="table_titles">ID</td> -->
            <td class="table_titles">Date and Time</td>
            <td class="table_titles">Sensor Serial</td>
            <td class="table_titles">Temperature in Celsius</td>
	    <td class="table_titles">Percent Humidity</td>
          </tr>
<?php
    // Retrieve all records and display them
	$SQL = "SELECT * FROM temperature WHERE datestamp LIKE '".$_GET["dateselect"]."%' ORDER BY id ASC";
    
	//Execute the SQL
    $result = mysql_query($SQL);

    // Used for row color toggle
    $oddrow = true;

    // process every record
    while( $row = mysql_fetch_array($result) )
    {
        if ($oddrow)
        {
            $css_class=' class="table_cells_odd"';
        }
        else
        {
            $css_class=' class="table_cells_even"';
        }

        $oddrow = !$oddrow;

        echo '<tr>';
 //       echo '   <td'.$css_class.'>'.$row["id"].'</td>';
        echo '   <td'.$css_class.'>'.$row["event"].'</td>';
        echo '   <td'.$css_class.'>'.$row["sensor"].'</td>';
        echo '   <td'.$css_class.'>'.$row["celsius"].'</td>';
	echo '   <td'.$css_class.'>'.$row["humidity"].'</td>';
        echo '</tr>';
    }
?>
    </table>
    </body>
</html>
