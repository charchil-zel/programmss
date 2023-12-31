#include <stdio.h> 
#include <stdlib.h>

struct Contact {
  char fName[50], lName[50], address[50];
  long long phNo;
};
void createContact(struct Contact *c) {
  printf("Enter your first name: ");
  scanf("%s", c->fName);
  printf("Enter your last name: ");
  scanf("%s", c->lName);
  printf("Enter phone: ");
  scanf("%lld", &c->phNo);
  printf("Enter address: ");
  scanf("%s", c->address);
}
void showContact(struct Contact *c) {
  printf("Name: %s %s\n", c->fName, c->lName);
  printf("Phone: %lld\n", c->phNo);
  printf("Address: %s\n", c->address);
}
void writeOnFile() {
  char ch;
  FILE *f1;
  struct Contact c;
  f1 = fopen("CMS.dat", "ab");
  do {
    createContact(&c);
    fwrite(&c, sizeof(struct Contact), 1, f1);
    printf("Do you have next data? (y/n): ");
    scanf(" %c", &ch);
  } while (ch == 'y' || ch == 'Y');
  printf("Contact has been successfully created...\n");
  fclose(f1); }

void readFromFile() {
  FILE *f2;
  struct Contact c;
  f2 = fopen("CMS.dat", "rb");
  printf("\n================================\nLIST OF CONTACTS\n================================\n");
  while (fread(&c, sizeof(struct Contact), 1, f2) == 1) {
    showContact(&c);
    printf("\n================================\n");
  }
  fclose(f2); }
void searchOnFile() 
{
  FILE *f3;
  long long phone;
  struct Contact c; 
  printf("Enter phone no.: ");
  scanf("%lld", &phone);
   f3 = fopen("CMS.dat", "rb");
  while (fread(&c, sizeof(struct Contact), 1, f3) == 1) {
    (phone==c.phNo)?(showContact(&c)):printf("\n\nNo record not found\n");    
}
    fclose(f3); 
}
void deleteFromFile() 
{
  long long num;  int flag = 0;
  FILE *f4, *f5;
  struct Contact c;
  f5 = fopen("CMS.dat", "rb");
  f4 = fopen("temp.dat", "wb");
  printf("Enter phone no. to delete: ");
  scanf("%lld", &num);
  while (fread(&c, sizeof(struct Contact), 1, f5) == 1) {
    (c.phNo != num)?fwrite(&c, sizeof(struct Contact), 1, f4):(flag = 1);
  }
  fclose(f5);
  fclose(f4);
  remove("CMS.dat");
  rename("temp.dat", "CMS.dat");
  flag == 1 ? printf("\n\n\tContact Deleted...\n") : printf("\n\n\tContact Not Found...\n"); 
  }
  
void editContact() {
  long long num;
  FILE *f6;
  struct Contact c;
   printf("Edit contact\n");
  printf("===============================\n\n");
  printf("Enter the phone number to be edited: ");
  scanf("%lld", &num);
   f6 = fopen("CMS.dat", "rb+");
  while (fread(&c, sizeof(struct Contact), 1, f6) == 1) {
    if (c.phNo == num) {
      printf("Enter new record\n");
      createContact(&c);
      long long pos = -1 * sizeof(struct Contact);
      fseek(f6, pos, SEEK_CUR);
      fwrite(&c, sizeof(struct Contact), 1, f6);
      printf("\n\n\tContact Successfully Updated...\n");
      fclose(f6);
      return; } }
  printf("\n\nNo record not found\n");
  fclose(f6);
}

int main() {
  system("cls");
  printf("\n* WELCOME TO CONTACT MANAGEMENT SYSTEM  *\n*Developed by Charchil Neupane *\n\n");
  getchar();
  while (1) {
    int choice;
    system("cls");
    printf("\nCONTACT MANAGEMENT SYSTEM\n");
    printf("\nMAIN MENU\n=====================\n");
    printf("[1] Add a new Contact\n");
    printf("[2] List all Contacts\n");
    printf("[3] Search for contact\n");
    printf("[4] Delete a Contact\n");
    printf("[5] Edit a Contact\n");
    printf("[0] Exit\n=====================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      system("cls");
      writeOnFile();
      break;
    case 2:
      system("cls");
      readFromFile();
     break;
    case 3:
      system("cls");
      searchOnFile();
      break;
    case 4:
      system("cls");
      deleteFromFile();
      break;
    case 5:
      system("cls");
      editContact();
      break;
    case 0:
      system("cls");
      printf("\n\n\n\t\t\tThank you for using CMS.\n\n");
      exit(0);
      break;
    default:
      continue;
    }
    int opt;
    printf("\n\n..::Enter the Choice:\n[1] Main Menu\t\t[0] Exit\n");
    scanf("%d", &opt);
    switch (opt) {
    case 0:
      system("cls");
      printf("\n\n\n\t\t\tThank you for using CMS.\n\n");
      exit(0);
      break;
    default:
      continue;
    } }
  return 0; }
