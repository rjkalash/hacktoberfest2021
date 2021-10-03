<?php

function checkPalindrom($text) {
    return strrev($text) === $text;
}

$text = 'level';

if(checkPalindrom($text)) {
    echo "$text is palindrome" . PHP_EOL;
} else {
    echo "$text is not palindrome";
}