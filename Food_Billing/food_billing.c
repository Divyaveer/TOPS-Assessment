#include<stdio.h>
#include<string.h>
int selectedItems=0, total=0;

struct items{
    char name[20];
    int price;
} item[100];

struct orders{
    char name[20];
    int price, quantity, amount;
} order[100];

int main() {
    int choice;
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
        printf("\n*************************************************************************************************************************");
        printf("\n\t\t\t\t\t\t\t\tMENU \t\t\t");
        printf("\n*************************************************************************************************************************\n");
        printf("\tSr.No.\t|\tItem(s)\t\t\t|\tRate (Rs.)");
        printf("\n*************************************************************************************************************************\n");
        for(int i = 0; i < 8; i++){
            if(strlen(item[i].name) < 6){
                printf("\t%d\t| %s\t\t\t\t|\t%d\n", i+1, item[i].name, item[i].price);
            }else if(strlen(item[i].name) > 14){
                printf("\t%d\t| %s\t\t|\t%d\n", i+1, item[i].name, item[i].price);
            }else if(strlen(item[i].name) > 20){
                printf("\t%d\t| %s\t|\t%d\n", i+1, item[i].name, item[i].price);
            }else{
                printf("\t%d\t| %s\t\t\t|\t%d\n", i+1, item[i].name, item[i].price);
            }
        }
        printf("\n*************************************************************************************************************************\n");
        printf("Enter what you want to Eat (Enter Index of each you want to purchase one by one) : ");
        scanf("%d", &choice);

        if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8){
            printf("\nYou have selected %s.\n", item[choice-1].name);
            printf("Enter the Quantity : ");
            scanf("%d", &order[selectedItems].quantity);

            strcpy(order[selectedItems].name, item[choice-1].name);
            order[selectedItems].price = item[choice-1].price;
            order[selectedItems].amount = order[selectedItems].quantity * item[choice-1].price;
            printf("\nAmount = %d\n", order[selectedItems].amount);
            total += order[selectedItems].amount;
            printf("Total = %d\n", total);
            ++selectedItems;
        }else{
            printf("\n\n\t\tWrong Input!!!....\n\n");
            continue;
        }

        printf("\nDo you want to Continue (Press y for continue) : ");
        scanf(" %c", &conti);
        if(conti == 'y'){
            continue;
        }else{
            printf("\n**********************************************************************************************************************************************************************");
            printf("\n\t\t\t\t\t\t\t\tBilling \t\t\t");
            printf("\n*********************************************************************************************************************************************************************\n");
            printf("\tSr.No.\t|\tItem(s)\t\t\t|\tRate (Rs.)\t\t|\tQuantity\t\t|\tAmount (Rs.)");
            printf("\n*********************************************************************************************************************************************************************\n");
            for(int i = 0; i < selectedItems; i++){
                if(strlen(order[i].name) < 6){
                    printf("\t%d\t| %s\t\t\t\t|\t%d\t\t\t|\t%d\t\t\t|\t%d\n", i+1, order[i].name, order[i].price, order[i].quantity, order[i].amount);
                }else if(strlen(order[i].name) > 14){
                    printf("\t%d\t| %s\t\t|\t%d\t\t\t|\t%d\t\t\t|\t%d\n", i+1, order[i].name, order[i].price, order[i].quantity, order[i].amount);
                }else if(strlen(order[i].name) > 20){
                    printf("\t%d\t| %s\t|\t%d\t\t\t|\t%d\t\t\t|\t%d\n", i+1, order[i].name, order[i].price, order[i].quantity, order[i].amount);
                }else{
                    printf("\t%d\t| %s\t\t\t|\t%d\t\t\t|\t%d\t\t\t|\t%d\n", i+1, order[i].name, order[i].price, order[i].quantity, order[i].amount);
                }
            }
            printf("\n*********************************************************************************************************************************************************************\n");
            printf("Total = %d\n", total);
            printf("\n*********************************************************************************************************************************************************************\n");
            break;
        }
        
    }while(1);
    
    return 0;
}