#include <stdio.h>

// geht davon aus, dass str null-terminated ist
char* trim(char* str) {
  // Hier Code einfügen

  int strLength = 0;
  while(str[strLength]!='\0')  //  remove ;
  {
      strLength++;
      printf("%i\n", strLength);
  }
  //const int strLength = strlen(str)/sizeof(str[0]);

  printf("Arr Length %s: %d \n", str, strLength);

  if(strLength == 1 && str[0] == '#'){

    str[0] = '\0';
    return str;
  }

  for(int i = 0; i < strLength; i++) {

    if(str[i]== '#') {
 
      for(int j = i+4; j < strLength+1; j++){

        str[i++] = str[j]; //Halloallo,Welt!

        printf("Loop %d: %s \n", i, str);
      }

      i = strLength;

      return str;
    }
  }

  return str;
}

