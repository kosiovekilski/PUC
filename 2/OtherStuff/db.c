# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define NAME_LEN 30
# define BRAND_LEN 15
# define ADDRESS_LEN 20

typedef struct {
    long id;
    char name [NAME_LEN];
    char brand [BRAND_LEN];
    double price, weight;
    char address [ADDRESS_LEN];
} Product;

void getNewProduct (Product * p) {
        printf ("     id: ");
        scanf (" %d", & p->id);
        printf ("   name: ");
        scanf (" %s", p->name);
        printf ("  brand: ");
        scanf (" %s", p->brand);
        printf ("  price: ");
        scanf (" %lf", & p->price);
        printf (" weight: ");
        scanf (" %lf", & p->weight);
        printf ("address: ");
        scanf (" %s", p->address);
}

void addProductToFile (FILE * fp, const Product p) {
    if (!fp) {
        perror (NULL);
        exit (-1);
    }

    if (fwrite (& p.id, sizeof (int), 1, fp) != 1) {
        perror (NULL);
    }
    if (fwrite (p.name, sizeof (char), NAME_LEN, fp) != NAME_LEN) {
        perror (NULL);
    }
    if (fwrite (p.brand, sizeof (char), BRAND_LEN, fp) != BRAND_LEN) {
        perror (NULL);
    }
    if (fwrite (& p.price, sizeof (double), 1, fp) != 1) {
        perror (NULL);
    }
    if (fwrite (& p.weight, sizeof (double), 1, fp) != 1) {
        perror (NULL);
    }
    if (fwrite (p.address, sizeof (char), ADDRESS_LEN, fp) != ADDRESS_LEN) {
        perror (NULL);
    }

    printf ("%s added in DB\n", p.name);

}

void printProduct (const Product p) {
    printf ("     id: %d\n", p.id);
    printf ("   name: %s\n", p.name);
    printf ("  brand: %s\n", p.brand);
    printf ("  price: %g\n", p.price);
    printf (" weight: %g\n", p.weight);
    printf ("address: %s\n", p.address);
}

void findByBrand (const Product p, char brand []) {
    if (!strcmp (p.brand, brand)) {
        printProduct (p);        
    }
}

void getProductFromFile (FILE * fp, Product * p) {
    if (!fp) {
        perror (NULL);
        exit (-1);
    }
    fread (& p->id, sizeof (int), 1, fp);
    fread (p->name, sizeof (char), NAME_LEN, fp);
    fread (p->brand, sizeof (char), BRAND_LEN, fp);    
    fread (& p->price, sizeof (double), 1, fp);
    fread (& p->weight, sizeof (double), 1, fp);
    fread (p->address, sizeof (char), ADDRESS_LEN, fp);
}

int main () {
    FILE * fp = fopen ("db.bin", "a+b");
    if (!fp) {
        perror (NULL);
        exit (-1);
    }

    Product p;

//    getNewProduct (& p);
//    getProductFromFile (fp, & p);
//    printProduct (p);

    if (fclose (fp)) {
        perror (NULL);
    }
    return 0;
}
