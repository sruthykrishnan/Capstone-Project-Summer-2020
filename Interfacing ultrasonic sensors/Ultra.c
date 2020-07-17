#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
int main()
{
   char pout[3]="out";
   char pin[3]="in";
   int high=1;
   int low= 0;
   int echo1,echo2,echo3;
#define  US1 "/sys/class/gpio/gpio66/value"
#define  US2 "/sys/class/gpio/gpio69/value"
#define  US3 "/sys/class/gpio/gpio60/value"


   FILE *fptr, *fptr1,*fptr2;
   fptr = fopen("/sys/class/gpio/gpio66/direction","w");
   fputs(pout,fptr); //initalizing gpio66 as output
   fclose(fptr);
   fptr = fopen("/sys/class/gpio/gpio67/direction","w");
   fputs(pin,fptr);//initalizing gpio67 as input
   fclose(fptr);
fptr1 = fopen("/sys/class/gpio/gpio69/direction","w");
   fputs(pout,fptr1);//initalizing gpio69 as output
   fclose(fptr1);
fptr1 = fopen("/sys/class/gpio/gpio68/direction","w");
   fputs(pin,fptr1);//initalizing gpio68 as input
   fclose(fptr1);
fptr2 = fopen("/sys/class/gpio/gpio60/direction","w");
   fputs(pout,fptr2);//initalizing gpio60 as output
   fclose(fptr2);
fptr2 = fopen("/sys/class/gpio/gpio48/direction","w");
   fputs(pin,fptr2);//initalizing gpio48 as input
   fclose(fptr2);
   for(int i=0;;i++){  //infinite loop for checking available slot
        int counter=3; // initalizing available slots
        fptr=fopen(US1,"w");
         fprintf(fptr,"%d",high) ; //trigger pulse for ultrasonic 1
        fclose(fptr);
        usleep(1000);
fptr=fopen( US1,"w");
 fprintf(fptr,"%d",low) ;
fclose(fptr);
usleep(10000);
fptr=fopen("/sys/class/gpio/gpio67/value","r");
fscanf(fptr,"%d", &echo1);
if(echo1==1)  //check the voltage from echo pin of ultrasonic 1
printf("space 1:vaccant \n");
else
{printf("space 1: occupied \n");
counter--;  // reduce the number of available slots if occupied
}
fclose(fptr);

fptr1=fopen(US2,"w");
      fprintf(fptr1,"%d",high); //trigger pulse for ultrasonic 2
      fclose(fptr1);
      usleep(1000);
fptr1=fopen( US2,"w");
 fprintf(fptr1,"%d",low) ;
fclose(fptr1);
usleep(10000);
fptr1=fopen("/sys/class/gpio/gpio68/value","r");
fscanf(fptr1,"%d", &echo2);
if(echo2==1)  //check the voltage from echo pin of ultrasonic 2
printf("space 2:vaccant \n");
else
{printf("space 2: occupied \n");
counter--; // reduce the number of available slots if occupied
}
fptr2=fopen(US3,"w");
      fprintf(fptr2,"%d",high); //trigger pulse for ultrasonic 3
      fclose(fptr2);
      usleep(1000);
fptr2=fopen( US3,"w");
 fprintf(fptr2,"%d",low) ;
fclose(fptr2);
usleep(10000);
fptr2=fopen("/sys/class/gpio/gpio48/value","r");
fscanf(fptr2,"%d", &echo3);
if(echo3==1)  //check the voltage from echo pin of ultrasonic 3
printf("space 3:vaccant \n");
else
{printf("space 3: occupied \n");
counter--;//reduce the number of available slots if occupied
}

if(counter==0)
printf("Parking full \n");
else
printf("no. of parking available= %d \n",counter); // print available slots
sleep(1);
}
return 0;
}
.
