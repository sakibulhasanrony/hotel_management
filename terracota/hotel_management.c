#include<stdio.h>

#include<stdlib.h>

int again;

int total=0;

int bfrate[7][2]={  {0,30},

                    {1,35},

                    {2,40},

                    {3,20},

                    {4,15},

                    {5,20},

                    {6,30}

                };

int lunchrate[7][2]={{0,120},

                {1,80},

                {2,100},

                {3,120},

                {4,165},

                {5,120},

                };

int dinner_rate[7][2]={{0,120},

                {1,70},

                {2,80},

                {3,165},

                {4,120},

                {5,110},

                {6,100}};

int purchased[][3]={{0,0},

                        {0,0},

                        {0,0},

                        {0,0},

                        {0,0},

                        {0,0},

                        {0,0}

                        };

int temp[][3]={{0,0},

                        {0,0},

                        {0,0},

                        {0,0},

                        {0,0},

                        {0,0},

                        {0,0}

                        };

void bfast(char bfmenu[][100]);

void lunch( char lunchmenu[][100]);

void dinner(char dinnermenu[][100]);

void main_menu();

void display();

void lunch_menucard();

void dinner_menu();

void display_bf_bill(char bfmenu[][100]);

void display_lunch_bill(char lunchmenu[][100]);

void display_dinner_bill(char dinnermenu[][100]);

void display_bfmenu();

void repeatbf(char bfmenu[][100]);

void repeatlunch(char lunchmenu[][100]);

void repeatdinner(char dinnermenu[][100]);

void display_total_words();

void main()

{

    char bfmenu[][100]={"Toast","Porata-Dal","Luchi-Dal","Dim-Vaji","Milk","Tea","Coffee"};

    char lunchmenu[][100]={"Kacchi Biryani","Bhuna Khichuri","Morog Polao","Fried Rice","SpecialMeal(Rice_item)","Nan with Grilled Chicken",};

    char dinnermenu[][100]={"Shik Kabab","Pasta","Noodles","SpecialMeal(Rice_item)","Beef Curry","Fish Fry","Brain Fry",};

    char choice;

    do

    {

        enter:

        display();

        printf("\nEnter your choice here : ");

        scanf("%c", &choice);

        getchar();

        switch(choice)

        {

            case 'A':

            case 'a':printf("\nBreakfast\n");

                    bfast(bfmenu);

                    break;

            case 'B':

             case 'b':printf("\nLunch\n");

                    lunch(lunchmenu);

                    break;

             case 'C':

            case 'c':printf("\nDinner\n");

                    dinner(dinnermenu);

                    break;

           default:printf("\nWrong choice entered Please enter the valid choice!!\n");

                    goto enter;

        }

    }while(choice!='d');

}

void display()

{



    printf("                                       +========================================+          \n\n");

    printf("                                            WELCOME TO TERACOTA RESTAUTANT          \n\n ");

    printf("                                      +========================================+          \n\n");

    printf("Please select the meal that you would like to purchase.  \n\n");

    printf("\t\t      [A] Breakfast\n");

    printf("\t\t      [B] Lunch\n");

    printf("\t\t      [C] Dinner\n");

}

void display_bfmenu()

{



    printf("                                       +========================================+          \n\n");

    printf("                                            WELCOME TO TERACOTA RESTAUTANT          \n\n ");

    printf("                                      +========================================+          \n\n");

    printf("                                                    Breakfast Menu   \n\n"  );

    printf("Please select the food that you would like to purchase. \n\n");

    printf("\t\t   [0] Toast -        Tk 30.00\n");

    printf("\t\t   [1] Porata-Dal -   Tk 35.00\n");

    printf("\t\t   [2] Luchi-Dal -    Tk 40.00\n");

    printf("\t\t   [3] Dim-Vaji -     Tk 20.00\n");

    printf("\t\t   [4] Milk -         Tk 15.00\n");

    printf("\t\t   [5] Tea -          Tk 20.00\n");

    printf("\t\t   [6] Coffee -       Tk 30.00\n");

}

