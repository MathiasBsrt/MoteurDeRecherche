#include <stdio.h>

int test1(){
    return 1;
}

int main(int argc, char const *argv[])
{
    int res = test1();
    if(res==1){
        printf("TEST OK");
    }
    else
    {
        printf("error in tes1");
    }
    
    return 0;
}
