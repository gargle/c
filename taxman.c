#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*

  TAXMAN - first published in People's Computer Company
           vol. 2, no. 1 - September 1973

  https://scruss.com/blog/2019/11/03/taxman-a-basic-game-from-1973/

  compile with: gcc taxman.c -o taxman -O3 -Wall -std=gnu11

  (Klemens, Ben. 21st Century C / Ben Klemens. First edition. Beijing ;: O’Reilly Media, 2013. Print.)

*/



int how_many_to_take() {
  int characters_read;
  int take=0;
  do {
    puts("");
    puts("");
    printf("You take: ");
    characters_read=scanf("%d", &take);
    while (getchar()!='\n');
  } while (characters_read<1);
  return take;
}

void initialise_list(int *array, int n) {
  for (int i=1;i<=n;i++) {
    *array++=i;
  }
}

void initialise_list_of_factors(int *factors, int *numbers, int k) {
  for (int i=1;i<=k;i++) {
    if (numbers[i-1]==0)
      continue;
    if (k%i==0) {
      *factors++=i;
    }
  }
}

void clear_list_of_factors(int *factors, int *numbers, int k) {
  for (int i=1;i<=k;i++) {
    if (numbers[i-1]==0)
      continue;
    if (k%i==0) {
      numbers[i-1]=0;
    }
  }
}

int sum_list(int *array, int n) {
  int sum=0;
  for (int i=1;i<=n;i++) {
    sum+=array[i-1];
  }
  return sum;
}

void print_list(int *array, int n) {
  int nonzero=-1;
  for (int i=1;i<=n;i++) {
    if (array[i-1]!=0) {
      nonzero=i-1;
      break;
    }
  }
  if (nonzero>-1) {
    printf("%d", array[nonzero]);
    if (nonzero+1<n) {
      for (int i=nonzero+2;i<=n;i++) {
        if (array[i-1]==0)
          continue;
        printf(", %d", array[i-1]);
      }
    }
  }
  puts("");
}

int check_list_for_factor_of_n(int *array, int k) {
  int c=0;
  for (int i=1;i<k;i++) {
    if (array[i-1]==0)
      continue;
    if (k%array[i-1]==0)
      c++;
  }
  return c;
}

int check_if_any_numbers_stil_have_factors(int *array, int n) {
  int f=0;
  for (int i=1;i<=n;i++) {
    if (array[i-1]==0)
      continue;
    f+=check_list_for_factor_of_n(array, array[i-1]);
  }
  return f;
}

void instructions() {
  puts("");
  puts("You try to beat the taxman.");
  puts("");
  puts("We start with a list of whole numbers in numerical");
  puts("order (you decide how many).");
  puts("");
  puts("You take a number from the list -- the taxman gets");
  puts("all the factors of your number that are still left.");
  puts("Your number and all of its factors are then deleted");
  puts("from the list.");
  puts("");
  puts("For example, suppose you want ten numbers to be in the list.");
  puts("Then the list would be: 1  2  3  4  5  6  7  8  9  10");
  puts("");
  puts("If you took 8, the taxman would get: 1, 2, and 4");
  puts("and the new list would be: 3  5  6  7  9  10");
  puts("");
  puts("The taxman must get something every time so you can");
  puts("only pick a number that has factors left.");
  puts("");
  puts("When none of the remaining numbers has any factors,");
  puts("the taxman gets them!!");
  puts("");
  puts("Your score is the sum of numbers you take.");
  puts("If you want to give up, take 0.");
  puts("");
  puts("Good luck !!!");
}



int main(int argc, char *argv[]) {
  int number_taken,number_of_factors;
  int my_total,taxman_total;
  int maximum_number=0;
  int *numbers=NULL;
  int *factors=NULL;

  /* parse the command line options */
  char ch;
  while ((ch=getopt(argc, argv, "hn:")) != EOF)
    switch (ch) {
    case 'h':
      instructions();
      return 0;
    case 'n':
      maximum_number=atoi(optarg);
      if (maximum_number>50) {
        puts("At this time, regulations allow a maximum of 50 numbers.");
        return 1;
      }
      break;
    default: /* if we get here it means that we have encountered an error */
      return 1;
    }
  if (maximum_number<1) {
    puts("Please use the -n parameter to tell me about the number of entries in the list.");
    return 1;
  }

  puts("");
  puts("");
  puts("Hi, I'm the taxman");

  my_total=0;
  taxman_total=0;

  numbers=(int *)malloc(sizeof(int)*maximum_number);
  initialise_list(numbers,maximum_number);

  printf("The list is: "); 
  print_list(numbers,maximum_number);
  for (;;) {
    number_taken=how_many_to_take();
    if (number_taken<1)
      break;
    if (number_taken<=maximum_number && numbers[number_taken-1]==number_taken) {
      if ((number_of_factors=check_list_for_factor_of_n(numbers,number_taken))>0) {
        my_total+=number_taken;
        factors=(int *)malloc(sizeof(int)*(number_of_factors+1)); /* +1 because number_taken is a factor too */
        initialise_list_of_factors(factors, numbers, number_taken);
        taxman_total+=sum_list(factors,number_of_factors);
        printf("I get: "); 
        print_list(factors,number_of_factors);
        clear_list_of_factors(factors, numbers, number_taken);
        free(factors);
        puts("");
        printf("Your total is %d\n", my_total);
        printf("My total is %d\n", taxman_total);
        puts("");
        printf("New list: "); 
        print_list(numbers,maximum_number);
      }
      else {
        puts("");
        printf("There are no factors of %d for the me.\n", number_taken);
        puts("Are you trying to short-change the taxman?");
      }          
    }
    else {
      printf("%d is not in the list -- try again.\n", number_taken);
    }
    if (check_if_any_numbers_stil_have_factors(numbers,maximum_number)==0) {
      taxman_total+=sum_list(numbers,maximum_number);
      puts("");
      puts("I get the remains because no factors of any number are left.");
      puts("");
      printf("Your total is %d\n", my_total);
      printf("My total is %d\n", taxman_total);
      break;
    }
  }
  free(numbers);

  /* show who won */
  puts("");
  if (my_total>taxman_total)
    printf("Your total is %d.  The taxman's total is %d.   You win!!!\n", my_total, taxman_total);
  else
    printf("The taxmax's total is %d.  Your total is %d.  The taxman wins.\n", taxman_total, my_total);
}