void bfast(char bfmenu[][100])

{

    int choice = 0;

    int quantity = 0;

    int again = 0,amt=0;

    int code,i;

    display_bfmenu();

    printf("\nEnter the code:: ");

    scanf("%d", &code);

    getchar();

    printf("Total is %d\n\n",total);

    if(code>=0&&code<=6)

    {

        printf("\nEnter the quantity::");

        scanf("%d",&quantity);

        purchased[code][1]= quantity*bfrate[code][1];

        total+=purchased[code][ 1];

        printf("Total is %d\n\n",total);

    }

    else

    {

        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");

        bfast(bfmenu);

    }

    repeatbf(bfmenu);

}

void repeatbf(char bfmenu[][100])

{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");

    scanf("%d",&again);

    if (again == 1)

            bfast(bfmenu);

    else if (again == 2 )

    {

        display_bf_bill(bfmenu);

        exit(0);

    }

    else

    {

        printf("\n\n\t\tSorry Invalid Decision Entered\n");

        repeatbf(bfmenu);

    }

}

void display_bf_bill(char bfmenu[][100])

{

    int i;

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

    printf("                    TERACOTA RESTAURANT                   \n");

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

    printf("                    BILLING INFORMATION                \n");

    printf("\n\t\tITEMS\t\tPrice(in Tk.)\n");

    for(i=0;i<7;i++)

    {

        if(purchased[i][1]!=0)

        {

            printf("\n\t\t%s\t\t",bfmenu[i]);

            printf("%d\n",purchased[i][1]);

        }

    }

    printf("\n\t\tTotal=Tk.%d\n",total);

    display_total_words();

    printf("\n\n  +~~~~~~~~~~~~~~~ Thank You ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+        \n  ");

    printf("+~~~~~~~~~~~~~~~ Please Come Again ~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");



}

void display_lunch_bill(char lunchmenu[][100])

