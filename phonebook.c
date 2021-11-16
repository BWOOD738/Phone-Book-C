//**********************************************************
// Lab: 7 
// Author: Bryce Woodard
// Description: A phone book that lets you add and remove 
// friends. Also allows you to see entire phone book.
//**********************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char fname[50];
    char lname[50];
    char phoneN[50];
} phone;
    
void AddContact (phone*);
void DeleteContact(phone*);
void ShowBook (phone*);
void SortA(phone*); // sort alphabetically
void FindPNum(phone*);
void RandomNum(phone*);
void DeleteBook(phone*);

int contact = 0;

int main()
{
    int choice = 0;
    int total = 0;
    
    phone* phonebook = (phone*) calloc(1, sizeof(phone));
    if (phonebook == NULL)
	{
        printf("ERROR: No remaining memory.");
        return 1;
    }
    
    while(choice != 4)
	{
        printf("\nWhat would you like to do?\n\n");
        printf("1. Add Friend\n");
        printf("2. Delete Friend\n");
        printf("3. Show Phone Book\n");
        printf("4. Sort by first name\n");
        printf("5. Find phone number\n");
        printf("6. Delete all contacts\n");
        printf("7. Select random number\n");
		printf("8. Exit\n\n");
        
        scanf("%d", &choice);
        switch(choice)
		{
            case 1:
                AddContact(phonebook);
                break;
			case 2:
				DeleteContact(phonebook);
				break;          
            case 3:
                ShowBook(phonebook);
                break;
            case 4:
            	SortA(phonebook);
            	break;
            case 5:
            	FindPNum(phonebook);
            	break;
            case 6:
            	DeleteBook(phonebook);
            	break;
            case 7:
            	RandomNum(phonebook);
            	break;
            case 8:
                printf("Goodbye!");
                free(phonebook);
                return 0;
                break;
    	}
    }
}//end main

void AddContact(phone* phonebook)
{
    contact++;
    // this should allocate memory when the contact size increases 
    phone* temp = (phone*) realloc(phonebook, sizeof(phone) * contact);
    
    phonebook = temp;
    
    if (temp == NULL)
	{
        printf("An error has occoured.");
    }
    else
	{
    	printf("First name: ");
    	scanf("%s", phonebook[contact-1].fname);
    	printf("Last name: ");
    	scanf("%s", phonebook[contact-1].lname);
    	printf("Phone number: ");
    	scanf("%s", phonebook[contact-1].phoneN);
	}
}

void DeleteContact(phone* phonebook)
{
	char dfname[50];
	char dlname[50];
	
	printf("Enter first name: ");
	scanf("%s", &dfname);
	
	printf("Enter last name: ");
	scanf("%s", &dlname);
	
	int k;
	for(k = 0; k < contact; k++)
	{
		if(strcmp(dfname, phonebook[k].fname) == 0 && strcmp(dlname, phonebook[k].lname) == 0)
		{
			printf("Deleting contact");
			contact--;
		}
	}
}

void ShowBook (phone* phonebook)
{
    if (contact == 0)
	{
        printf("You have no entries!");
    }
    
    else
	{
    	printf("Your Entries- \n");
    	int i = 0;
    	
    	for(i = 0; i < contact; i++)
		{
    		printf("%d. ", i + 1);
    		printf("%s %s %s\n", phonebook[i].fname, phonebook[i].lname, phonebook[i].phoneN);
    	}
	}
}

void SortA(phone* phonebook)
{
	int i, j;
	char tempStr[20][20];
	
	printf("Contacts sorted alphabetically by first name: \n");
	
	for(i = 0; i < contact; i++)
	{
		for(j = i + 1; j < contact; j++)
		{
			if(strcmp(phonebook[i].fname, phonebook[j].fname) > 0)
			{
				strcpy(tempStr[i], phonebook[i].fname);
				strcpy(phonebook[i].fname, phonebook[j].fname);
				strcpy(phonebook[j].fname, tempStr[i]);				
			}	
		}
	}
	
	for(i = 0; i < contact; i++)
	{
		printf("%s\n", phonebook[i].fname);
	}
}

void FindPNum(phone* phonebook)
{
	char s_name[20];
	int i;
	
	printf("Enter first name: ");
	scanf("%s", s_name);
	
	for(i = 0; i < contact; i++)
	{
		if(strcmp(s_name, phonebook[i].fname) == 0)
		{
			printf("Phone number is: %s", phonebook[i].phoneN);	
		}
		else
		{
			printf("Name not found");	
		}	
	}	
}

void RandomNum(phone* phonebook)
{
	srand(time(NULL));
	printf("Call contact number %d\n", rand() % 1 + contact);
}

void DeleteBook(phone* phonebook)
{
	int i;
	
	for(i = 0; contact = 0; i--)
	{
		contact--;
	}
}