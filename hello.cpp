#include<iostream>
using namespace std;
class Hello{
    private:
        int a;
    public:
        Hello(int a){
            this->a=a;
        }
        void print(){
            cout<<"Hello "<<this->a<<endl;
        }
};
int main(){
    Hello *asd = new Hello(-32);
    asd->print();
}