#include<stdio.h>

int main() {
    int item, p=180, b=100, d=120, i=50, total=0, quantity, amount;
    char conti;

    do{
        printf("--------------- Menu ---------------\n");
        printf("1. Pizza\tPrice = Rs.180/PCS\n");
        printf("2. Burger\tPrice = Rs.100/PCS\n");
        printf("3. Dosa\tPrice = Rs.120/PCS\n");
        printf("4. Idli\tPrice = Rs.50/PCS\n");
        printf("Please Enter your Choice : ");
        scanf("%d", &item);

        switch(item){
            case 1:
                printf("You have selected Pizza.\n");
                printf("Enter the Quantity : ");
                scanf("%d", &quantity);

                amount = quantity * p;
                printf("Amount : %d\n", amount);
                total = total + amount;
                printf("Total Amount : %d\n", total);
                break;
            case 2:
                printf("You have selected Burger.\n");
                printf("Enter the Quantity : ");
                scanf("%d", &quantity);

                amount = quantity * b;
                printf("Amount : %d\n", amount);
                total = total + amount;
                printf("Total Amount : %d\n", total);
                break;
            case 3:
                printf("You have selected Dosa.\n");
                printf("Enter the Quantity : ");
                scanf("%d", &quantity);

                amount = quantity * d;
                printf("Amount : %d\n", amount);
                total = total + amount;
                printf("Total Amount : %d\n", total);
                break;
            case 4:
                printf("You have selected Idli.\n");
                printf("Enter the Quantity : ");
                scanf("%d", &quantity);

                amount = quantity * i;
                printf("Amount : %d\n", amount);
                total = total + amount;
                printf("Total Amount : %d\n", total);
                break;
            default:
                printf("\n\n\t\tInvalid Option!!!!!.....\n\n");
        }

        printf("Do you Want to Continue : ");
        scanf(" %c", &conti);
    }while(conti == 'y');
    
    return 0;
}