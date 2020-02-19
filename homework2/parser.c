//INSTRUCTIONS
//Your parser will read from input.txt
//input.txt consists of a series inputs that you need to read.
//each input is proceeded by a flag.
//Each flag will be either I, C, or F.
//I means int, C means char, F means float.

//So for example
//I 7963467
//means int 7963467
//C H
//means char H
//F 0.7896
//means float 0.7896

//Your parser must read in each input, and then print it to the
//correct file.
//ints go in ints.txt
//chars go in chars.txt
//floats go in floats.txt
//CODE BEGINS HERE
#include <stdio.h>
//include fprintf and fscanf
//begin your main function
int main()
{
  FILE *intfile;
  FILE *charfile;
  FILE *floatfile;
  intfile = fopen("intFile.txt", "w+");
  charfile = fopen("charFile.txt", "w+");
  floatfile = fopen("floatFile.txt", "w+");
  //open ints.txt, chars.txt, and floats.txt for writing
  //open input.txt for reading
  //don't forget that the file access mode is different for each!
  FILE *input;
  input = fopen("input.txt", "r+");
  //create a char variable to hold the flags you read
  char flag[255];
  //create an int, char, and float variable to hold the int, char,
  //and float values you read
  int value_integer[255];
  char value_character[255];
  float value_float[255];
  //while fscanf does not return an EOF error
  //read in a flag from input.txt
  while (fscanf(input, "%s", &flag) != EOF)
  {
    // printf("flag is: %s\n", flag);
    switch (*flag)
    {
      //if it stands for an int
      //read an int from input.txt
      //write the int to ints.txt
    case 'C':
      while (fscanf(input, "%s", value_character) != EOF)
      {
        fputs(value_character, charfile);
        fputs(" ", charfile);
        break;
      }
      break;
      //if it stands for a char
      //read a char from input.txt
      //write the char to chars.txt
    case 'I':
      while (fscanf(input, "%s", value_integer) != EOF)
      {
        fputs(value_integer, intfile);
        fputs(" ", intfile);
        break;
      }
      break;
      //if it stands for a float
      //read a float from input.txt
      //write the float to floats.txt
    case 'F':
      while (fscanf(input, "%s", value_float) != EOF)
      {
        fputs(value_float, floatfile);
        fputs(" ", floatfile);
        break;
      }
      break;
    }
  }
  fclose(intfile);
  fclose(charfile);
  fclose(floatfile);
  fclose(input);
  //once fscanf returns and EOF error return a successful exit
  //status
  return 0;
}
