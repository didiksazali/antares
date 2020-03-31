<?php

$curl = curl_init();

curl_setopt_array($curl, array(
  CURLOPT_PORT => "8443",
  CURLOPT_URL => "https://platform.antares.id:8443/~/antares-cse/antares-id/AIoT/SmartSwitchStatus",
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => "",
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 30,
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => "POST",
  CURLOPT_POSTFIELDS => "{\r\n  \"m2m:cin\": {\r\n    \"con\": \"{\\\"status\\\":\\\"1\\\"}\"\r\n  }\r\n}",
  CURLOPT_HTTPHEADER => array(
    "Accept: application/json",
    "Accept-Encoding: gzip, deflate",
    "Cache-Control: no-cache",
    "Connection: keep-alive",
    "Content-Length: 58",
    "Content-Type: application/json;ty=4",
    "Host: platform.antares.id:8443",
    "Postman-Token: 95f54054-1ec8-4a9e-9612-e215e8346275,fda75511-afb4-4e1a-8c9f-41b49a0cfcad",
    "User-Agent: PostmanRuntime/7.15.2",
    "X-M2M-Origin: 7b1348e3956238ad:613f238b5604e1e5",
    "cache-control: no-cache"
  ),
));

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);

if ($err) {
  echo "cURL Error #:" . $err;
} else {
  header('location:index.php?status=nyala');
}
?>