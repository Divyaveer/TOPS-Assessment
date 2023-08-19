#include<iostream>
using namespace std;

class test {
    public:
        int a=15, b=18;
        void add(int a, int b){
            cout<<"Addition = "<<a+b<<endl;
        }
};

int main() {
    test t;

    t.add(10, 20);
    
    return 0;
}