{

    int i;

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

    printf("                    TERACOTA RESTAURANT                   \n");

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

    printf("                    BILLING INFORMATION                \n\n");

    printf("\n\t\tITEMS\t\t\tPrice(in Tk.)\n");

    for(i=0;i<6;i++)

    {

        if(purchased[i][1]!=0)

        {

            printf("\n\t\t %s \t\t",lunchmenu[i]);

            printf("%d\n",purchased[i][1]);

        }

    }

    printf("\n\t\tTotal=Tk.%d\n",total);

    display_total_words();

    printf("\n\n  +~~~~~~~~~~~~~~~ Thank You ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+        \n  ");

    printf("+~~~~~~~~~~~~~~~ Please Come Again ~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

}

void display_dinner_bill(char dinnermenu[][100])

{

    int i;

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

    printf("                    TERACOTA RESTAURANT                   \n");

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

    printf("                    BILLING INFORMATION               \n\n");

    printf("\n\t\tITEMS\t\t\tPrice(in Tk.)\n");

    for(i=0;i<7;i++)

    {

        if(purchased[i][1]!=0)

        {

            printf("\n\t\t %s \t\t",dinnermenu[i]);

            printf("%d\n",purchased[i][1]);

        }



    }

    printf("\n\t\tTotal=Tk.%d\n\n",total);

    display_total_words();

    printf("\n\n  +~~~~~~~~~~~~~~~ Thank You ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n");

    printf("+~~~~~~~~~~~~~~~ Please Come Again ~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

}

void lunch(char lunchmenu[][100])

{

    int choice = 0;

    int quantity = 0;

    int again = 0,amt=0;

    int code,i;

    lunch_menucard();

    printf("\nEnter the code:: ");

    scanf("%d", &code);

    getchar();

    if(code>=0&&code<=6)

    {

        printf("\nEnter the quantity::");

        scanf("%d",&quantity);

        purchased[code][1]= quantity*lunchrate[code][1];

         total+=purchased[code][1];

    }

    else

    {

        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");

         lunch(lunchmenu);

    }

    repeatlunch(lunchmenu);

}

void dinner(char dinnermenu[][100])

{

    int choice = 0;

    int quantity = 0;

    int again = 0,amt=0;

    int code,i;

    dinner_menu();



    printf("\nEnter the code:: ");

    scanf("%d", &code);

    getchar();

    if(code>=0&&code<=6)

    {

        printf("\nEnter the quantity::");

        scanf("%d",&quantity);

        purchased[code][1]= quantity*dinner_rate[code][1];

        total+=purchased[code][1];

    }

    else

    {

        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");

        dinner(dinnermenu);

    }

    repeatdinner(dinnermenu);

}

void lunch_menucard()

{



    printf("                                       +========================================+          \n\n");

    printf("                                            WELCOME TO TERACOTA RESTAUTANT          \n\n ");

    printf("                                      +========================================+          \n\n");

    printf("                                                    Lunch Menu   \n\n");

    printf("Please select the food that you would like to purchase.  \n\n");

    printf("\t\t   [0] Kacchi-Biryani -            Tk 120.00\n");

    printf("\t\t   [1] Bhuna-khichuri-             Tk 80.00\n");

    printf("\t\t   [2] Morog-polao -               Tk 100.00\n");

    printf("\t\t   [3] Fried Rice -                Tk 120.00\n");

    printf("\t\t   [4] Special meal(rice-item) -   Tk 165.00\n");

    printf("\t\t   [5] Roti with Grilled chicken - Tk 120.00\n");



    printf("\nEnter your choice here : ");

}

void dinner_menu()

{

    printf("                                       +========================================+          \n\n");

    printf("                                            WELCOME TO TERACOTA RESTAUTANT          \n\n ");

    printf("                                      +========================================+          \n\n");

    printf("                                                     Dinner Menu   \n\n");

    printf("Please select the food that you would like to purchase.  \n\n");

    printf("\t\t   [0] Shik Kabab -               Tk 120.00\n");

    printf("\t\t   [1] Pasta -                    Tk 70.00\n");

    printf("\t\t   [2] Noodles -                  Tk 80.00\n");

    printf("\t\t   [3] Special meal(rice-item) -  Tk 165.00\n");

    printf("\t\t   [4] Beef Curry -               Tk 120.00\n");

    printf("\t\t   [5] Fish Fry -                 Tk 110.00\n");

    printf("\t\t   [6] Brain Fry -                Tk 100.00\n");

}

void repeatlunch(char lunchmenu[][100])

{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");

    scanf("%d",&again);

    if (again == 1)

            lunch(lunchmenu);

    else if (again == 2 )

    {

        display_lunch_bill(lunchmenu);

        exit(0);

    }

    else

    {

        printf("\n\n\t\tSorry Invalid Decision Entered\n");

        repeatlunch(lunchmenu);

    }

}

void repeatdinner(char dinnermenu[][100])

{



    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");

    scanf("%d",&again);

    if (again == 1)

    {

        dinner(dinnermenu);

    }

    else if (again == 2 )

    {

        display_dinner_bill(dinnermenu);

        exit(0);

    }

    else

    {

        printf("\n\n\t\tSorry Invalid Decision Entered\n");

        repeatdinner(dinnermenu);

    }

}

void display_total_words()

{

    int num=0,digits=0,temp=0;

    while(total != 0)

    {

        num=(num * 10)+(total % 10);

        total/= 10;

        digits++;

    }

    printf("\nNo of digits::%d\n",digits);

    while(num!= 0)

    {

        temp++;

        switch(num%10)

        {

            case 0:

                printf("Zero ");

                break;

            case 1:

                printf("One ");

                break;

            case 2:

                printf("Two ");

                break;

            case 3:

                printf("Three ");

                break;

            case 4:

                printf("Four ");

                break;

            case 5:

                printf("Five ");

                break;

            case 6:

                printf("Six ");

                break;

            case 7:

                printf("Seven ");

                break;

            case 8:

                printf("Eight ");

                break;

            case 9:

                printf("Nine ");

                break;

        }

        num = num / 10;

    }

    if(num==0&&digits!=temp)

        printf(" Zero ");

    return;



}