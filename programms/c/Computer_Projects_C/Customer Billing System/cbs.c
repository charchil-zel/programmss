
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//to fetch the current date
//to check the current OS used 
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

//Declare structures 
struct items {
  char items[100];
  float price;
  int quantity;
};

struct total {
  float total,discount,cs,vat;
};

struct orders {
  char customers[100], date[100];
  int noitems;
};
//generate the bill headers by displaying the required information passed from struct orders...
void generateBillHeader(struct orders *c) {
  printf("\n\n");
  printf("\t    Neupane. Restaurant");
  printf("\n\t   -----------------");
  printf("\nDate:%s", c->date);
  printf("\nInvoice To: %s\n", c->customers);
  printf("---------------------------------------\nItems\t\t");
  printf("Qty\t\tTotal\t\t");
  printf("\n---------------------------------------\n\n");
}
//generate the bill body by displaying the required information passed from struct items...
void generateBillBody(struct items *a) {
  printf("%s\t\t", a->items);
  printf("%d\t\t", a->quantity);
  printf("%.2f\t\t\n", a->quantity * a->price);
}
//calculate and generate the footer of the bill
void generateBillFooter(struct total *t) {
  printf("---------------------------------------\n");
  printf("Sub Total\t\t\t%.2f", t->total);
  printf("\nDiscount @10%s\t\t\t%.2f", "%", t->discount);
  printf("\n\t\t\t\t-------");
  printf("\nNet Total\t\t\t%.2f", t->total - t->discount);
  printf("\nCustomer Service @9%s\t\t%.2f", "%", t->cs);
  printf("\nVat @13%s\t\t\t%.2f", "%", t->vat);
  printf("\n---------------------------------------");
  printf("\nGrand Total\t\t\t%.2f",
         (t->cs + t->vat) + (t->total - t->discount));
  printf("\n---------------------------------------\n");
}

int main() {//call up the main function
  int opt, n;
  char saveBill;
  char name[30];
  int search = 0;
  char choice;

  start: system(CLEAR_SCREEN);
  printf("\t============ADV. RESTAURANT============");
  printf("\n\nPlease select your prefered operation");
  printf("\n\n1.Generate Invoice");
  printf("\n2.Show all Invoices");
  printf("\n3.Search Invoice");
  printf("\n4.Exit");
  printf("\n\nYour choice:\t");
  scanf("%d", &opt);
  
  struct orders ord, orders;
  struct items *item;
  struct total totals;
  switch (opt) {
  case 1:
    system(CLEAR_SCREEN);
    printf("\nPlease enter the name of the customer:\t");
    scanf("%s", ord.customers);
    time_t t = time(NULL);//generate the time by declaring the pointer t
    strftime(ord.date, sizeof(ord.date), "%Y-%m-%d", localtime(&t));//print the current date
    printf("\nPlease Enter the Numer of Item Ordered:\t");
    scanf("%d", &n);
    ord.noitems = n;
    item = malloc(n * sizeof(struct items));//dynamic memory allocation for the items when large no. are collected from the file 
    
    totals.total = 0;
    for (int i = 0; i < n; i++) {
      fgetc(stdin);
      printf("\n\n");
      printf("Please enter the itemno. %d:\t", i + 1);
      scanf("%s", item[i].items);
      printf("Please enter the quantity of items: \t");
      scanf("%d", &item[i].quantity);
      printf("Please enter the unit price: \t");
      scanf("%f", &item[i].price);
      totals.total += item[i].price * item[i].quantity;
    }
  //Calculate service charge, vat and discount as per defined 
    totals.cs = 0.09 * totals.total;
    totals.vat = 0.13 * totals.total;
    totals.discount = 0.10 * totals.total;
    ord.noitems = n;
    generateBillHeader(&ord);//generate header using the above information
    for (int i = 0; i < n; i++) {
      generateBillBody(&item[i]);//generate body from the entered items stored in struct items.. 
    }
    generateBillFooter(&totals);//generate footer by calculating totals
    printf("\nDo you want to save the invoice [y/n]:\t");
    scanf(" %c", &saveBill);
    
    //Save the invoice in the database and write the data into the file in format as per structure for easier to scan the data later 
    if (saveBill == 'y' || saveBill == 'Y') {
      FILE *fp=fopen("bill.dat", "ab");//append binary as .dat is used 
      if (fp == NULL) {
        printf("\n\nError in opening file");
      } else {
        fwrite(&ord, sizeof(struct orders), 1, fp);
        for (int i = 0; i < ord.noitems; i++) {
          fwrite(&item[i], sizeof(struct items), 1, fp);
        }
        fwrite(&totals, sizeof(struct total), 1, fp);
        printf("\nSucessfully Saved the Invoice...::-)\n");
      }
      fclose(fp);
    } free(item);//free memory allocated (otherwise overflow of memory)
    break;
    //generate saved invoices 
  case 2:
    system(CLEAR_SCREEN);
    FILE *fp = fopen("bill.dat", "rb");//read binary from the file in specific format as saved 
    printf("\n *****Your Previous Invoice(s) *****\n");
    while (fread(&ord, sizeof(struct orders), 1, fp)) {
      generateBillHeader(&ord);
      item = malloc(ord.noitems * sizeof(struct items));
      //free(item);
      if (item == NULL) {
        printf("Allocation fail");
        break;
      }
      for (int i = 0; i < ord.noitems; i++) {
        fread(&item[i], sizeof(struct items), 1, fp);
        generateBillBody(&item[i]);
      }
      fread(&totals, sizeof(struct total), 1, fp);
      generateBillFooter(&totals);
    }
    fclose(fp);
    break;

    //Search invoice based on customer name
  case 3:
    printf("Enter the name of the customer to search:\t");
    scanf("%s", name);
    system(CLEAR_SCREEN);
    FILE *fp1 = fopen("bill.dat", "rb");
    printf("\t*****Invoice of %s *****\n", name);
    while (fread(&orders, sizeof(struct orders), 1, fp1) == 1) {
      if (strcmp(orders.customers, name) == 0) {
        generateBillHeader(&orders);
        item = malloc(orders.noitems * sizeof(struct items));
        if (item == NULL) {
          printf("Allocation fail");
          break;
        }
        for (int i = 0; i < orders.noitems; i++) {
          fread(&item[i], sizeof(struct items), 1, fp1);
        }
        fread(&totals, sizeof(struct total), 1, fp1);
        for (int i = 0; i < orders.noitems; i++) {
          generateBillBody(&item[i]);
        }
        generateBillFooter(&totals);
        search++;
        free(item);//free memory
        break;
      }
    }
    if (search == 0) {
      printf("Sorry! The invoice for %s was not found...", name);
    }
    fclose(fp1);
    break;

  case 4:
    printf("\n\t\tThanks for the visit :)\n");
    exit(0);
    break;

  default:
    printf("\n\t\tInvalid choice\n");
  }

  printf("\nDo you want to perfrom another option?[y/n]:\t\n");
  scanf(" %c", &choice); {
    if (choice == 'y' || choice == 'Y') {
      system(CLEAR_SCREEN);
      goto start;
    }
  }
  return 0;
}
