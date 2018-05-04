#include <stdio.h>

int bits(unsigned char character);
unsigned char rotate(unsigned char letter, int count);
void encrypt(unsigned char plainText[2048], unsigned char key[2048], int length, unsigned char cipherText[2048]);

int main(){
  /*Char arrays to hold the (generated) message, key, and (generated) cipher text*/
  unsigned char plainText[2048];
  unsigned char key[2048];
  unsigned char cipherText[2048];

  /*to keep track of lengths of the message and key in case of tiling and to check if either goes over 2048 characters*/
  int messageLength=0;
  int keyLength=0, initialKeyLength=0;
  int i=0,j=0;

  /*Reads in the character of the message and stores it in the array, unless over 2048 characters*/
  int messageValue;
  messageValue = getchar();
  while(messageValue!=255 && messageValue!=EOF){
    if(messageLength<2048){
        plainText[i] = messageValue;
        messageLength++;
	i++;
    }
    messageValue = getchar();
  }


  int keyValue;
  keyValue = getchar();
  while(keyValue!=EOF){
    if(keyLength<2048){
       key[j] = keyValue;
       initialKeyLength++;
       j++;
    }
    keyValue=getchar();
   }

  /*loops through the key until the same length as message (tiling)*/
  for(i=initialKeyLength, keyLength=initialKeyLength;i<messageLength;i++){
    key[i]=key[i%initialKeyLength];
    keyLength++;
  }

  /*sets sum to be value of last char in key mod length of key*/
  int keySum = key[keyLength - 1] % keyLength;

  /* key[i] = rotate( (key[i] ^ key[sum]), bits(key[i-1]*/
  key[0] = rotate((key[0]^key[keySum]), bits(key[keyLength-1]));

  keySum = keySum + key[0];
  keySum = keySum % keyLength;

  /*loops through above operations until end of key*/
  for(i=1;i<keyLength;i++){
       key[i]=rotate((key[i]^key[keySum]), bits(key[i-1]));
       keySum = keySum + key[i];
       keySum = keySum % keyLength;
  }

  /*Calls the encrypt function*/
  encrypt(plainText,key,messageLength,cipherText);

  for(i=0;i<messageLength;i++)
    putchar(cipherText[i]);
}

/*XORs message[i] ^ key[i]*/
void encrypt(unsigned char plainText[2048], unsigned char key[2048], int length, unsigned char cipherText[2048]){
  unsigned char cipher;
  int i;

  for(i=0;i<length;i++)
    cipherText[i]= (plainText[i])^(key[i]);
}

/*rotates the bits by the specified count*/
unsigned char rotate(unsigned char letter, int count)
{
  int i = 0;
  /*loop until count*/
  for(i=0;i<count;i++){
    /*if the last bit is not 1, shift right by 1*/
    if((letter&1) != 1)
      letter = letter >> 1;
    /*if the last bit is 1, shift right by 1 and XOR by 64 to wrap the 1 around*/
    else{
      letter = letter >> 1;
      letter = letter^64;
    }
  }
  return letter;
}

/*counts the number of 1 bits in the given character*/
int bits(unsigned char character)
{
  int bitCount = 0;
  /*while the character is not 0...*/
  while(character != 0){
    /*if a bit is a 1, increment bitCount*/
    if((character&1)==1)
      bitCount++;
    /*Shift the character right by 1*/
    character = character>>1;
  }
  return bitCount;
}
