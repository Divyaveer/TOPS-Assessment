#include<stdio.h>
#include<string.h>

struct items
{
    char name[20];
    int price, quantity, amount;
} item[100];

int main() {
    int choice, total=0;
    char conti;

    strcpy(item[0].name, "Pizza");
    strcpy(item[1].name, "Burger");
    strcpy(item[2].name, "Dosa");
    strcpy(item[3].name, "Idli");
    strcpy(item[4].name, "Steam Rice");
    strcpy(item[5].name, "Dal Fry");
    strcpy(item[6].name, "Kadai Paneer");
    strcpy(item[7].name, "Mix Veg");

    item[0].price = 180;
    item[1].price = 100;
    item[2].price = 120;
    item[3].price = 50;
    item[4].price = 150;
    item[5].price = 110;
    item[6].price = 135;
    item[7].price = 90;

    do{
        printf("---------------------------- Menu ----------------------------\n");        
        printf("1. Pizza\tPrice = Rs.180/PCS\n");
        printf("2. Burger\tPrice = Rs.100/PCS\n");
        printf("3. Dosa\tPrice = Rs.120/PCS\n");
        printf("4. Idli\tPrice = Rs.50/PCS\n");
        printf("5. Steam Rice\tPrice = Rs.150\n");
        printf("6. Dal Fry\tPrice = Rs.110\n");
        printf("7. Kadai Paneer\tPrice = Rs.135\n");
        printf("8. Mix Veg\tPrice = Rs.90\n");
        printf("----------------------------- X ------------------------------\n");
        printf("Enter what you want to Eat (Enter Index of each you want to purchase one by one) : ");
        scanf("%d", &choice);

        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6){
            printf("\n\n\t\tWrong Input!!!....\n\n");
            continue;
        }else{
            printf("\nYou have selected %s.\n", item[choice-1].name);
            printf("Enter the Quantity : ");
            scanf("%d", &item[choice-1].quantity);

            item[choice-1].amount = item[choice-1].quantity * item[choice-1].price;
            printf("\nAmount = %d\n", item[choice-1].amount);
            total += item[choice-1].amount;  
            printf("Total = %d\n", total);
        }

        printf("\nDo you want to Continue (Press y for continue) : ");
        scanf(" %c", &conti);
        if(conti == 'y'){
            continue;
        }else{
            printf("\n------------------------------- Bill -------------------------------\n");
            for(int i=0; i<100; i++){
                if(item[i].quantity != 0){
                    printf("%s\tQuantity = %d\tAmount = %d\n", item[i].name, item[i].quantity, item[i].amount);
                }
            }
            printf("--------------------------------------------------------------------\n");
            printf("Total = %d\n", total);
            printf("--------------------------------------------------------------------\n");
            break;
        }
        
    }while(1);
    
    return 0;
}