#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isIdentifier(char ibuffer[])
{
       int f=1,i;
int l = sizeof(ibuffer)/sizeof(ibuffer[0]);
    if((ibuffer[0]>='a' && ibuffer[0]<='z')||(ibuffer[0]>='A' && ibuffer[0]<='Z')||(ibuffer[0]=='_'))
    {
        for(i=1; i<l; i++)
        {
            if((ibuffer[i]>='a' && ibuffer[i]<='z')||(ibuffer[i]>='A' && ibuffer[i]<='Z')||(ibuffer[i]>='0' && ibuffer[i]<='9')||(ibuffer[i]=='_'))
            {
                f++;
            }

        }
        if(f==l)
        {
            return 1;
        }
    }
}


int isKeyword(char buffer[]){
char keywords[33][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while","printf"};
int i, flag = 0;
for(i = 0; i < 33; ++i){
if(strcmp(keywords[i], buffer) == 0){
flag = 1;
break;
}
}
return flag;
}

int isOperator(char ch){
char operators[] = {"+-*/%=><"};
int i, flag = 0;
for(i = 0; i < 8; ++i){
if(operators[i]==ch){
flag = 1;
break;
}
}
return flag;
}

int isOther(char ch){
char others[] = {"(){};"};
int i, flag = 0;
for(i = 0; i < 5; ++i){
if(others[i]== ch){
flag = 1;
break;
}
}
return flag;
}

int op_id=0,keyword_id=0, line=1,other_id=0,identifier_id=0,number_id=0,literal_id=0;

int main(){
char ch, buffer[15],ibuffer[15],literal[20] ;
ifstream fin("program.txt");

int i,j=0,k=0,l=0;
if(!fin.is_open()){
cout<<"error while opening the file\n";
exit(0);
}
cout<<"Symbol\t"<<"symbol_id\t"<<"token_type\t"<<"value\t"<<"Line number\t"<<endl;
while(!fin.eof()){
   ch = fin.get();



   if (ch=='\n')
    {line++;
    }





   if(isalnum(ch)){
   buffer[j++] = ch;
   }
   else if((ch == ' ' || ch == '\n'||isOperator(ch)||isOther(ch)) && (j != 0)){
   buffer[j] = '\0';
   j = 0;
      if(isKeyword(buffer) == 1)
   {keyword_id++;
    cout<<buffer<<"\t"<<"keyword_"<<keyword_id<<"\t"<<"keyword\t"<<"\t-\t"<<line<<"\t"<<endl;
   }
   else if(isIdentifier(buffer)==1)
    {identifier_id++;
    cout<<buffer<<"\t"<<"identifier_"<<identifier_id<<"\t"<<"identifier\t"<<"-\t"<<line<<"\t"<<endl;
    }
    else if(isKeyword(buffer) == 0&&isIdentifier(buffer)==0&&isalpha(buffer[0])==1)
    {
        literal_id++;
    cout<<buffer<<"\t"<<"literal_"<<literal_id<<"\t"<<"literal\t\t"<<"-"<<"\t"<<line<<"\t"<<endl;
    }
    else
    {
             number_id++;
    cout<<buffer<<"\t"<<"number_"<<number_id<<"\t"<<"number\t\t"<<buffer<<"\t"<<line<<"\t"<<endl;

    }

   }
      if(isOther(ch) == 1)
   {
       other_id++;
       cout<<ch<<"\t"<<"other_"<<other_id<<"\t"<<"\tOther\t"<<"\t-\t"<<line<<"\t"<<endl;
   }

   if(isOperator(ch) == 1)
   { op_id++;

   cout<<ch<<"\t"<<"Op_"<<op_id<<"\t"<<"\tOperator"<<"\t-\t"<<line<<"\t"<<endl;
   }

   if (ch==' ')
    continue;

}
fin.close();
cout<<"\nMd. Istiak Ahmed Khan\n\n\n";
return 0;
}

