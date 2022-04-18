//Showad Huda C
import java.io.*;

public class vigenere {
//method to encrypt the data and retrun the cipher text
public static String encrypt(char[] input, char[]key){
//result string
String res = "";
int i;
//add the input and key value and do %26 and convert the same to character again
for(i=0;i<input.length;i++){
res += (char) ((input[i] + key[i] - 2 * 'A') % 26 + 'A');
}
return res;
}

public static void main(String[] args) {
try {
           //consider first input as key file
String key = args[0];
           //second input as inout file
String infile = args[1];
           //file objects
File finKey = new File(key);
File finInput = new File(infile);
           //buffer reader to read the files
BufferedReader binKey = new BufferedReader(new FileReader(finKey));
BufferedReader binInput = new BufferedReader(new FileReader(finInput));

           //reading of key file starts here
           //create a buffer for 512 char
char keyBuffer[] = new char[512];
int i;
           //initially fill them 'x'
for(i=0;i<keyBuffer.length;i++){
keyBuffer[i] = 'x';
}
int counter = 0;
int c;
           //to print the value on the consoloe
System.out.println("Input Key File:");
while((c = binKey.read()) != -1){
char character = (char)c;
               //print the character as it is
System.out.print(character);
               //if the character is letter then consider it for key
if(Character.isLetter(character)){
keyBuffer[counter++] = Character.toLowerCase(character);
}

}

           //reading of input file starts here
           //create a buffer for 512 char
char inputBuffer[] = new char[512];
           //initially fill them 'x'
for(i=0;i<inputBuffer.length;i++){
inputBuffer[i] = 'x';
}
counter = 0;
           //to print the value on the consoloe
System.out.println();
System.out.println();
System.out.println("Input Plaintext File:");
while((c = binInput.read()) != -1){
char character = (char)c;
               //print the character as it is
System.out.print(character);
               //if the character is letter then consider it for iput and convert it to lower case
if(Character.isLetter(character)){
inputBuffer[counter++] = Character.toLowerCase(character);
}
}

           //string to store cipher text
String cipherText = "";
           //call the function
cipherText = encrypt(inputBuffer,keyBuffer);
System.out.println();
System.out.println();
           //print the output
System.out.println("Corresponding Encrypted output: \n");
for(i=0;i<512;i++){
               //print new line after every 80 characters
               if(i>0 && (i%80==0)){
System.out.println();
}
System.out.print(cipherText.charAt(i));
}

}
catch (IOException e){
e.printStackTrace();
}
}
}