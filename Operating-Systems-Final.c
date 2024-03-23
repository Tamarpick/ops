//חלק א' סעיף א'

function Wellcome() {
    // נשתמש ב ECHO כדי להדפיס את ההודעות המפורמטות למסך
    echo "aSPY//YASa"
    echo "apyyyyCY//////////YCa |"
    echo "sY//////YSpcs scpCY//Pp | Welcome to myShell"
    echo "ayp ayyyyyyySCP//Pp syY//C | Version 2.4.3"
    echo "AYAsAYYYYYYYY///Ps cY//S |"
    echo "pCCCCY//p cSSps y//Y | https://github.com/Tamarpick"
    echo "SPPPP///a pP///AC//Y |"
    echo "A//A cyP////C | Have fun!"
    echo "p///Ac sC///a |"
    echo "P////YCpc A//A | Craft packets like it is your last"
    echo "scccccp///pSP///p p//Y | day on earth."
    echo "sY/////////y caa S//P | -- Lao-Tze"
    echo "cayCyayP//Ya pY/Ya |"
    echo "sY/PsY////YCc aC//Yp"
    echo "sc sccaCY//PCypaapyCP//YSs"
    echo "spCPY//////YPSps"
    echo "ccaacs"
}

//חלק א' סעיף ב'
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void getLocation() {
    char hostname[1024]; // בניית מערך בגודל 1024 ביטים כדי לאפשר מספיק מקום
    hostname[1023] = '\0'; //  אתחול התו האחרון כתו שאומר שזה סוף המחזורת
    gethostname(hostname, 1023); 

    printf("\033[1;34mUser:\033[0m \033[1;32m%s\033[0m \033[1;34mHost:\033[0m \033[1;32m%s\033[0m\n", getenv("USER"), hostname); // הדפסה עם עיצוב
}
