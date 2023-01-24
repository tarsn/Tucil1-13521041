#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "boolean.h"
#include <time.h>
#include <string.h>

typedef struct {
   float idx[4];
} List;

void welcome() {
    printf("\n");
    printf("\t___  ___      _          _ _     _____   ___ \n");
    printf("\t|  \\/  |     | |        (_) |   / __  \\ /   |\n");
    printf("\t| .  . | __ _| | _____   _| |_  `' / /'/ /| |\n");
    printf("\t| |\\/| |/ _` | |/ / _ \\ | | __|   / / / /_| |\n");
    printf("\t| |  | | (_| |   <  __/ | | |_  ./ /__\\___  |\n");
    printf("\t\\_|  |_/\\__,_|_|\\_\\___| |_|\\__| \\_____/   |_/\n");
    printf("\t                                             \n");
    printf("\t                                             \n");  
    printf("\t         _____       _                       \n");
    printf("\t        /  ___|     | |                      \n");
    printf("\t        \\ `--.  ___ | |_   _____ _ __        \n");
    printf("\t         `--. \\/ _ \\| \\ \\ / / _ \\ '__|       \n");
    printf("\t        /\\__/ / (_) | |\\ V /  __/ |          \n");
    printf("\t        \\____/ \\___/|_| \\_/ \\___|_|          \n");
    printf("\t                                             \n\n");
}

int cekinp(char x) {
    int cek = false;
    if (x == 'A' || x == 'a' || x == '1') {
        cek = true;
    } else if (x == '2') {
        cek = true;
    } else if (x == '3') {
        cek = true;
    } else if (x == '4') {
        cek = true;
    } else if (x == '5') {
        cek = true;
    } else if (x == '6') {
        cek = true;
    } else if (x == '7') {
        cek = true;
    } else if (x == '8') {
        cek = true;
    } else if (x == '9') {
        cek = true;
    } else if (x == '0') {
        cek = true;
    } else if (x == 'J' || x == 'j') {
        cek = true;
    } else if (x == 'Q' || x == 'q') {
        cek = true;
    } else if (x == 'K' || x == 'k') {
        cek = true;
    }  else if (x == ' ') {
        cek = true;
    }  else if (x == '\n') {
        cek = true;
    } return cek;
}

List inputuser() {
    List inp;
    boolean sinput = true;
    int ann = 0;
    while (sinput) {
        char tmp = ' ';
        int cek = true;
        int urutan = 0;
        int skip = 0;
        if (ann != 0) {
            printf("\nSilahkan masukkan 4 kartu!\n>>> ");   
        }
        while (tmp != '\n') {
            scanf("%c", &tmp);
            if (cekinp(tmp) == true) {
                if (skip == 1) {
                    skip = 0;
                } else {
                    if ('A' == toupper(tmp)) {
                        inp.idx[urutan] = 1;
                        urutan += 1;
                    } else if ('1' == tmp) {
                        inp.idx[urutan] = 10;
                        urutan += 1;
                        skip = 1;
                    } else if (toupper(tmp) == 'J') {
                        inp.idx[urutan] = 11;
                        urutan += 1;
                    } else if (toupper(tmp) == 'Q') {
                        inp.idx[urutan] = 12;
                        urutan += 1;
                    } else if (toupper(tmp) == 'K') {
                        inp.idx[urutan] = 13;
                        urutan += 1;
                    } else if ('2' == tmp || '3' == tmp || '4' == tmp || '5' == tmp || '6' == tmp || '7' == tmp || '8' == tmp || '9' == tmp){
                        int tmpp = tmp - '0';
                        inp.idx[urutan] = (float) (tmpp);
                        urutan += 1;
                    }
                }
            } else {
                cek = false;
            }
        }
        if (cek) {
            if (urutan == 4) {
                sinput = false;
            } else {
                if (ann != 0) {
                    printf("Inputan tidak sesuai, silahkan input ulang!!\n");
                }
                ann += 1;
            } 
        } else {
            printf("Inputan tidak sesuai, silahkan input ulang!!\n");
        }
    }
    return inp;
}

List randomin() {
    srand(time(0));
    int nilai[4];
    for (int i=0; i<4; i++) {
        nilai[i] = (rand() % 13) + 1;
    }

    List ran;
    printf("\nKartu yang didapatkan adalah ");
    for (int i=0; i<4; i++) {
        if (nilai[i] == 1) {
            printf("A ");
        } else if (nilai[i] == 11) {
            printf("J ");
        } else if (nilai[i] == 12) {
            printf("Q ");
        } else if (nilai[i] == 13) {
            printf("K ");
        } else {
            printf("%d ", nilai[i]);
        }
        ran.idx[i] = nilai[i];
    }
    printf("\n"); 
    return ran;
}

