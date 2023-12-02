#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>////to manipulate the terminal output delay
//Check the working OS 
#ifdef WIN_32
#define CLEAR_SCREENSCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif
void Credits(void);//display the credits at the startup

//declare the structure to save the data
struct Contact {
  char fName[50], lName[50], address[50], email[50];
  long long phNo;//phone number is long int 
};
//for new user and ->is the arrow operator to save the value in struct Contact using *c

void createContact(struct Contact *c) {
  printf("Enter your first name: ");
  scanf("%s", c->fName);
  printf("Enter your last name: ");
  scanf("%s", c->lName);
  printf("Enter phone: ");
  scanf("%lld", &c->phNo);
  printf("Enter address: ");
  scanf("%s", c->address);
  printf("Enter email: ");
  scanf("%s", c->email);
}
//print contact information
void showContact(struct Contact *c) {
  printf("Name: %s %s\n", c->fName, c->lName);
  printf("Phone: %lld\n", c->phNo);
  printf("Address: %s\n", c->address);
  printf("Email: %s\n", c->email);
}
//save the data in the file 
void writeOnFile() {
  char ch;
  FILE *f1;
  struct Contact c;
  f1 = fopen("CMS.dat", "ab");//append binary as .dat is used
  do {
    createContact(&c);
    fwrite(&c, sizeof(struct Contact), 1, f1);
    printf("Do you have next data? (y/n): ");
    scanf(" %c", &ch);
  } while (ch == 'y' || ch == 'Y');
  printf("Contact has been successfully created...\n");
  fclose(f1); }

//read and display all the saved contact information
void readFromFile() {
  FILE *f2;
  struct Contact c;
  f2 = fopen("CMS.dat", "rb");
  printf("\n================================\n");
  printf("LIST OF CONTACTS\n");
  printf("================================\n");
  while (fread(&c, sizeof(struct Contact), 1, f2) == 1) {
    showContact(&c);
    printf("\n================================\n");
  }
  fclose(f2); }
//search the databased for the user according to saved contact
void searchOnFile() {
  FILE *f3;
  long long phone;
  struct Contact c; 
  printf("Enter phone no.: ");
  scanf("%lld", &phone);
   f3 = fopen("CMS.dat", "rb");
  while (fread(&c, sizeof(struct Contact), 1, f3) == 1) {
    if (phone == c.phNo) {    showContact(&c); }
    else { printf("\n\nNo record not found\n"); } } 
    fclose(f3); }

//if the user is to be deleted from the database
void deleteFromFile() {
  long long num;
  int flag = 0;
  FILE *f4, *f5;
  struct Contact c;
  f5 = fopen("CMS.dat", "rb");
  f4 = fopen("temp.dat", "wb");
  printf("Enter phone no. to delete: ");
  scanf("%lld", &num);
  while (fread(&c, sizeof(struct Contact), 1, f5) == 1) {
    if (c.phNo != num) {
      fwrite(&c, sizeof(struct Contact), 1, f4);
    } else
      flag = 1; }
  fclose(f5);
  fclose(f4);
  remove("CMS.dat");
  rename("temp.dat", "CMS.dat");
  flag == 1 ? printf("\n\n\tContact Deleted...\n") : printf("\n\n\tContact Not Found...\n"); }
  
  //edit the saved contact information
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
      long long pos = -1 * sizeof(struct Contact);//declare the position to start of the contact saved (using -1 *)
      fseek(f6, pos, SEEK_CUR);//seek cursor to start of the selected contact using the position defined above
      fwrite(&c, sizeof(struct Contact), 1, f6);//save the edited contact
      printf("\n\n\tContact Successfully Updated...\n");
      fclose(f6);
      return; } }
  printf("\n\nNo record not found\n");
  fclose(f6);
}

void Credits(void) {
  system(CLEAR_SCREEN);
  printf("\n\n\n\n\n\n\n\n\n\t\t\t\tPROJECT\n\t\t\t     Contact Management System"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tMADE BY\n\t\t\t     Charchil Neupane"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tROLL NO\n\t\t\t\t      12"); sleep(2);
  printf("\n\n\n\n\t\t\t\tSECTION\n\t\t\t          M11"); sleep(2);
  printf("\n\n\n\n\t\t\t\tINSTITUTE:Kathmandu Model Secondary School"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tSUBMITTED TO:Computer Department\n\t\t\t"); sleep(2);
  system(CLEAR_SCREEN); }

int main() {
  Credits();
  system(CLEAR_SCREEN);
  printf("\n\n\n\n\n\n\n\n\t\t\t * WELCOME TO CONTACT MANAGEMENT SYSTEM *");
  getchar();
  while (1) {
    int choice;
    system(CLEAR_SCREEN);
    printf("\nCONTACT MANAGEMENT SYSTEM\n");
    printf("\nMAIN MENU\n");
    printf("=====================\n");
    printf("[1] Add a new Contact\n");
    printf("[2] List all Contacts\n");
    printf("[3] Search for contact\n");
    printf("[4] Delete a Contact\n");
    printf("[5] Edit a Contact\n");
    printf("[0] Exit\n");
    printf("=====================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      system(CLEAR_SCREEN);
      writeOnFile();
      break;
    case 2:
      system(CLEAR_SCREEN);
      readFromFile();
     break;
    case 3:
      system(CLEAR_SCREEN);
      searchOnFile();
      break;
    case 4:
      system(CLEAR_SCREEN);
      deleteFromFile();
      break;
    case 5:
      system(CLEAR_SCREEN);
      editContact();
      break;
    case 0:
      system(CLEAR_SCREEN);
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
      system(CLEAR_SCREEN);
      printf("\n\n\n\t\t\tThank you for using CMS.\n\n");
      exit(0);
      break;
    default:
      continue;
    } }

  return 0; }
