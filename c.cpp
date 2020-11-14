#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double w, h;
    cin >> w >> h;
    double diff = (w+h) - sqrt(w*w + h*h);
    printf("%.9f\n", diff);
}