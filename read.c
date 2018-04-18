#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
void convertOpposite(const char *str);
{
    int ln = strlen(str);
      
    // Conversion according to ASCII values
    for (i=0;i<ln;i++)
    {
        if (str[i]>='a' && str[i]<='z')
        //Convert lowercase to uppercase
            str[i] = str[i] - 32;
        else if(str[i]>='A' && str[i]<='Z')
        //Convert uppercase to lowercase
            str[i] = str[i] + 32;
    }
}
int main()
{
int r;
char buff[50];
r=open("myfifo",O_RDONLY);
read(r,buff,6);
convertOpposite(buff);
printf("%s",buff);
}
