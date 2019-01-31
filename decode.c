#include <stdio.h>
#include <stdlib.h>



int main( int argc, char *argv[] ){
    if(argc < 3){
      printf("Usage:\n./a.out <ciphertext> <k1 inverse> <k2>\n");
      return 1;
    }
    //subtract 97 from every character to get int
    int k_inv = atoi(argv[2]);
    int k_two = atoi(argv[3]);
    printf("ciphertext: %s\n", argv[1]);
    int i = 0;
    while(argv[1][i]){
      argv[1][i] -= 97;

      argv[1][i] = argv[1][i] - (k_two);

      if(argv[1][i] < 0)
        argv[1][i] += 26;

      int t = argv[1][i] * k_inv;

      argv[1][i] = t % 26;
      if(argv[1][i] < 0)
        argv[1][i] *= -1;
      argv[1][i] += 97;
      i++;
    }

    printf("plaintext : %s\n", argv[1]);

    return 0;
}
