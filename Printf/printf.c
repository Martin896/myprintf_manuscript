#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	 int countC = 0;
	 va_list arg_lists;
	 
	 va_start(arg_lists, format);
	 
	 if (f
			          if (*format == '\0' || format == NULL)
				                   return (-1);ormat == NULL)
		 return (-1);

	 /*looping through each character of the formated string*/

	 while (*format) 
	 {
	 	if (*format != '%') /*if the format string is not % then */
		{
			write(1, format, 1); /*it prints just the current charcter*/
			countC++; /*the countC is now incresed by 1*/
		}
	
		else
		{
			/* so as long as *format is not % it will remain in the if loop else we come here and handle specifiers*/
			format++; /* the pointer now points to the next*/
			
			if (*format == 'c')
			{ 
				/*the character format specifier*/

				char sc = va_arg(arg_lists, int);
	
				/** so this means we have a directive, 
				 ** we now check the argument that hold the value of char*/
	
				write(1, &sc, 1);
				countC++;
			}

			else if (*format == 's') /* we check if it a string*/
			{
				char *strc = va_arg(arg_lists, char*); 
				
				/*because it is a character pointer we have to check if it points a valid adress*/

				if (strc == NULL)
					return (-1); /*return an error*/

				/*otherwise since in our write fxn number of byte =1 we use a 
				 * while loop to print the entire string*/
				
				while (*strc)
				{
					write(1, str, 1);
					strc++;
					countC++;
				}
			}
				else
				{
					/** now the tricky part, since we have checked for s and c to check for % 
				 	* which is not a recongnise specifer but a usual chacter we have to find
				 	* a way to 'trick' the compiler to go back and print % 
				 	* we do this by point backward i.e format - 1 */

					write(1, format - 1, 2);
					countC++; 
				}
				format++;
			}
			va_end(arg_lists);
			return (countC);

}


/**
 *write(1, format - 1, 2);: This writes two characters to the standard output.
The first character is the '%' character, and the second character is the one immediately following the '%'.

 write(1, format - 1, 1);: This writes only the '%' character to the standard output.

 So, if you want to print just the '%' character without the character immediately following it,
 you should use write(1, format - 1, 1);. In the context of your code
 , this would be suitable for handling cases where the '%' is not followed by a recognized format specifier.

 *So, in essence, it treats the '%' character as a regular character
 and prints it to the standard output. 
 It doesn't interpret it as part of a valid format specifier.
 This can be useful for scenarios where you want to print a literal '%'
character in the output without expecting it to be part of a special format sequence.
 **/
