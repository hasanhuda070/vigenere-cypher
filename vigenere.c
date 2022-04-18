//Showad Huda Assignment 1 CIS3360

//Include pre-processor directives
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Character pointers for reading file input
char *read(FILE *inFile, int *index);
char *readPlain(char *pFileName);
char *readKey(char *kFileName);
char *createCipher(char *inPt, char *inKey);
void printOutput(char *forString);

//Main function
//Establish key file and encrypted file parameters
int main(int argc, char **argv){

        int i;
        char *forEncryption = NULL;
        char *key = NULL;
        char *cipher = NULL;

        //Vignere Key set up
        printf("\n\nVigenere Key:\n\n");
        if (!(key = readKey(argv[1])))
                return 0;       
        printOutput(key);

        //Plaintext set up
        printf("\n\nPlaintext:\n\n");  
        if (!(forEncryption = readPlain(argv[2])))
                return 0;       
        printOutput(forEncryption);

        //Cipher set up        
        cipher = createCipher(forEncryption, key);
        printf("Vigenere Key: %s", key);
        printf("\n\nCiphertext:\n\n");
        printOutput(cipher);

        //Free memory from pointers
        free(forEncryption);
        free(key);
        free(cipher);
        return 0;
}

char *read(FILE *inFile, int *index)
{
        //malloc and add 1 for null to 512 characters
        char *forArray = malloc(sizeof(char) * (512 + 1));
        char currChar = '\0';
        forArray[0] = '\0';
        //End of file
        while ((currChar = fgetc(inFile)) != EOF)
        {       
                printf("%c", currChar);
                if (!isalpha(currChar))
                        continue; //if not a character
        
                currChar = tolower(currChar);
                forArray[(*index)++] = currChar;
                forArray[*index] = '\0';
                if ((*index) == 512) //Set parameter of 512 characters, cannot go over.
                        return forArray;         
        }
        return forArray; 
}

//Key text parameters
char *readKey(char *kFileName){

        if (kFileName == NULL)
                return NULL;    
        FILE *myFile = NULL;
        char *newKey = NULL;
        int index = 0;

        if (kFileName == NULL)
                return NULL;
        myFile = fopen(kFileName, "r");
        if (!(myFile = fopen(kFileName, "r")))
                return NULL;

        newKey = read(myFile, &index);
        newKey[index] = '\0';
        return newKey;
}

//Plain text parameters
char *readPlain(char *pFileName){

        //Similar to key text parameters
        if (pFileName == NULL)
                return NULL;
        FILE *myFile = NULL;
        char *newPt = NULL;
        int index = 0;
        myFile = fopen(pFileName, "r"); 
        if (!(myFile = fopen(pFileName, "r")))
                return NULL;
        newPt = read(myFile, &index);

        //X padding goes until 512 characters
        while (index < 512)
        {
                newPt[index++] = 'x';
        }
        newPt[index] = '\0';
        return newPt;
}

char *createCipher(char *inPt, char *inKey){

        int i, x, ptVal, keyVal, insertVal;
        //malloc and add 1 for null to 512 characters
        char *cipher = malloc(sizeof(char) * (512 + 1));
        for (i = x = 0; i < 512; i++)
        {
                //Key decyphering throughtout cypher text
                if (inKey[x] == '\0') 
                        x = 0;
                keyVal = inKey[x] - 'a';
                ptVal = inPt[i] - 'a';
                //26 letters
                insertVal = (keyVal + ptVal) % 26; 
                cipher[i] = tolower('a' + insertVal);

                x++;
        }
        printf("Ciphertext: %s", cipher);
        return cipher;
}

//Print output parameters
void printOutput(char *forString){

        int i = 0, j = 0;
        while (forString[i] != '\0')
        {
                if (j == 80) //Exactly 80 letters per row
                {
                        j = 0;
                        printf("\n");
                }
                printf("%c", forString[i]);
                j++;
                i++;
        }
        printf("\n");
}