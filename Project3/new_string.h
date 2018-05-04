/**
   Authors: Joe Divinagracia && James O'Brien
**/

char* new_strcpy(char* destination, const char* source);
char* new_strncpy(char* destiantion, const char* source, size_t n);
int new_strcmp(const char* string1, const char *string2);
int new_strncmp(const char* string1, const char* string2, size_t n);
char* new_strcat(char* destination, const char* source);
char* new_strncat(char* destination, const char* source, size_t n);
size_t new_strlen(const char* string);
char* new_strchr(const char* string, int character);
char* new_strstr(const char* haystack, const char* needle);

/*
  Gets the length of a given string
*/
size_t new_strlen(const char* string){
  int i=0;
  //loops up until the null character
  while(string[i]!='\0')
    i++;
  return i;
}

/*
  Copies the string in /source/ to /destination/
*/
char* new_strcpy(char* destination, const char* source){
  size_t i;
 
  for(i=0;source[i] != '\0';i++)
    destination[i] = source[i];
  
  return destination;
}

/*
  Copies the first n character of /source/ into /destination/
*/
char* new_strncpy(char* destination, const char* source, size_t n){
  size_t i;

  //loops through the first n characters of /source/
  for(i=0; i < n && source[i] != '\0';i++)
    destination[i] = source[i];

  //if i hits null before '\0', fill destination with '\0'
  for(;i<n;i++)
    destination[i] = '\0';
  
  return destination;
}

/*
  returns the difference between two strings
*/
int new_strcmp(const char* string1, const char* string2){
  int i=0, sum=0;
  //positive if string1 is before string2, and negative if opposite
  while(string1[i] != '\0' || string2[i] != '\0'){
    sum = string1[i] - string2[i];
    if(sum!=0)
      return sum;
    i++;
  }
  return sum;
}

/*
  works like strcmp, but only checks the first n characters
  everything else is pretty much the same as above
*/
int new_strncmp(const char* string1, const char* string2, size_t n){
  int i=0, sum=0;
  for(i=0;i<n;i++){
    sum = string1[i] - string2[i];
    if(sum!=0)
      return sum;
  }
  return sum;
}

/*
  concatenates /source/ onto /destination/
*/
char* new_strcat(char* destination, const char* source){
  int i=0, size = new_strlen(destination);
  
  for(i=0;source[i] != '\0';i++)
    destination[size+i] = source[i];

  return destination;
}

/*
  concatenates the first n characters on /source/ onto the end of /destination/
*/
char* new_strncat(char* destination, const char* source, size_t n){
  int i, size = new_strlen(destination);

  for(i=0;i<n;i++)
    if(source[i] != '\0')
      destination[size+i] = source[i];

  return destination;
}		  

/*
  finds the first occurence of /character/ in /string/ and returns everything after /character/
*/
char* new_strchr(const char* string, int character){
  char tempString[new_strlen(string)];
  char* ret;
  int i=0,j=0;
  //found is used to check if the character has been found yet
  int found=0;
  //loops while string[i] is not /character/ and not at the end
  while(string[i] != character && string[i] != '\0')
    i++;

  //once it finds the character
  //put everything from /string/ into /tempString/
  while(string[i] != '\0'){
    tempString[j] = string[i];
    i++;
    j++;
    found=1;
  }
  //if it reaches the end w/o finding the character
  //return NULL
  if(found==0)
    return NULL;
  //else return the tempString
  else{
    new_strcpy(ret, tempString);
    return ret;
  }
}

/*
  finds the first occurence of a substring inside of a string and retusn a pointer to it
  running make for this functions gives a warning
*/
char* new_strstr(const char* haystack, const char* needle){
  
  int needleLength = new_strlen(needle);
  int i=0, j=0, tempI, found = 0;

  //loops while the substring has not been found
  while(found!=1 && haystack[i]!='\0'){
    if(haystack[i] == needle[j]){
      tempI = i;
      //loops while j < needleLength AND hay[tempI] is needle[j]
      while(j<needleLength && (haystack[tempI] == needle[j])){
	//if j reaches the end of the string, set found to 1
	//this breaks out of the while loop
	if(j==needleLength-1)
	  found+=1;
	tempI++;
	j++;
      }
    }
    j=0;
    i++;
  }

  //decrements i back to where it should start
  i--;
  //if it is found, return the pointer to that substring
  if(found==1)
    return &haystack[i];
  else
  //or else return NULL
    return NULL;
}
