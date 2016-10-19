#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include "nms.h"

int main(void) {
	int termCols, spaces = 0;
	char input;
	char display[2000];
	char *head1Left      = "DATANET PROC RECORD:  45-3456-W-3452";
	char *head1Right     = "Transnet on/xc-3";
	char *head2Center    = "Initialising";
	char *head3Center    = "";
	char *head4Center    = "****************  Welcome To  ****************";
	char *head5Center    = "================================================================";
	char *menu1          = "11111  1    1   1 11111   1111   1111  1       1     1     ";
	char *menu2          = "1      1    1   1 1       1   1  1     1       1    1 1    ";
	char *menu3          = "1      1    1   1 1       1  1   1      1     1    1   1   ";
	char *menu4          = "1 111  1    1   1 1  11   1 1    111     1   1    1111111  ";
	char *menu5          = "1   1  1    1   1 1   1   1  1   1        1 1    1       1 ";
	char *menu6          = "11111  1111 11111 11111   1   1  1111      1     1       1 ";
	char *foot1Center    = "================================================================";
	char *foot2Center    = "Coded By CodeCannons";
	NmsArgs args = INIT_NMSARGS;

	// Get terminal dimentions (needed for centering)
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	termCols = w.ws_col;

	// Start building the display string
	strcpy(display, head1Left);

	spaces = termCols - strlen(head1Left) - strlen(head1Right);
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head1Right);

	strcat(display, "\n");

	spaces = (termCols - strlen(head2Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head2Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(head3Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head3Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(head4Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head4Center);

	strcat(display, "\n");

	spaces = (termCols - strlen(head5Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head5Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = ((termCols - strlen(head5Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu1);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head5Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu2);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head5Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu3);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head5Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu4);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head5Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu5);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head5Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu6);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(foot1Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, foot1Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(foot2Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, foot2Center);

	// Set needed args
	args.src = display;
	args.return_opts = "123456";
	args.input_cursor_y = 18;
	args.input_cursor_x = ((termCols - strlen(foot2Center)) / 2) + 1;

	// Display characters
	input = nms_exec(&args);

	switch (input) {
		case '1':
			printf("User chose 1\n");
			break;
		case '2':
			printf("User chose 2\n");
			break;
		case '3':
			printf("User chose 3\n");
			break;
		case '4':
			printf("User chose 4\n");
			break;
		case '5':
			printf("User chose 5\n");
			break;
		case '6':
			printf("User chose 6\n");
			break;
		default:
			printf("Unrecognized selection: %c\n", input);
			break;
	}

	return 0;
}
