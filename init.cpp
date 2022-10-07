#include<iostream>
#include"structs.h"
#include"functions.h"

using namespace std;

int main() {
    cout << "Working" <<endl;
    origin origin;
    set_current_origin(&origin);
    init_origin();
    bind_point(1,1);

}