<!doctype html>
<html>
<head>
</head>
<body>
<?php
$username = "z1910007";
$password = "2000Oct14";

try {
    // setup pdo connection
    $dsn = "mysql:host=courses;dbname=z1910007";
    $pdo = new PDO($dsn, $username, $password);
    $pdo -> setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

    $sql = "SELECT * FROM Queue WHERE Paid = TRUE";
    $result = $pdo->query($sql);
    $rows = $result->fetchAll(PDO::FETCH_ASSOC);

    for ($i = 0; $i < sizeof($rows); $i++)
    {
        echo $rows[$i]["QueueNumber"];
        echo $rows[$i]["CustomerName"];
        echo $rows[$i]["FileID"];
        echo "<br>";
    }

    $sql = "SELECT * FROM Queue WHERE Paid = FALSE";
    $result = $pdo->query($sql);
    $rows = $result->fetchAll(PDO::FETCH_ASSOC);

    for ($i = 0; $i < sizeof($rows); $i++)
    {
        echo $rows[$i]["QueueNumber"];
        echo $rows[$i]["CustomerName"];
        echo $rows[$i]["FileID"];
        echo "<br>";
    }
}
catch(PDOexception $e) {
    echo "Connection to database failed: " . $e->getMessage();
}

?>
</body>
</html>