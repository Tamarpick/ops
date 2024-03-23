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


//חלק א' סעיף ג'


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** splitArgument(char* str) {
int i = 0; // משתנה מונה
char** arguments = malloc(256 * sizeof(char*)); // הקצאת זיכרון למערך של 256 מצביעי מחרוזת
char* token = strtok(str, " "); // קבלת האסימון הראשון מהמחרוזת המקורית


while (token != NULL) { // לולאה שרצה עד שכל האסימונים נאספו
    arguments[i++] = token; // שמירת האסימון הנוכחי במערך
    token = strtok(NULL, " "); // קבלת האסימון הבא
}
arguments[i] = NULL; // סימון סוף המערך עם NULL

return arguments; // החזרת המערך עם האסימונים
}



//חלק ב' סעיף א'


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה לטיפול בפקודת יציאה מהממשק
void logout(char* commandStr) {
    // כתובת התחלת המחרוזת לאחר הסרת רווחים מהתחלה
    char* cleanedCmd = commandStr + strspn(commandStr, " \t\n");
    // מצביע לתו האחרון במחרוזת לפני רווחים סופיים
    char* endCmd = cleanedCmd + strlen(cleanedCmd) - 1;
    // הסרת רווחים, טאבים ושורות חדשות מסוף המחרוזת
    while (endCmd > cleanedCmd && (*endCmd == ' ' || *endCmd == '\t' || *endCmd == '\n')) {
        *endCmd = '\0'; // החלפת תווים אלו בסיום מחרוזת
        endCmd--; // הזזה לתו הקודם
    }

    // פיצול המחרוזת למילה הראשונה
    char* firstCmd = strtok(cleanedCmd, " \t");
    // בדיקה אם המילה הראשונה היא "exit"
    if (firstCmd != NULL && strcmp(firstCmd, "exit") == 0) {
        // ניסיון לקבלת המילה השנייה - אם לא קיימת, הפקודה תקפה
        char* nextCmd = strtok(NULL, " \t");
        if (nextCmd == NULL) { // אין פרמטרים נוספים
            printf("Exiting the terminal...\n");
            free(commandStr); // שחרור הזיכרון שהוקצה למחרוזת
            exit(0); // יציאה מהתוכנית
        }
    }

    // אם הפקודה לא הייתה "exit" תקנית, הדפסת הודעת שגיאה
    printf("Command not recognized. Please use 'exit' to close the terminal.\n");
}


//חלק ב' סעיף ב'


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// פונקציה לשינוי התיקייה הנוכחית בהתאם לפרמטרים שהתקבלו
void cd(char **params) {
    char pathBuffer[1024] = {0}; // מערך לשמירת הנתיב המלא
    int index = 1; // אינדקס לעיבוד ארגומנטים

    // בדיקה אם הארגומנט הראשון לא ריק ואם אין ארגומנט נוסף או שהנתיב מכיל מרכאות
    if (params[index] != NULL && (params[index+1] == NULL || strchr(params[index], '"') != NULL)) {
        strcpy(pathBuffer, params[index]); // העתקת הנתיב למערך
        
        char *charPtr = pathBuffer; // מצביע לתו הראשון במערך
        while (*charPtr) { // הסרת כל המרכאות מהנתיב
            if (*charPtr == '"') {
                memmove(charPtr, charPtr+1, strlen(charPtr));
            } else {
                ++charPtr;
            }
        }
    } else {
        // עיבוד ארגומנטים נוספים ובניית הנתיב מחדש עם רווחים ביניהם
        while (params[index] != NULL) {
            strcat(pathBuffer, params[index]);
            if (params[index+1] != NULL) strcat(pathBuffer, " ");
            index++;
        }
    }

    // ביצוע פקודת שינוי התיקייה, אם נכשל מדפיס שגיאה
    if (chdir(pathBuffer) == -1) {
        perror("cd failed");
    }
}


//חלק ב' סעיף ג'

void cp(char **inputs) {
    char srcPath[1024]; // מערך לשמירת הנתיב המקורי
    char dstPath[1024]; // מערך לשמירת הנתיב היעד

    // העתקת הנתיב המקורי מהקלט, והסרת מרכאות אם קיימות
    strcpy(srcPath, inputs[1]);
    removeQuotes(srcPath);

    // העתקת הנתיב היעד מהקלט, והסרת מרכאות אם קיימות
    strcpy(dstPath, inputs[2]);
    removeQuotes(dstPath);

    // ניסיון לפתוח את הקובץ המקורי לקריאה
    FILE* srcFile = fopen(srcPath, "rb");
    if (srcFile == NULL) { // אם הפתיחה נכשלת, הדפסת שגיאה ויציאה
        perror("Error opening source file");
        return;
    }

    // ניסיון לפתוח את הקובץ היעד לכתיבה
    FILE* dstFile = fopen(dstPath, "wb");
    if (dstFile == NULL) { // אם הפתיחה נכשלת, סגירת הקובץ המקורי, הדפסת שגיאה ויציאה
        fclose(srcFile);
        perror("Error opening destination file");
        return;
    }

    // הגדרת באפר לקריאת הנתונים מהקובץ המקורי וכתיבתם ליעד
    char dataBuffer[4096];
    size_t bytesRead;
    // קריאת נתונים מהקובץ המקורי וכתיבתם לקובץ היעד עד לסיום הקובץ
    while ((bytesRead = fread(dataBuffer, 1, sizeof(dataBuffer), srcFile)) > 0) {
        fwrite(dataBuffer, 1, bytesRead, dstFile);
    }

    // סגירת הקבצים
    fclose(srcFile);
    fclose(dstFile);
}


