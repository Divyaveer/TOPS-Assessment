#include<iostream>
#include<cstring>

#define MAX_ITEMS_BILL 100

using namespace std;
int numberOfItemsSelected = 0, billTotal=0;

//Menu class : ----
class menu {
    public:
        string item_category;

        struct categorised_item {
            string name;
            int price;
        } item[4];

        void displayVarity(long int *choice) {
            cout<<"\n*************************************************************************************************************************";
            cout<<"\n\t\t\t\t\t\t\t\tMENU \t\t\t";
            cout<<"\n*************************************************************************************************************************\n";
            cout<<"\tSr.No.\t|\tItem(s)\t\t\t|\tRate (Rs./Plate)";
            cout<<"\n*************************************************************************************************************************\n";
            for(int i = 0; i < 4; i++){
                if(item[i].name.size() < 6){
                    cout<<"\t"<<i+1<<"\t| "<<item[i].name<<"\t\t\t\t|\t"<<item[i].price<<"\n";
                }else if(item[i].name.size() > 14 && item[i].name.size() <= 20){
                    cout<<"\t"<<i+1<<"\t| "<<item[i].name<<"\t\t|\t"<<item[i].price<<"\n";
                }else if(item[i].name.size() > 20 && item[i].name.size() < 25){
                    cout<<"\t"<<i+1<<"\t| "<<item[i].name<<"\t\t|\t"<<item[i].price<<"\n";
                }else if(item[i].name.size() >= 25){
                    cout<<"\t"<<i+1<<"\t| "<<item[i].name<<"\t|\t"<<item[i].price<<"\n";
                }else{
                    cout<<"\t"<<i+1<<"\t| "<<item[i].name<<"\t\t\t|\t"<<item[i].price<<"\n";
                }
            }
            cout<<"\n*************************************************************************************************************************\n";
            cout<<"Enter what you want to Eat (Enter Index of each you want to purchase one by one) : ";
            cin>>*choice;
        }
};

class billing {
    public:
        string item;
        int price, quantity, amount;
};

//Function for the Menu
void displayMenu(long int *choice, class menu menu_item[]) {
    cout<<"\n*************************************************************************************************************************";
    cout<<"\n\t\t\t\t\t\t\t\tMENU \t\t\t";
    cout<<"\n*************************************************************************************************************************\n";
    cout<<"\tSr.No.\t|\tItem(s)";
    cout<<"\n*************************************************************************************************************************\n";
    for(int i = 0; i < 5; i++){
        cout<<"\t"<<i+1<<"\t| "<<menu_item[i].item_category<<"\n";
    }
    cout<<"\n*************************************************************************************************************************\n";
    cout<<"Enter which category of food you want to eat (Enter Index of each you want to purchase one by one) : ";
    cin>>*choice;
}

//Funtion for Adding Items in Bill
void addItemBill(class billing bill[], long int *choice, long int *subChoice, class menu menu_item[]) {
    string _continue = "y";
    
    while(_continue == "y") {
        menu_item[*choice-1].displayVarity(subChoice);

        if(*subChoice > 4){
            cout<<"\n\n\t\tWrong Input!!!! Try Again......\n\n";
            continue;
        }else{
            cout<<endl<<"You have selected '"<<menu_item[*choice-1].item[*subChoice-1].name<<"'."<<endl;

            bill[numberOfItemsSelected].item = menu_item[*choice-1].item[*subChoice-1].name;

            cout<<endl<<"Enter the Quantity of "<<menu_item[*choice-1].item[*subChoice-1].name<<" : ";
            cin>>bill[numberOfItemsSelected].quantity;

            bill[numberOfItemsSelected].price = menu_item[*choice-1].item[*subChoice-1].price;
            bill[numberOfItemsSelected].amount = bill[numberOfItemsSelected].price * bill[numberOfItemsSelected].quantity;

            cout<<endl<<"Total Amount of "<<bill[numberOfItemsSelected].item<<" = "<<bill[numberOfItemsSelected].amount<<endl;

            billTotal += bill[numberOfItemsSelected].amount;

            cout<<endl<<"Total Amount of all the items in Bill = "<<billTotal<<endl;

            numberOfItemsSelected++;

            cout<<"Do you want to continue (Press y for continue) : ";
            cin>>_continue;
        }
    }
}

