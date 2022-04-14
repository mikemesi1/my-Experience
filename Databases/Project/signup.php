<!doctype html>
<html>
<head>
</head>
<body>
<<<<<<< Updated upstream
<form method="post" Action="http://students.cs.niu.edu/~z1910007/signup.php">
=======

<form method="post" Action="http://students.cs.niu.edu/~z1910569/signup.php">

>>>>>>> Stashed changes
    <input type="text" id="input" name="input"><br>
    <input type="radio" id="song" name="search" value="0">
    <label for="song">Songs</label><br>
    <input type="radio" id="band" name="search" value="1">
    <label for="band">Bands</label><br>
    <input type="radio" id="artist" name="search" value="2">
    <label for="artist">Artists</label><br>
    <input type="submit">
    <br/>
</form>

<form method="post" action="http://students.cs.niu.edu/~z1910007/signup.php">
<?php
// setting user and pass for connection
$username = "z1910569";
$password = "1999Jul20";
function draw_table($rows)
{
echo "<table border=1 cellspacing=1>";
echo"<tr>";
foreach($rows[0] as $key=>$p)
{
echo "<th>$key</th>";
}
echo "</tr>";
foreach($rows as $row)
{
echo "<tr>";
foreach($row as $key=>$item)
{
echo "<td> $item</td>";
}
echo "</tr>";
}
echo "</table>";
}
try {
    // setup pdo connection
    $dsn = "mysql:host=courses;dbname=z1910569";
    $pdo = new PDO($dsn, $username, $password);
    $pdo -> setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

    if(isset($_POST["input"]))
    {
        $search = $_POST["input"];
	$search = addslashes($search);
        $files;
        // Search for song
	if(isset($_POST["search"]) && $_POST["search"] == "0")
        {
	    $search = '%' . $search . '%';
	    echo "Searching Song...";	    // Check if input is set, otherwise use entire list
	    echo "<br>";
	    if ($search == NULL)
            {
                $sql = "SELECT * FROM Song";
            }
            else
            {
                $sql = "SELECT * FROM Song WHERE SongName LIKE '$search'";
            }
            $result = $pdo->query($sql);
            $rows = $result->fetchAll(PDO::FETCH_ASSOC);
            // Output list of
            for ($i = 0; $i < sizeof($rows); $i++)
	    {
                echo $rows[$i]["SongName"];
                echo "<br/>";

		// Output each file version
		$Song = $rows[$i]["SongID"];
		$sql = "SELECT * FROM File WHERE SongID = '1'";
	       	$result = $pdo->query($sql);
		$rs = $result->fetchAll(PDO::FETCH_ASSOC);
                echo "<table border=1>";
                echo "<tr>";
                echo "<th> Song Version";
                echo "</th>";
                echo "</tr>";
                for ($j = 0; $j < sizeof($rs); $j++)
                {
                    echo "<tr>";
                    echo "<td>";
		    echo '<input type="radio" id="song" name="song" value="'.$rs[$j]["FileID"].'">';
                    echo '<label for="song">'.$rs[$j]["SongVersion"].'</label><br>';
                    echo "</td";
                    echo "</tr>";
                }
		echo "</table>";
            }
        }
        // Search for band
        elseif(isset($_POST["search"]) && $_POST["search"] == "1")
        {
	    echo "Searching Band...";
	    echo "<br>";
            $bands;
            // Check if input is set, otherwise use entire list
            if ($search == NULL)
            {
                $sql = "SELECT * FROM Band";
            }
            else
            {
                $sql = "SELECT * FROM Band WHERE BandName = '$search'";
            }
            $result = $pdo->query($sql);
            $rows = $result->fetchAll(PDO::FETCH_ASSOC);
            // Search for songs using list of band names
            for ($i = 0; $i < sizeof($rows); $i++)
            {
                $bands = $rows[$i]["BandID"];
                $sql = "SELECT * FROM Song WHERE BandID = '$bands'";
                $result = $pdo->query($sql);
                $rows = $result->fetchAll(PDO::FETCH_ASSOC);
                // Output list of songs
                echo "<table border=1>";
                echo "<tr>";
                echo "<th> Song Name";
                echo "</th>";
                echo "</tr>";
                for ($i = 0; $i < sizeof($rows); $i++)
                {
                    echo"<tr>";
                    echo"<td>";
                    echo $rows[$i]["SongName"];
                    echo"</td>";
                    echo"</tr>";
                }
                echo "</table>";
            }
        }
        // Search for artist
        elseif (isset($_POST["search"]) && $_POST["search"] == "2")
        {
	    echo "Searching Artist...";
	    echo "<br>";
            $artists;
            // Check if input is set, otherwise use entire list
            if ($search == NULL)
            {
                $sql = "SELECT * FROM Contributer";
            }
            else
            {
                $sql = "SELECT * FROM Contributer WHERE ContributerName = '$search'";
            }
            $result = $pdo->query($sql);
            $rows = $result->fetchAll(PDO::FETCH_ASSOC);
            // Search for Song IDs in Contributed based on contributer names
            for ($i = 0; $i < sizeof($rows); $i++)
            {
                $artists = $rows[$i]["ContributerID"];
                $sql = "SELECT * FROM Contributed WHERE ContributerID = '$artists'";
                $result = $pdo->query($sql);
                $rows = $result->fetchAll(PDO::FETCH_ASSOC);
                // Get song IDs from Contributed
                for ($i = 0; $i <sizeof($rows); $i++)
                {
                    $artists[$i] = $rows[$i]["SongID"];
                }
            }
	    // Output list of songs be searching through song ids
	    echo "<table border=1>";
	    echo "<tr>";
	    echo "<th> Song Name";
            echo "</th>";
            echo "</tr>";
            for ($i = 0;$i<sizeof($rows); $i++)
            {
                $sql = "SELECT * FROM Song WHERE SongID = '$artists[$i]'";
                $result = $pdo->query($sql);
                $rows2 = $result->fetchAll(PDO::FETCH_ASSOC);
		echo"<tr>";
                echo"<td>";     
		echo $rows2[0]["SongName"];
                echo"</tr>";
                echo"</td>";
	    }
	    echo "</table>";
        }
        else
        {
            // Output full song list if no input or type is selected
	        echo "Printing all songs...";
	        echo"<br>";
            $sql = "SELECT * FROM Song";
            $result = $pdo->query($sql);
            $rows = $result->fetchAll(PDO::FETCH_ASSOC);
            echo "<table border=1>";
            echo "<tr>";
            echo "<th> Song Name";
            echo "</th>";
            echo "</tr>";
            for ($i = 0; $i < sizeof($rows); $i++)
            {
                echo"<tr>";
                echo"<td>";
                echo $rows[$i]["SongName"];
                echo "<br>";
                echo"</tr>";
                echo"</td>";
            }
            echo "</table>";
        }
    }
    else
    {
        // Output full song list if no input or type is selected
	echo "Printing all songs...";
	echo "<br>";
        $sql = "SELECT * FROM Song";
        $result = $pdo->query($sql);
	$rows = $result->fetchAll(PDO::FETCH_ASSOC);
	echo "<table border=1>";
        echo "<tr>";
        echo "<th> Song Name";
        echo "</th>";
        echo "</tr>";
        for ($i = 0; $i < sizeof($rows); $i++)
        {
	    
            echo"<tr>";
            echo"<td>";
            echo $rows[$i]["SongName"];
            echo "<br>";
            echo"</tr>";
            echo"</td>";        }
    }
}
catch(PDOexception $e) {
    echo "Connection to database failed: " . $e->getMessage();
}
?>
<<<<<<< Updated upstream
    <form method="post" action="http://students.cs.niu.edu/~z1910007/signup.php">
        <input type="radio" name="paid" id="paid" value="1"> 
        <label for="paid">How much do you want to pay?</label><br>
        <input type="submit">
=======

    <form method="post" action="http://students.cs.niu.edu/~z1910569/signup.php">
	<label for="paid">How much do you want to pay? </label><br>     
	<input type="number" name="paid" id="paid"><br> 
        <label for="paid">Please enter your name</label><br>
	<input type="text" name="CustName"><br>
	<input type="submit">
>>>>>>> Stashed changes
    </form>
    <?php
        if(isset($_POST["song"]))
        {
            $paid = false;
            if($_POST["paid"]=="1")
            {
                $paid=true;
            }

            $song = $_POST["song"];

            $sql = "Insert into Queue(Paid, FileID) VALUES (?, ?)";
            
            $prepared = $pdo->prepare($sql);

            $prepared->execute(array($paid, ));
          
	}

    ?>
</body>
</html>
