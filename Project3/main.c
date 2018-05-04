#include <stdio.h>
#include "new_string.h"
#include <string.h>
#include <stdlib.h>

int main(){

  const char* source = "swag money";
  char destination[2048];
  char new_destination[2048];
  
  //new_strlen
  printf("strlen():\n");
  int length = new_strlen(source);
  int length2 = strlen(source);
  printf("Length of \"%s\" is: %d\nString.h: %d\n\n",source, length,length2);

  //strcpy functions
  char copyDest[2048];
  char strDest[2048];
  printf("strcpy():\n");
  new_strcpy(copyDest, source);
  printf("new_string.h\nOG: \"%s\"\nCopy: \"%s\"\n", source, copyDest);
  strcpy(strDest, source);
  printf("<string.h>\nOG: \"%s\"\nCopy: \"%s\"\n\n", source, strDest);

  //strncpy functions
  char new_strnDest[2048];
  char strnDest[2048];
  printf("strncpy():\n");
  new_strncpy(new_strnDest, source, 3);
  printf("new_string.h\nOG: \"%s\"\nFirst 3 chars of copy: \"%s\"\n", source, new_strnDest);
  strncpy(strnDest, source, 3);
  printf("string.h\nOG: \"%s\"\nFirst 3 chars of copy: \"%s\"\n\n", source, strnDest);

  //strcmp functions
  printf("strcmp():\n");
  int val = new_strcmp(source, "Swag Money");
  printf("%d\n", val);
  val = strcmp(source, "Swag money");
  printf("%d\n\n", val);

  printf("strncmp():\n");
  val = new_strncmp(source, "swat money", 5);
  printf("Ours: %d\n", val);
  val = strncmp(source, "swat money", 5);
  printf("Theirs: %d\n\n", val);

  //strcats
  char new_cat[100];
  char cat[100];
  printf("strcat():\n");
  new_strcpy(new_cat, "Hell yea");
  new_strcat(new_cat, source);
  printf("Ours: \t\t%s\n", new_cat);

  char destination2[500*sizeof(int)];
  new_strcpy(cat, "Hell yea");
  strcat(cat, source);
  printf("Theirs: \t%s\n\n", cat);
  
  //strncat
  char new_catDest[2048];
  char catDest[2048];
  printf("strncat():\n");
  new_strcpy(new_catDest, "Bunghole");
  new_strncat(new_catDest, source, 3);
  printf("Ours: \t\t%s\n", new_catDest);

  new_strcpy(catDest, "Bunghole");
  strncat(catDest, source, 3);
  printf("Theirs: \t%s\n\n", catDest);

  printf("new_strchr():\n");
  const char str1[] = "Heywood Jablowme";
  const char chr1 = 'z';
  char* ret1;
  ret1 = new_strchr(str1, chr1);
  printf("String character \"%s\" at %c = %s\n\n", str1, chr1, ret1);

  printf("strchr:\n");
  const char chr = 'b';
  char* ret;
  ret = strchr(str1, chr);
  printf("String character \"%s\" at %c = %s\n\n", str1, chr, ret);

  const char* haystack= "Cant change what makes your dick hard";
  const char* needle = "makes";
  char* strstr_ret;

  printf("Init string: %s\n", haystack);
  
  strstr_ret = new_strstr(haystack, needle);
  printf("Substring: %s\n", strstr_ret);
  return 0;
}
