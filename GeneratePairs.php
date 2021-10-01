<?php 

function generatePairs(int $m, int $n): array {
  $arr = [];
  for($i = $m; $i <= $n; $i++){
    for($u = $i; $u <= $n; $u++){
      $arr[] = [$i, $u];
    }
  }
  return $arr;
}

?>
