<?php
$status = $_GET['status'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
<input type="button" onclick="location.href='nyala.php';" value="Nyala" />
<input type="button" onclick="location.href='redup.php';" value="Redup" />
<?php
if ($status=='nyala'){
 echo '<p>Lampu Nyala</p>';
} else {
    echo '<p>Lampu Redup</p>';
}
?>

</body>
</html>