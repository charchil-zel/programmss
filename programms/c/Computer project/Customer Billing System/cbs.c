#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct items {
  char items[100];
  float price;
  int quantity;
};
struct total {
  float total, discount, cs, vat;
};
struct orders {
  char customers[100], date[100];
  int noitems;
};
void generateBillHeader(struct orders *c) {
  printf("\n\n");
  printf("\tNeupane. Restaurant\n\t   -----------------");
  printf("\nDate:%s", c->date);
  printf("\nInvoice To: %s\n", c->customers);
  printf("---------------------------------------\nItems\t\t");
  printf("Qty\t\tTotal\t\t\n---------------------------------------\n\n");
}
void generateBillBody(struct items *a) {
  printf("%s\t\t", a->items);
  printf("%d\t\t", a->quantity);
  printf("%.2f\t\t\n", a->quantity * a->price);
}
void generateBillFooter(struct total *t) {
  printf("---------------------------------------\n");
  printf("Sub Total\t\t\t%.2f", t->total);
  printf("\nDiscount @10%s\t\t\t%.2f", "%", t->discount);
  printf("\n\t\t\t\t-------");
  printf("\nNet Total\t\t\t%.2f", t->total - t->discount);
  printf("\nCustomer Service @9%s\t\t%.2f", "%", t->cs);
  printf("\nVat @13%s\t\t\t%.2f", "%", t->vat);
  printf("\n---------------------------------------");
  printf("\nGrand Total\t\t\t%.2f",(t->cs + t->vat) + (t->total - t->discount));
  printf("\n---------------------------------------\n");
}
int main() {
  int opt, n,search = 0;
  char saveBill, choice,name[30];
  start: system("cls");
  printf("\t============Neupane. RESTAURANT============");
  printf("\n\nPlease select your preferred operation\n1. Generate Invoice\n2. Show all Invoices\n3. Search Invoice\n4. Exit\n\nYour choice: ");
  scanf("%d", &opt);
  struct orders ord, orders;
  struct items *item;
  struct total totals;
  switch (opt) {
  case 1:
    system("cls");
    printf("\nPlease enter the name of the customer:\t");
    scanf("%s", ord.customers);
    time_t t = time(NULL);
    strftime(ord.date, sizeof(ord.date), "%Y-%m-%d", localtime(&t));
    printf("\nPlease Enter the Numer of Item Ordered:\t");
    scanf("%d", &n);
    ord.noitems = n;
    item = malloc(n * sizeof(struct items));

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
    totals.cs = 0.09 * totals.total;
    totals.vat = 0.13 * totals.total;
    totals.discount = 0.10 * totals.total;
    ord.noitems = n;
    generateBillHeader(&ord);
    for (int i = 0; i < n; i++) {
      generateBillBody(&item[i]);
    }
    generateBillFooter(&totals);
    printf("\nDo you want to save the invoice [y/n]:\t");
    scanf(" %c", &saveBill);

    if (saveBill == 'y' || saveBill == 'Y') {
      FILE *fp=fopen("bill.dat", "ab");
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
    } free(item);
    break;
  case 2:
    system("cls");
    FILE *fp = fopen("bill.dat", "rb");
    printf("\n *****Your Previous Invoice(s) *****\n");
    while (fread(&ord, sizeof(struct orders), 1, fp)) {
      generateBillHeader(&ord);
      item = malloc(ord.noitems * sizeof(struct items));
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
  case 3:
    printf("Enter the name of the customer to search:\t");
    scanf("%s", name);
    system("cls");
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
        free(item);
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
  scanf(" %c", &choice);
  if (choice == 'y' || choice == 'Y') {
    system("cls");
    goto start;
  }
  return 0;
}
