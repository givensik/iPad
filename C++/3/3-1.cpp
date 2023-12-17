#include <iostream>
using namespace std;

typedef struct Animal{
    char name[30];
    int age;
    int health;        
    int food; 
    int clean;
}Animal;
Animal* list[30];
void Create_Animal(Animal* a){
    cout << "name :";
    cin >> a->name;
    cout << "age :";
    cin >> a->age;

    a->health = 100;
    a->food = 100;
    a-> clean =100; 
}

void show_stat(int anum){
    cout << "name :" << list[anum]->name << endl;
    cout << "age :" << list[anum]->age << endl;
    cout << "health :" << list[anum]->health << endl;
    cout << "food :" << list[anum]->food << endl;
    cout << "clean :" << list[anum]->clean << endl;
}

int main(){

    int tmp, n=0;
    for(int i=0; i<30; i++){
        cout << "생성 = 1, 끝 = 0 :";
        cin >> tmp;
        if(tmp==0){
            break;
        }
        Animal *a = new Animal;
        Create_Animal(a);
        cout << "입력한 값 =" << a->name <<endl;
        list[i]= a;
        n++;
    }
    // while(1){
    //     cout << "show_stat()=1, end=0";
    //     cin >> "tmp";
        
    //     if(tmp == 0){
    //         break;
    //     }
    //     int anum;
    //     cout << "animal number :";
    //     cin >> anum;
    //     show_stat(anum);
    // }
    
    for(int i=0; i<n; i++){
        show_stat(i);
        delete list[i];
    }
    
    return 0;
}