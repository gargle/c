#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*

  TAXMAN - first published in People's Computer Company
           vol. 2, no. 1 - September 1973

  https://scruss.com/blog/2019/11/03/taxman-a-basic-game-from-1973/

*/



int how_many_to_take() {
  int characters_read;
  int take=0;
  do {
    puts("");
    puts("");
    printf("You take: ");
    characters_read=scanf("%i", &take);
    while(getchar()!='\n');
  } while(characters_read<1);
  return take;
}

void initialise_list(int *array, int n) {
  for(int i=1;i<=n;i++) {
    *array++=i;
  }
}

int sum_list(int *array, int n) {
  int sum=0;
  for(int i=1;i<n;i++) {
    sum+=array[i-1];
  }
  return sum;
}

void print_list(int *array, int n) {
  int nonzero=-1;
  for(int i=1;i<=n;i++) {
    if (array[i-1]!=0) {
      nonzero=i-1;
      break;
    }
  }
  if (nonzero>-1) {
    printf("%d", array[nonzero]);
    if (nonzero+1<n) {
      for(int i=nonzero+2;i<=n;i++) {
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
  for(int i=1;i<k;i++) {
    if (array[i-1]==0)
      continue;
    if (k%array[i-1]==0)
      c++;
  }
  return c;
}

int check_if_any_numbers_stil_have_factors(int *array, int n) {
  int f=0;
  for(int i=1;i<=n;i++) {
    if (array[i-1]==0)
      continue;
    f+=check_list_for_factor_of_n(array, array[i-1]);
  }
  return f;
}

int initialise_list_of_factors(int *factors, int *array, int k) {
  int sum=0;
  for(int i=1;i<=k;i++) {
    if (array[i-1]==0)
      continue;
    if (k%array[i-1]==0) {
      *factors++=array[i-1];
      sum=sum+array[i-1];
      array[i-1]=0;
    }
  }
  return sum;
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
  int taken,f;
  int mytotal,taxmantotal;
  int newlist=0;
  int n=0;
  int *array=NULL;
  int *facto=NULL;

  /* parse the command line options */
  char ch;
  while ((ch=getopt(argc, argv, "hn:")) != EOF)
    switch(ch) {
    case 'h':
      instructions();
      return 0;
    case 'n':
      n=atoi(optarg);
      if (n>50) {
        puts("At this time, regulations allow a maximum of 50 numbers.");
        return 1;
      }
      break;
    default: /* if we get here it means that we have encountered an error */
      return 1;
    }
  if (n<1) {
    puts("Please use the -n parameter to tell me about the number of entries in the list.");
    return 1;
  }
  
  puts("");
  puts("");
  puts("Hi, I'm the taxman");

  mytotal=0;
  taxmantotal=0;
    
  array = (int *) malloc(sizeof(int)*(n+1)); /* array of n integers */
  initialise_list(array,n);

  printf("The list is: "); 
  print_list(array,n);
  for (;;) {
    taken=how_many_to_take();
    if (taken<1)
      break;
    if (taken<=n && array[taken-1]==taken) {
      if ((f=check_list_for_factor_of_n(array,taken))>0) {
        mytotal+=taken;
        array[taken-1]=0;
        facto = (int *) malloc(sizeof(int)*f); /* array of f integers */
        taxmantotal+=initialise_list_of_factors(facto, array, taken);
        printf("I get: "); 
        print_list(facto,f);
        free(facto);
        puts("");
        printf("Your total is %d\n", mytotal);
        printf("My total is %d\n", taxmantotal);
        puts("");
        printf("New list: "); 
        print_list(array,n);
      }
      else {
        puts("");
        printf("There are no factors of %d for the me.\n", taken);
        puts("Are you trying to short-change the taxman?");
      }          
    }
    else {
      printf("%d is not in the list -- try again.\n", taken);
    }
    if (check_if_any_numbers_stil_have_factors(array,n)==0) {
      taxmantotal+=sum_list(array,n);
      puts("");
      puts("I get the remains because no factors of any number are left.");
      puts("");
      printf("Your total is %d\n", mytotal);
      printf("My total is %d\n", taxmantotal);
      break;
    }
  }
  free(array);

  /* show who won */
  puts("");
  if (mytotal>taxmantotal)
    printf("Your total is %d.  The taxman's total is %d.   You win!!!", mytotal, taxmantotal);
  else
    printf("The taxmax's total is %d.  Your total is %d.  The taxman wins.", taxmantotal, mytotal);
}
