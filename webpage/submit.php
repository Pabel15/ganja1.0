<?php 
  
header("Content-Type: application/json"); 
$fecha = new DateTime('now');

$data = json_decode(file_get_contents("php://input")); 
$lista = array (
    $fecha->format('Y-m-d H:i:s'),
    $data->variable,
    $data->valor
);

$fp = fopen('fichero.csv', 'a');

fputcsv($fp, $lista);

fclose($fp);
echo "Salvado variable: $data->variable, valor: $data->valor"; 
  
?> 
