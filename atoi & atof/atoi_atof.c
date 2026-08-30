#include<stdio.h>
#include<stdlib.h>
int my_atoi(const char *);
double my_atof(const char *);
int main()
{
    int l, i;
    char s[40];
    printf("enter the string : ");
    scanf("%[^\n]",s);
    for(i=0;s[i];i++)
    {
        if(s[i]=='.')
        {
            printf("l=%lf\n",my_atof(s));
            return 0;
        }
    }
    l=my_atoi(s);
    printf("l = %d\n",l);
    return 0;
}
int my_atoi(const char *p)
{
    int i,num;
    if(p[0]=='-' || p[0]=='+')
        i=1;
    else
        i=0;
    for(num=0; p[i]; i++)
    {
        if(p[i]>='0' && p[i]<='9')
            num=num*10+p[i]-48;
        else
            break;
    }
    if(p[0]=='-')
        num=-num;
    return num;
}
double my_atof(const char *p)
{
    int i,r,c=0;
    double num=0,k=1,n=0;
    if(p[0]=='-' || p[0]=='+')
        i=1;
    else
        i=0;
    for(;p[i] && p[i]!='.';i++)
    {
        if(p[i]>='0' && p[i]<='9')
            num=num*10+p[i]-48;
        else
            break;
    }
    if(p[i]=='.')
    {
	i++;
        for(;p[i];i++)
        {
            if(p[i]>='0' && p[i]<='9')
            {
                r=p[i]-48;
                n=n*10+r;
                c++;
            }
            else
                break;
        }
        for(i=0;i<c;i++)
            k=k*10;
        num=num+n/k;
    }
    if(p[0]=='-')
        num=-num;
    return num;
}

