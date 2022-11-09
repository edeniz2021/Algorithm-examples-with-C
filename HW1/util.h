#ifndef _UTIL_H_
#define _UTIL_H_

int find_divisible(int x, int y, int z);

int find_nth_divisible(int n, int f_I, int z);

int validate_identity_number(char kimlik_numarasi [ ]);

int create_customer(char kimlik_numarasi[ ], int sifre);

int check_login(char kimlik_numarasi [ ], int sifre);

int drawable_amount (float cash_amount);

#endif /* _UTIL_H_ */
