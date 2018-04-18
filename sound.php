<?php
//echo "This is from the server";
$log_file = 'soundlog.txt';
$data = $_POST['data'];
//date_default_timezone_set("UTC");
$today = date("Y-m-d H:i:s");
$str = $today .', '.$data."\n";

//echo "This is from the server";
//now we open the file

if(file_exists($log_file))
{
	$fp = fopen($log_file, a); // the file is opened as append mode
	fwrite($fp, $str);
	fclose($fp);
}
else //the file doesn't exist, so open a new one.
{
	$fp = fopen($log_file, w);
	fwrite($fp, $str);
	fclose($fp);
}

echo "Data is stored\n";
?>
