#include<iostream>
using namespace std;

//Menu class : ----
class menu {
    public:
        string item_category;

        struct categorised_item {
            string name;
            int price;
        } item[4];
};

class bill {
    public:
        string item;
        int price, quantity, amount;
};

//Function for the Menu
void displayMenu(int *choice, class menu menu_item[]) {
    cout<<"\n*************************************************************************************************************************";
    cout<<"\n\t\t\t\t\t\t\t\tMENU \t\t\t";
    cout<<"\n*************************************************************************************************************************\n";
    cout<<"\tSr.No.\t|\tItem(s)";
    cout<<"\n*************************************************************************************************************************\n";
    for(int i = 0; i < 5; i++){
        cout<<"\t"<<i+1<<"\t| "<<menu_item[i].item_category<<"\n";
    }
    cout<<"\n*************************************************************************************************************************\n";
    cout<<"Enter what you want to Eat (Enter Index of each you want to purchase one by one) : ";
    cin>>*choice;
}

int main() {
    //variable Declaration
    class menu menu_item[5];

    int choice;
    string conti="y";

    //Main Category 'Pizza'
    menu_item[0].item_category = "Pizzas";

    //Sub Category
    menu_item[0].item[0].name = "Cheese n Corn Pizza";
    menu_item[0].item[0].price = 169;

    menu_item[0].item[1].name = "Margherita Pizza";
    menu_item[0].item[1].price = 99;

    menu_item[0].item[2].name = "Cheese n Tomato Pizza";
    menu_item[0].item[2].price = 169;

    menu_item[0].item[3].name = "Double Cheese Margherita Pizza";
    menu_item[0].item[3].price = 189;

    //Main Category 'Burger'
    menu_item[1].item_category = "Burger";

    //Sub Category
    menu_item[1].item[0].name = "McChicken Burger";
    menu_item[1].item[0].price = 112;

    menu_item[1].item[1].name = "McSpicy Chicken Burger";
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

    menu_item[2].item[2].name = "Cheese Potato Onion sandwich";
    menu_item[2].item[2].price = 69;

    menu_item[2].item[3].name = "Cheese Chilly Garlic Sandwich";
    menu_item[2].item[3].price = 79;

    //Main Category 'Rolls'
    menu_item[3].item_category = "Rolls";

    //Sub Category
    menu_item[3].item[0].name = "Panner Cheese Masala Roll";
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

    menu_item[4].item[3].name = "Red Bucket Special Biryani";
    menu_item[4].item[3].price = 200;

    //Display Menu
    displayMenu(&choice, menu_item);

    cout<<"\n\n"<<choice<<"\n\n";

    return 0;
}