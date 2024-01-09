#include"queue.c"

int main()
{
    
    short usi = -1;
    short si = -32768;
    printf("%x\n",si+usi);
    //7fff,但双标志？扩展到4字节了？
    printf("%d\n",si+usi);

}