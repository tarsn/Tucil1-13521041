#include <stdio.h>
#include "functemp.c"

int main() {
    welcome();
    boolean game = true;
    while (game) {
        boolean cekpil = true;
        List inp;
        while (cekpil) {
            printf("Pilih metode memilih kartu: \n1. Input Manual\n2. Random\n>>> ");
            int pil;
            scanf("%d", &pil);
            if (pil == 1) {
                inp = inputuser();
                cekpil = false;
            } else if (pil == 2) {
                inp = randomin();
                cekpil = false;
            } else {
                printf("Inputan salah!\n");
            }
        }

        clock_t start, end;
        start = clock();
        printf("\nKemungkinan solusi dari kartu adalah: \n");
        float arr[4];
        for (int i=0; i<4; i++) {
            arr[i] = inp.idx[i];
        }

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
                                            printf("(%.0f %c %.0f) %c (%.0f %c %.0f)\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
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
                                            printf("((%.0f %c %.0f) %c %.0f) %c %.0f\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
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
                                            printf("(%.0f %c (%.0f %c %.0f)) %c %.0f\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
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
                                            printf("%.0f %c ((%.0f %c %.0f) %c %.0f)\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
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
                                            printf("%.0f %c (%.0f %c (%.0f %c %.0f))\n", arr[i], c1, arr[j], c2, arr[k], c3, arr[l]);
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
        printf("\nTotal kemungkinannya adalah sebanyak %i\n", nos);
        end = clock();
        double timespent= (double)(end-start) / CLOCKS_PER_SEC;
        printf("Waktu Eksekusinya sebesar %f detik\n\n", timespent);

        boolean cekbf = true;
        while (cekbf) {
            printf("Apakah menyimpan outputannya?\n1. Ya\n2. Tidak\n>>> ");
            int tmppil;
            scanf("%d", &tmppil);
            if (tmppil == 1) {
                convtxt(inp);
                cekbf = false;
            } else if (tmppil == 2) {
                cekbf = false;
            } else {
                printf("Inputan tidak sesuai, silahkan ulangi lagi!\n");
            }
        }

        boolean ceklas = true;
        while (ceklas) {
            printf("\nApakah ingin mencoba lagi?\n1. Ya\n2. Tidak\n>>> ");
            int tmppil;
            scanf("%d", &tmppil);
            if (tmppil == 1) {
                ceklas = false;
            } else if (tmppil == 2) {
                ceklas = false;
                game = false;
                printf("Termkasih. Semoga bertemu dilain waktu :D\n");
            } else {
                printf("Inputan tidak sesuai, silahkan ulangi lagi!\n");
            }
        } printf("\n");
    }
}