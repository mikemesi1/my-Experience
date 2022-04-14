<!doctype html>
<html>
<head>
</head>
<body>
<form method="post" Action="http://students.cs.niu.edu/~z1910569/Signup.php">
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

<?php
// setting user and pass for connection
$username = "z1910569";
$password = "1999Jul20";

try {
    // setup pdo connection
    $dsn = "mysql:host=courses;dbname=z1910569";
    $pdo = new PDO($dsn, $username, $password);
    $pdo -> setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

    if(isset($_POST["input"]))
    {
        $search = $_POST["input"];
        $files;
        // Search for song
	if(isset($_POST["search"]) && $_POST["search"] == "0")
        {
            echo "Searching Song...";	    // Check if input is set, otherwise use entire list
	    echo "<br>";
	    if ($search == NULL)
            {
                $sql = "SELECT * FROM Song";
            }
            else
            {
                $sql = "SELECT * FROM Song WHERE SongName = '$search'";
            }
            $result = $pdo->query($sql);
            $rows = $result->fetchAll(PDO::FETCH_ASSOC);
            // Output list of songs
            for ($i = 0; $i < sizeof($rows); $i++)
	    {	
		echo "<br/>";
                echo $rows[$i]["SongName"];
                echo "<br/>";

		// Output each file version
		$Song = $rows[$i]["SongID"];
		$sql = "SELECT * FROM File WHERE SongID = '$Song'";               
	       	$result = $pdo->query($sql);	
		$rs = $result->fetchAll(PDO::FETCH_ASSOC);
                for ($i = 0; $i < sizeof($rs); $i++)
                {
                    echo $rs[$i]["SongVersion"];
                    echo "<br>";
                }
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
                for ($i = 0; $i < sizeof($rows); $i++)
                {
                    echo $rows[$i]["SongName"];
                    echo "<br>";
                }
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
            for ($i = 0;$artists[$i] !=NULL; $i++)
            {
                $sql = "SELECT * FROM Song WHERE SongID = '$artists[$i]'";
                $result = $pdo->query($sql);
                $rows = $result->fetchAll(PDO::FETCH_ASSOC);
                echo $rows[0]["SongName"];
                echo "<br>";
            }
        }
        else
        {
            // Output full song list if no input or type is selected
	    echo "Printing all songs...";
	    echo"<br>";
            $sql = "SELECT * FROM Song";
            $result = $pdo->query($sql);
            $rows = $result->fetchAll(PDO::FETCH_ASSOC);
            for ($i = 0; $i < sizeof($rows); $i++)
            {
                echo $rows[$i]["SongName"];
                echo "<br>";
            }
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
        for ($i = 0; $i < sizeof($rows); $i++)
        {
            echo $rows[$i]["SongName"];
            echo "<br>";
        }
    }
}
catch(PDOexception $e) {
    echo "Connection to database failed: " . $e->getMessage();
}
?>
    <form method="post" action="http://students.cs.niu.edu/~z1910569/Signup.php">
        <input type="radio" name="paid" id="paid" value="1"> 
        <label for="paid">How much do you want to pay?</label><br>
        <input type="submit">
    </form>
    <?php
        if(isset($_POST["Queue"]))
        {
            $paid = false;
            if($_POST["paid"]=="1")
            {
                $paid=true;
            }
            $sql = "Insert into Queue(Paid, FileID) VALUES (?, ?)";
            
            $prepared = $pdo->prepare($sql);

            $prepared->execute(array($paid, ));
          
	}

    ?>
</body>
</html>
