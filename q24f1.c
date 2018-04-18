#include<sys/stat.h>
int main()
{
int r;
r=mkfifo("myfifo",0777);
if(r==0)
{
printf("Created");
}
else
{
printf("error");
}
}

