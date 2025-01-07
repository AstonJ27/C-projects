#include <stdio.h>
int main() {
 float cel, far;
 printf("ingrese una temperatura en grados celsius: ");
 scanf("%f",&cel);
 far=cel*9/5+32;
 printf("en grados fahrenheit es: %.4f\n",far);

return 0; }
