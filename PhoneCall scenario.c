#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

char num[12]= {'0','1','2','3','4','5','6','7','8','9','*','#'};

long long int phoneno=0;
int milli_seconds=0;

int phone_no[10];

int random_time()
{
    int greater=10,          smallest=1;
    srand(time(NULL));
    int r  =rand()    %     (greater-smallest+   1)    +    smallest;
    milli_seconds=    1000   *    r;
    return milli_seconds;
}

void Sound()
{
    int time = 0;
    time = random_time();
    Beep(467,time);
}
void dialPad()
{

    system("cls");

    printf("\n\n\t Dial Pad\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |   %c \n",num[1],num[2],num[3]);

    printf("*****|*****|*****\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |   %c \n",num[4],num[5],num[6]);


    printf("*****|*****|*****\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |   %c \n",num[7],num[8],num[9]);

    printf("*****|*****|*****\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |   %c \n",num[10],num[11],num[12]);

    printf("     |     |     \n");
}

void dial()
{
    dialPad();
    printf("Enter the phone number:   \n");
    scanf("%lld", &phoneno);

}

void delay()
{
    int time=0;
    time = random_time();
    clock_t startTime = clock();
    while(clock()<startTime+time);
}

char input_to_end_the_call()
{

    printf("End the call(Y/N)\n");
    char input;
    scanf("%c",&input);
    return input;
}
void randon_phone_number()
{
    srand(time(NULL));
    for(int i=0; i<10; i++)
    {
        phone_no[i] =(rand()%9);
    }
}

void anonymousCall()
{
    int i;
    randon_phone_number();
    printf("Calling from..   \n");
    for(i=0; i<10; i++)
    {
        printf("%d",phone_no[i]);
    }
    delay();
    printf("Ringing...........\n");
    Sound();
    printf("Connected\n");
    printf("Hello!\n");
    char input;
    input= input_to_end_the_call();
    if(input == 'Y')
    {
        printf("Call Ended..\n");
    }
    else
    {
        printf("Please ended the call. i am about to die.....\n");
        input_to_end_the_call();
    }


}

void call()
{
    printf("Calling..............\n");
    delay();
    printf("Ringing...........\n");
    Sound();
    printf("Connected\n");
    printf("Hello!\n");
    char input;
    input= input_to_end_the_call();
    if(input == 'Y')
    {
        printf("Call Ended..\n");
    }
    else
    {
        printf("Please ended the call. i am about to die.....\n");
        input_to_end_the_call();
    }

}


int main()
{
    int choice;
    do
    {
        printf("1.  Dial a Number\n");
        printf("2.  Make a call\n");
        printf("3.   Wanna make a anonymous call?????\n");
        printf("4.   End");
        printf("\nEnter your option: \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            dial ();
            break;
        case 2:
            call ();
            break;
        case 3:
            anonymousCall ();
            break;
        }
    }
    while(choice<4);
    return 0;
}