void convtxt(List input) {
    char filename[20] = "../test/";
    char nama[20];
    printf("\nMasukkan nama file txt : ");
    scanf("%s", nama);
    strcat(filename, nama);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
    }
    
    float arr[4];
    for (int i=0; i<4; i++) {
        arr[i] = input.idx[i];
    }

    fprintf(fp, "Kartu yang dimiliki %.0f %.0f %.0f %.0f\n", arr[0],arr[1],arr[2],arr[3]);
    int nos = 0; // Number of Solution
    int i, j, k, l;
    int jml = 0;
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            for (k=0; k<4; k++) {        
                for (l=0; l<4; l++) {
                    if (i != j && i != k && j != k && i != l && j != l && k != l) {

                        int op1,op2,op3;
                        for (op1 = 1; op1<5; op1++) {
                            for (op2 = 1; op2<5; op2++){
                                for (op3 = 1; op3<5; op3++){

                                    float tmp1, tmp2, hasil;
                                    char c1,c2,c3;

                                    // (A op1 B) op2 (C op3 D)
                                    switch (op1) {
                                        case 1 : tmp1 = arr[i] + arr[j]; c1 = '+'; break;
                                        case 2 : tmp1 = arr[i] - arr[j]; c1 = '-'; break;
                                        case 3 : tmp1 = arr[i] * arr[j]; c1 = '*'; break;
                                        case 4 : tmp1 = arr[i] / arr[j]; c1 = '/'; break;
                                        default : break;
                                    }
                                    switch (op3) {
                                        case 1 : tmp2 = arr[k] + arr[l]; c3 = '+'; break;
                                        case 2 : tmp2 = arr[k] - arr[l]; c3 = '-'; break;
                                        case 3 : tmp2 = arr[k] * arr[l]; c3 = '*'; break;
                                        case 4 : tmp2 = arr[k] / arr[l]; c3 = '/'; break;
                                        default : break;
                                    } 
                                    switch (op2) {
                                        case 1 : hasil = tmp1 + tmp2 ; c2 = '+'; break;
                                        case 2 : hasil = tmp1 - tmp2 ; c2 = '-'; break;
                                        case 3 : hasil = tmp1 * tmp2 ; c2 = '*'; break;
                                        case 4 : hasil = tmp1 / tmp2 ; c2 = '/'; break;
                                        default : break;
                                    }
                                    if (hasil == 24) {
                                        fprintf(fp, "(%.0f %c %.0f) %c (%.0f %c %.0f)\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
                                        nos += 1;
                                    }

                                    // ((A op1 B) op2 C) op3 D
                                    switch (op1) {
                                        case 1 : tmp1 = arr[i] + arr[j]; c1 = '+'; break;
                                        case 2 : tmp1 = arr[i] - arr[j]; c1 = '-'; break;
                                        case 3 : tmp1 = arr[i] * arr[j]; c1 = '*'; break;
                                        case 4 : tmp1 = arr[i] / arr[j]; c1 = '/'; break;
                                        default : break;
                                    }
                                    switch (op2) {
                                        case 1 : tmp2 = tmp1 + arr[k]; c2 = '+'; break;
                                        case 2 : tmp2 = tmp1 - arr[k]; c2 = '-'; break;
                                        case 3 : tmp2 = tmp1 * arr[k]; c2 = '*'; break;
                                        case 4 : tmp2 = tmp1 / arr[k]; c2 = '/'; break;
                                        default : break;
                                    }
                                    switch (op3) {
                                        case 1 : hasil = tmp2 + arr[l]; c3 = '+'; break;
                                        case 2 : hasil = tmp2 - arr[l]; c3 = '-'; break;
                                        case 3 : hasil = tmp2 * arr[l]; c3 = '*'; break;
                                        case 4 : hasil = tmp2 / arr[l]; c3 = '/'; break;
                                        default : break;
                                    }
                                    if (hasil == 24) {
                                        fprintf(fp, "((%.0f %c %.0f) %c %.0f) %c %.0f\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
                                        nos += 1;
                                    }

                                    // (A op1 (B op2 C)) op3 D
                                    switch (op2) {
                                        case 1 : tmp1 = arr[j] + arr[k]; c2 = '+'; break;
                                        case 2 : tmp1 = arr[j] - arr[k]; c2 = '-'; break;
                                        case 3 : tmp1 = arr[j] * arr[k]; c2 = '*'; break;
                                        case 4 : tmp1 = arr[j] / arr[k]; c2 = '/'; break;
                                        default : break;
                                    }
                                    switch (op1) {
                                        case 1 : tmp2 = arr[i] + tmp1; c1 = '+'; break;
                                        case 2 : tmp2 = arr[i] - tmp1; c1 = '-'; break;
                                        case 3 : tmp2 = arr[i] * tmp1; c1 = '*'; break;
                                        case 4 : tmp2 = arr[i] / tmp1; c1 = '/'; break;
                                        default : break;
                                    }
                                    switch (op3) {
                                        case 1 : hasil = tmp2 + arr[l]; c3 = '+'; break;
                                        case 2 : hasil = tmp2 - arr[l]; c3 = '-'; break;
                                        case 3 : hasil = tmp2 * arr[l]; c3 = '*'; break;
                                        case 4 : hasil = tmp2 / arr[l]; c3 = '/'; break;
                                        default : break;
                                    }
                                    if (hasil == 24) {
                                        fprintf(fp, "(%.0f %c (%.0f %c %.0f)) %c %.0f\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
                                        nos += 1;
                                    }

                                    // A op1 ((B op2 C) op3 D)
                                    switch (op2) {
                                        case 1 : tmp1 = arr[j] + arr[k]; c2 = '+'; break;
                                        case 2 : tmp1 = arr[j] - arr[k]; c2 = '-'; break;
                                        case 3 : tmp1 = arr[j] * arr[k]; c2 = '*'; break;
                                        case 4 : tmp1 = arr[j] / arr[k]; c2 = '/'; break;
                                        default : break;
                                    }
                                    switch (op3) {
                                        case 1 : tmp2 = tmp1 + arr[l]; c3 = '+'; break;
                                        case 2 : tmp2 = tmp1 - arr[l]; c3 = '-'; break;
                                        case 3 : tmp2 = tmp1 * arr[l]; c3 = '*'; break;
                                        case 4 : tmp2 = tmp1 / arr[l]; c3 = '/'; break;
                                        default : break;
                                    }
                                    switch (op1) {
                                        case 1 : hasil = arr[i] + tmp2; c1 = '+'; break;
                                        case 2 : hasil = arr[i] - tmp2; c1 = '-'; break;
                                        case 3 : hasil = arr[i] * tmp2; c1 = '*'; break;
                                        case 4 : hasil = arr[i] / tmp2; c1 = '/'; break;
                                        default : break;
                                    }
                                    if (hasil == 24) {
                                        fprintf(fp, "%.0f %c ((%.0f %c %.0f) %c %.0f)\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
                                        nos += 1;
                                    }

                                    // A op1 (B op2 (C op3 D))
                                    switch (op3) {
                                        case 1 : tmp1 = arr[k] + arr[l]; c3 = '+'; break;
                                        case 2 : tmp1 = arr[k] - arr[l]; c3 = '-'; break;
                                        case 3 : tmp1 = arr[k] * arr[l]; c3 = '*'; break;
                                        case 4 : tmp1 = arr[k] / arr[l]; c3 = '/'; break;
                                        default : break;
                                    }
                                    switch (op2) {
                                        case 1 : tmp2 = arr[j] + tmp1; c2 = '+'; break;
                                        case 2 : tmp2 = arr[j] - tmp1; c2 = '-'; break;
                                        case 3 : tmp2 = arr[j] * tmp1; c2 = '*'; break;
                                        case 4 : tmp2 = arr[j] / tmp1; c2 = '/'; break;
                                        default : break;
                                    }
                                    switch (op1) {
                                        case 1 : hasil = arr[i] + tmp2; c1 = '+'; break;
                                        case 2 : hasil = arr[i] - tmp2; c1 = '-'; break;
                                        case 3 : hasil = arr[i] * tmp2; c1 = '*'; break;
                                        case 4 : hasil = arr[i] / tmp2; c1 = '/'; break;
                                        default : break;
                                    }
                                    if (hasil == 24) {
                                        fprintf(fp, "%.0f %c (%.0f %c (%.0f %c %.0f))\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
                                        nos += 1;
                                    }
                                }
                            }
                        }
                    }    
                }        
            }
        }
    }
    fprintf(fp, "\nTotal kemungkinannya adalah sebanyak %i", nos);
    fclose(fp);
}