<html><head><title>suppliers</title></head><body> 
<form action="http://students.cs.niu.edu/~z1910569/assign8/Assign8.php" method="GET">


	<input type="submit" name="Suppliers" value="Show suppliers">  
	<input type="submit" name="parts" value="Show parts"><br/>	
</form>	

<form action="http://students.cs.niu.edu/~z1910569/assign8/Assign8.php" method="GET">                   
	<p>Choose a supplier to look for.</p>
	<input type="radio" name="supplier" value="S1"> S1
	<input type="radio" name="supplier" value="S2"> S2
	<input type="radio" name="supplier" value="S3"> S3
	<input type="radio" name="supplier" value="S4"> S4
	<input type="radio" name="supplier" value="S5"> S5<br/><br/>
	<input type="submit" name="yeehaw"><br/>
</form>

<form action="http://students.cs.niu.edu/~z1910569/assign8/Assign8.php" method="GET">                   
	<p>Choose a part to look for</p>	
	<input type="radio" name="part" value="P1"> P1
	<input type="radio" name="part" value="P2"> P2
	<input type="radio" name="part" value="P3"> P3        
	<input type="radio" name="part" value="P4"> P4
	<input type="radio" name="part" value="P5"> P5   
	<input type="radio" name="part" value="P6"> P6 <br/><br/><br/>
	<input type="submit" name ="Woot"><br/> 
</form>

<form action="http://students.cs.niu.edu/~z1910569/assign8/Assign8.php" method="GET">
	<p>if you want to add a new supplier put in the following information</p>
	<input type="text" name="S"> Supplier ID <br/>
	<input type="text" name ="Sname"> Supplier name <br/>
	<input type="text" name ="status"> Status <br/>
	<input type="text" name ="city">   city <br/>
	<input type="submit" name="submit">
<form>
<form action="http://students.cs.niu.edu/~z1910569/assign8/Assign8.php" method="GET">
	<p>if you want to add a part, input the following information</p>
	<input type="text" name="P"> Part ID<br/> 
	<input type="text" name="Pname"> Part name <br/>
	<input type="text" name="color"> Color	<br/>
	<input type="text" name="weight"> weight<br/>
	<input type="submit" name="submit">
</form>



<pre>
<?php
	error_reporting(E_ALL);
	include("secrets.php");
	function draw_table($rows){
		echo "<table border=1 cellspacing=1>";
		echo"<tr>";
		foreach($rows[0] as $key=>$p){
			echo "<th>$key</th>";
		}
		echo "</tr>";
		foreach($rows as $row){
			echo "<tr>";
			foreach($row as $key=>$item){
				echo "<td> $item</td>";
			}
			echo "</tr>";
		}
		echo "</table>";
	}
	function all_parts($pdo){
		$rs = $pdo->query("SELECT * FROM P");
		$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
		draw_table($rows);
	}
	function all_suppliers($pdo){
		$rs = $pdo->query("SELECT * FROM S");
		$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
		draw_table($rows);
	}

    //End of function declarations   
        try{
                $dsn = "mysql:host=courses;dbname=z1910569";
                $pdo = new PDO($dsn, $username, $password);
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

		
		$rs = $pdo->query("SELECT * FROM S");
		$rows= $rs->fetchAll(PDO::FETCH_ASSOC);	



		if($_GET["Suppliers"] == "Show suppliers"){	//shows all suppliers and their data(Part 1)
			all_suppliers($pdo);
		}
		if($_GET["parts"] == "Show parts"){		//Shows all parts and their data (Part2)
			all_parts($pdo);
	}
	 
		if($_GET["supplier"]!=NULL){			//Shows a supplier, the parts they sell.(Part 4)
			$rs = $pdo->prepare("SELECT * FROM SP WHERE S = ?;");
			$rs-> execute(array($_GET["supplier"]));
			$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
			draw_table($rows);
			
			$rs = $pdo->prepare("SELECT * FROM S WHERE S = ?;");	//Shows the data of that supplier 
			$rs-> execute(array($_GET["supplier"]));	
			$rows = $rs->fetchall(PDO::FETCH_ASSOC);
			draw_table($rows);

		}
		if($_GET["part"]!= NULL){		//Shows a part and all its suppliers (part 3)
			$rs = $pdo->prepare("SELECT * FROM SP WHERE P = ?;");
			$rs->execute(array($_GET["part"]));
			$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
			draw_table($rows);

			$rs = $pdo->prepare("SELECT * FROM P WHERE P = ?;");	//shows the parts data
			$rs->execute(array($_GET["part"]));
			$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
			draw_table($rows);
	}
		//This is part 6
		if($_GET["P"] != NULL)	//inserts into the parts table what is taken from the form.
		{
			
			$rs=$pdo->prepare("INSERT INTO P (P, PNAME, COLOR, WEIGHT) VALUES(?, ?, ?, ?)");
			$rs->execute(array($_GET["P"], $_GET["Pname"], $_GET["color"], $_GET['weight']));
			
		}		

		//this is part 7
		if($_GET["S"]!= NULL)	//inserts into the supplier table what is taken from the form.
		{	
			$rs=$pdo->prepare("INSERT INTO S (S, SNAME, STATUS, CITY) VALUES(?, ?, ?, ?)");
			$rs->execute(array($_GET["S"], $_GET["Sname"], $_GET["status"], $_GET["city"]));
				
		}
        }
        catch(PDOexception $e){
                echo "Connection to database failed" . $e->getMessage();
        }

?>
</pre></body></html>