//חלק ג' סעיף א'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// פונקציה למחיקת קובץ עם טיפול בנתיבים המכילים רווחים
void delete(char *path) {
    // הסרת מרכאות מהנתיב אם קיימות
    if (path[0] == '"' && path[strlen(path) - 1] == '"') {
        path[strlen(path) - 1] = '\0'; // הסרת המרכאות מסוף המחרוזת
        path++; // התעלמות מהמרכאות בתחילת המחרוזת
    }

    // ביצוע מחיקת הקובץ
    if (remove(path) == 0) {
        printf("הקובץ '%s' נמחק בהצלחה.\n", path);
    } else {
        perror("שגיאה במחיקת הקובץ");
    }
}


//חלק ג' ססעיף ב'

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// פונקציה לפיצול מחרוזת למערכים של ארגומנטים לפני ואחרי התו '|'
void splitAndExecute(char* input) {
    char* args[256]; // מערך זמני לאחסון ארגומנטים
    char* command1[128]; // מערך לארגומנטים של הפקודה הראשונה
    char* command2[128]; // מערך לארגומנטים של הפקודה השנייה
    char* token;
    int i = 0, j = 0;

    // פיצול הקלט לארגומנטים באמצעות strtok
    token = strtok(input, " ");
    while(token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // סימון סוף המערך

    // חלוקת הארגומנטים לשני מערכים לפני ואחרי התו '|'
    for (i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], "|") == 0) {
            command1[i] = NULL; // סיום מערך הארגומנטים הראשון
            i++;
            break;
        }
        command1[i] = args[i];
    }

    // מילוי מערך הארגומנטים השני
    for (j = 0; args[i] != NULL; i++, j++) {
        command2[j] = args[i];
    }
    command2[j] = NULL; // סימון סוף המערך

    // כעת, ניתן לקרוא לפונקציה mypipe עם command1 ו-command2
    // mypipe(command1, command2); // הנחה שהפונקציה mypipe מוגדרת במקום אחר
}


//חלק ד' סעיף א'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// פונקציה להסרת מרכאות מהתחלה וסוף המחרוזת אם קיימות
void removeQuotes(char* str) {
    size_t len = strlen(str);
    if (str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}

// פונקציה להעברת קובץ מנתיב מקור לנתיב יעד
void move(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "שגיאה: חסרים ארגומנטים לפקודת move\n");
        return;
    }

    char sourcePath[1024];
    char destPath[1024];

    strcpy(sourcePath, args[1]);
    removeQuotes(sourcePath);

    strcpy(destPath, args[2]);
    removeQuotes(destPath);

    // בדיקה אם הקובץ המקורי קיים
    if (access(sourcePath, F_OK) == -1) {
        fprintf(stderr, "שגיאה: הקובץ המקורי '%s' לא נמצא\n", sourcePath);
        return;
    }

    // ניסיון להעביר את הקובץ
    if (rename(sourcePath, destPath) != 0) {
        perror("שגיאה בהעברת הקובץ");
        return;
    }

    printf("הקובץ הועבר בהצלחה מ- '%s' אל- '%s'\n", sourcePath, destPath);
}



//חלק ד' סעיף ב'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה להוספת טקסט לקובץ. הפונקציה מקבלת מערך של ארגומנטים
void echoppend(char **args) {
    // בדיקה שיש לפחות שני ארגומנטים במערך (הפקודה והנתיב)
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "שגיאה: חסרים ארגומנטים\n");
        return;
    }

    // הנחה שהארגומנט האחרון הוא הנתיב לקובץ
    char *filePath = args[2];
    // פתיחת הקובץ לכתיבה בסוף הקובץ. יצירת הקובץ אם לא קיים
    FILE *file = fopen(filePath, "a");
    if (file == NULL) {
        perror("שגיאה בפתיחת הקובץ");
        return;
    }

    // הוספת המחרוזת לקובץ
    fprintf(file, "%s\n", args[1]);

    // סגירת הקובץ
    fclose(file);

    printf("המחרוזת '%s' נוספה בהצלחה לקובץ '%s'\n", args[1], filePath);
}


//חלק ד' סעיף ג'



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה לכתיבת מחרוזת לקובץ, מחליפה את תוכן הקובץ במחרוזת החדשה
void echowrite(char **args) {
    // בדיקה שיש לפחות שני ארגומנטים במערך (הפקודה והנתיב)
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "שגיאה: חסרים ארגומנטים\n");
        return;
    }

    // הנחה שהארגומנט האחרון הוא הנתיב לקובץ
    char *filePath = args[2];
    // פתיחת הקובץ לכתיבה (מחיקת תוכן קיים)
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("שגיאה בפתיחת הקובץ");
        return;
    }

    // כתיבת המחרוזת לקובץ
    fprintf(file, "%s\n", args[1]);

    // סגירת הקובץ
    fclose(file);

    printf("המחרוזת '%s' נכתבה בהצלחה לקובץ '%s'\n", args[1], filePath);
}


//חלק' ד' סעיף ד'

#include <stdio.h>
#include <stdlib.h>

// פונקציה לקריאה והדפסה של תוכן קובץ
void read(char **args) {
    // בדיקה אם נתיב הקובץ נמסר כארגומנט
    if (args[1] == NULL) {
        fprintf(stderr, "שגיאה: לא סופק נתיב לקובץ\n");
        return;
    }

    // ניסיון לפתוח את הקובץ
    FILE *file = fopen(args[1], "r");
    if (file == NULL) {
        fprintf(stderr, "שגיאה בפתיחת הקובץ: %s\n", args[1]);
        return;
    }

    // קריאה והדפסה של תוכן הקובץ
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // סגירת הקובץ
    fclose(file);
}