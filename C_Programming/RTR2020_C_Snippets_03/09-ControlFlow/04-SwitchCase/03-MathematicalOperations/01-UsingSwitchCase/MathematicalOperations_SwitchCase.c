#include <stdio.h> //for printf()
#include <conio.h> //for getch()

 int main(void)
 {
   //Variable declarations
   int a_nrl, b_nrl;
   int result_nrl;

   char option_nrl, option_division_nrl;

   //code
   printf("\n\n");

   printf("Enter Value For 'A' : ");
   scanf("%d\n",&a_nrl );

   printf("Enter Value For 'B' : \n" );
   scanf("%d\n",&b_nrl );

   printf("Enter Option  In Character : \n\n" );
   printf("'A' or 'a' For Addition : \n" );
   printf("'S' or 's' For Substraction : ");
   printf("'M'or 'm' For Multiplication : \n" );
   printf("'D' or 'd' For Divison : \n" );

   printf("Enter Option : ");
   option_nrl = getch();

   switch (option_nrl)
   {
     //FALL THROUGH CONSITION FOR 'A' and 'a'
     case 'A':
     case 'a':
            result_nrl= a_nrl + b_nrl;
            printf("Addition Of A = %d And B= %d Gives Result %d !!!\n\n", a_nrl, b_nrl, result_nrl);
            break;

    //FALL THROUGH CONSITION FOR 'S' and 's'

    case 'S':
    case 's':
        if (a_nrl>=b_nrl)
        {
          result_nrl= a_nrl - b_nrl;
          printf("Substration Of B=%d From A = %d Gives Result % !!!]n\n",b_nrl, a_nrl, result_nrl );

        }
        else
        {
            result_nrl = b_nrl - a_nrl;
          printf("Substration Of A = %d From B = %d Gives Result %d !!!\n\n", a_nrl, b_nrl, result_nrl );
        }
    break;

  //FALL THROUGH CONSITION FOR 'M' and 'm';
  case 'M':
  case 'm':
      result_nrl = a_nrl * b_nrl;
      printf("Multiplication Of A = %d And B = %d Gives Result %d !!!\n\n",a_nrl, b_nrl, result_nrl );
        break;

        // FALL THROUGH CONSITION FOR 'D' and 'd'
        case 'D':
        case 'd':
          printf("Enter Option In Character : \n\n");
  printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
  printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");
  printf("Enter Option : ");
  option_division_nrl = getch();

  printf("\n\n");

  switch (option_division_nrl)
    {

  //FALL THROUGH CONSITION FOR 'Q' and 'q' and '/'
  case 'Q':
  case 'q':
  case '/':
    if (a_nrl>=b_nrl)
    {
      result_nrl =  b_nrl / a_nrl;
      printf("Divison Of A = %d By B = %d Gives Quotient = % !!!\n\n",a_nrl, b_nrl, result_nrl );
    }
    else
    {
      result_nrl = b_nrl/a_nrl;
      printf("Divison Of B = %d By A = %d Gives Quotient = %d !!!\n\n",b_nrl, a_nrl, result_nrl );
    }
    break;  //'Break' of case 'Q' or case 'q' or case '/'

    // FALL THROUGH CONSITION FOR 'R' and 'r' and '%'
    case 'R':
    case 'r':
    case '%':
        if (a_nrl >=b_nrl)
        {
          result_nrl = a_nrl % b_nrl;
          printf("Division Of A = %d By B = %d Gives Remainder = %d !!!\n\n",a_nrl, b_nrl, result_nrl );

        }
        else
        {
          result_nrl = b_nrl % a_nrl;
          printf("Division Of B = %d By A=%d Gives Remainder = %d !!!\n\n",b_nrl, a_nrl, result_nrl );
        }
        break; // 'break' of case 'R' or case 'r' or case '%'

    default:  // 'default' case for switch(option_division)
        printf("Invalid Character %c Entered For Division !!! Please Try Again...\n\n\n", option_division_nrl );
      break;  // 'break' of 'default' of switch(option_division)

   } // ending curly brace of switch(option_division)

   break;

    default: // 'break' of case 'D' or case 'd'
    printf("Invalid Charater %c Entered !!! Please Try Again...\n\n",option_nrl );
    break;
    } // ending curly brace of switch(option)
    printf("Switch Case Block Complete !!!\n");

   return 0;
 }