//Function for Bill
void _bill(class billing bill[]) {
    cout<<"\n*************************************************************************************************************************";
    cout<<"\n\t\t\t\t\t\t\t\tBill inVoice\t\t\t";
    cout<<"\n*************************************************************************************************************************\n";
    cout<<"\tSr.No.\t|\tItem(s)\t\t\t|\tRate (Rs./Plate)\t|\tQuantity\t|\tAmount";
    cout<<"\n*************************************************************************************************************************\n";
    for(int i = 0; i < numberOfItemsSelected; i++){
        if(bill[i].item.size() < 6){
            cout<<"\t"<<i+1<<"\t| "<<bill[i].item<<"\t\t\t\t|\t"<<bill[i].price<<"\t\t\t|\t"<<bill[i].quantity<<"\t\t|\t"<<bill[i].amount<<"\n";
        }else if(bill[i].item.size() > 14 && bill[i].item.size() <= 20){
            cout<<"\t"<<i+1<<"\t| "<<bill[i].item<<"\t\t|\t"<<bill[i].price<<"\t\t\t|\t"<<bill[i].quantity<<"\t\t|\t"<<bill[i].amount<<"\n";
        }else if(bill[i].item.size() > 20 && bill[i].item.size() < 25){
            cout<<"\t"<<i+1<<"\t| "<<bill[i].item<<"\t\t|\t"<<bill[i].price<<"\t\t\t|\t"<<bill[i].quantity<<"\t\t|\t"<<bill[i].amount<<"\n";
        }else if(bill[i].item.size() >= 25){
            cout<<"\t"<<i+1<<"\t| "<<bill[i].item<<"\t|\t"<<bill[i].price<<"\t\t\t|\t"<<bill[i].quantity<<"\t\t|\t"<<bill[i].amount<<"\n";
        }else{
            cout<<"\t"<<i+1<<"\t| "<<bill[i].item<<"\t\t\t|\t"<<bill[i].price<<"\t\t\t|\t"<<bill[i].quantity<<"\t\t|\t"<<bill[i].amount<<"\n";
        }
    }
    cout<<"*************************************************************************************************************************\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal = "<<billTotal;
    cout<<"\n*************************************************************************************************************************\n";
}

int main() {
    //variable Declaration
    class menu menu_item[5];
    class billing bill[MAX_ITEMS_BILL];

    long int choice, subChoice;
    string _continue="y";

    //Main Category 'Pizza'
    menu_item[0].item_category = "Pizzas";

    //Sub Category
    menu_item[0].item[0].name = "Cheese n Corn Pizza";
    menu_item[0].item[0].price = 169;

    menu_item[0].item[1].name = "Margherita Pizza";
    menu_item[0].item[1].price = 99;

    menu_item[0].item[2].name = "Cheese n Tomato Pizza";
    menu_item[0].item[2].price = 169;

    menu_item[0].item[3].name = "Double Cheese Pizza";
    menu_item[0].item[3].price = 189;

    //Main Category 'Burger'
    menu_item[1].item_category = "Burger";

    //Sub Category
    menu_item[1].item[0].name = "McChicken Burger";
    menu_item[1].item[0].price = 112;

    menu_item[1].item[1].name = "McSpicy Chicken";
    menu_item[1].item[1].price = 159;

    menu_item[1].item[2].name = "McVeggie Burger";
    menu_item[1].item[2].price = 118;

    menu_item[1].item[3].name = "McSpicy Paneer Burger";
    menu_item[1].item[3].price = 159;

    //Main Category 'Sandwich'
    menu_item[2].item_category = "Sandwich";

    //Sub Category 
    menu_item[2].item[0].name = "DELFINO VEG SANDWICH";
    menu_item[2].item[0].name = 20;

    menu_item[2].item[1].name = "Paneer Sandwhich";
    menu_item[2].item[1].price = 80;

    menu_item[2].item[2].name = "Cheese Potato Onion";
    menu_item[2].item[2].price = 69;

    menu_item[2].item[3].name = "Cheese Chilly Garlic";
    menu_item[2].item[3].price = 79;

    //Main Category 'Rolls'
    menu_item[3].item_category = "Rolls";

    //Sub Category
    menu_item[3].item[0].name = "Panner Cheese Masala";
    menu_item[3].item[0].price = 130;

    menu_item[3].item[1].name = "Double Chicken Roll";
    menu_item[3].item[1].price = 150;

    menu_item[3].item[2].name = "Mirchi Aloo Roll";
    menu_item[3].item[2].price = 79;

    menu_item[3].item[3].name = "Potato Roll";
    menu_item[3].item[3].price = 69;

    //Main Category 'Biryani'
    menu_item[4].item_category = "Biryani";

    //Sub Category
    menu_item[4].item[0].name = "Dum Biryani";
    menu_item[4].item[0].price = 180;

    menu_item[4].item[1].name = "65 Biryani";
    menu_item[4].item[1].price = 240;

    menu_item[4].item[2].name = "Fry Biryani";
    menu_item[4].item[2].price = 180;

    menu_item[4].item[3].name = "Red Bucket Special";
    menu_item[4].item[3].price = 200;


    while(_continue == "y") {
        //Display Menu
        displayMenu(&choice, menu_item);

        if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5){
            addItemBill(bill, &choice, &subChoice, menu_item);
        }else{
            cout<<"\n\n\t\tWrong Input!!!!! Try Again.......\n\n";
            continue;
        }

        cout<<"Do you anythin else? (Press y for yes) : ";
        cin>>_continue;
    }

    _bill(bill);

    return 0;
}