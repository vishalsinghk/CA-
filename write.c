#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
int r;
r=open("myfifo",O_WRONLY);
write(r,"HiThere",5);
}
