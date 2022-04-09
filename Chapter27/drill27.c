//gcc -o d27 drill27.c
#include <stdio.h>

void printing(const char* p, const int x)
{
	printf("p is \"%s\" and x is %i\n",p,x);
}

int main()
{
	//1.
    printf("Hello, World!\n");
    //2.
    char * hello = "Hello";
    char * world = "World!";
    printf("%s %s\n",hello,world);
    //3.
    printing("Carlos",27);
    printing("James",30);
    printing("David",2002);
    
    return 0;
}
