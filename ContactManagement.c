#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Contact {
    char name[50];
    long long number;
};
struct Contact *c[200];
int length=0;
void sort();
void insert(char name[50],long long number) {
    c[length++]=(struct Contact*)malloc(sizeof(struct Contact));
    strcpy(c[length-1]->name,name);
    c[length-1]->number=number;
    sort();
}

void display() {
    printf("\n--------contacts--------\n");
    printf("------------------------\n");
    for(int i=0;i<length;i++)
        printf("\n%s\n%lld\n",c[i]->name,c[i]->number);
        
}
void sort() {
    for(int i=0;i<length-1;i++) {
        for(int j=i+1;j<length;j++) {
            for(int k=0;c[i]->name[k]!='\0'&&c[j]->name[k]!='\0';k++) {
                if(c[i]->name[k]>c[j]->name[k]) {
                    struct Contact* t=c[i];
                    c[i]=c[j];
                    c[j]=t;
                    break;
                }
                else if(c[i]->name[k]<c[j]->name[k]) {
                    break;
                }
            }
        }
        //printf("%d   ",sizeof(c[i]->name));
    }
}
//(struct Contact*)malloc(sizeof(struct Contact))
void main() {
    /*
    long long l=9583672357LL;
    insert(c,"SBR",l);
    printf("Calling..... %lld",c->number);
    */
    while(1)
    {
        char s[50];
        long long l;
        printf("\n1:create new contact\n");
        printf("2:show all contacts\n");
        printf("3:add to existing contact\n");
        printf("4:delete the contact\n");
        printf("5:exit\n");
        printf("Choose any option to perform : ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter name : ");
            scanf("%s",s);
            printf("Enter number : ");
            scanf("%lld",&l);
            insert(s,l);
            break;
        case 2:
            display();
            break;
        case 3:

            break;
        case 5:
            return;
        default:
            printf("Invalid option ....");
        }
    }
}