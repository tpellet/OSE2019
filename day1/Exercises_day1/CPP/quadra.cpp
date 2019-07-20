#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
       double a;
       double b;
       double c;
       cout << "enter a ";
       cin >> a;
       cout << "enter b "; 
       cin >> b;
       cout << "enter c "; 
       cin >> c;

       double determinant = pow(b,2)-4*a*c;
       double r1 = (-b - sqrt(determinant))/(2*a);
       double r2 = (-b + sqrt(determinant))/(2*a);

       cout << "Roots are :" << r1 << " and " << r2;

return 0;
}
