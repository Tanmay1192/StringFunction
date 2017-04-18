#include <stdio.h>
#include <string.h>


/*-----------------------------------------------------------------------------------------------------------------------------------------
 *  Name        : indexOf
 *
 *  Input       : First argument is input string and second is character whoes index value is to be evaluated
 *
 *  Return      : On success - will return index of the character in the string
 *                On Failure - will return -1
 *
 *  Author      : Tanmay Prakash
 ----------------------------------------------------------------------------------------------------------------------------------------*/
int indexOf(char *str, int c)
{
  register int position = -1;
  register int i;
  char* s;
  for(s = str; *s; s++);
  int length = (int)(s - str);

  for(i=0; i <= length; i++)
  {
    if(str[i] == c)
      position = i + 1;
  }
  return position;
}


/*-----------------------------------------------------------------------------------------------------------------------------------------
 *  Name        : substring
 *
 *  Input       : 1st argument -> input string
 *                2nd argument -> index location of first character from where substring is to be taken
 *                3rd argument -> index location of last character till  where substring is to be taken
 *                4th argument -> destination where to copy substring. 
 *
 *  Return      : On success - will return index of the character in the string
 *                On Failure - will return -1
 *
 *  Author      : Tanmay Prakash
 ----------------------------------------------------------------------------------------------------------------------------------------*/
char* substring(char* string, int offset, int len, char* dest)
{
  if(len < 0 || offset > len || string == NULL)
    return NULL;

  char *s;
  for(s = string; *s; s++);
  int input_len = (int)(s - string);
  int bytes_to_copy = len - offset;

  if((offset + bytes_to_copy) > input_len)
    return NULL;

  //strncpy(dest, (string + offset), bytes_to_copy - 1);
  //dest[bytes_to_copy - 1] = '\0';

  snprintf(dest, bytes_to_copy, "%s", (string + offset));
  return dest;
}

#ifdef TEST
int main(void)
{
  char string[256] = "";
  char sub_string[256] = "";

  strcpy(string, "URI[input1=startswith]");
  printf("from main index: %d\n", (indexOf(string, '[')));
  printf("from main index: %d\n", (indexOf(string, ']')));
  
  substring(string, indexOf(string,'['), indexOf(string, ']'), sub_string);
  
  printf("substring: (%s)\n", sub_string);
  printf("Length of substring : %d\n", strlen(sub_string));
  
  return 0;
}
#endif

