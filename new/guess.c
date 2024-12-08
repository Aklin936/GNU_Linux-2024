#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main(int argc, char const *argv[])
{

	bindtextdomain("messages", TEXTDOMAINDIR);
	textdomain("messages");
	setlocale(LC_ALL, "");


	printf(_("Your number is: %d\n"), right);

	return 0;
}