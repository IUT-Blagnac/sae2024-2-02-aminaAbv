#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Déclarez les fonctions externes pour les utiliser dans les tests
extern char* RLE(const char* in);
extern char* RLE_iterations(const char* in, int iteration);
extern char* unRLE(const char* in);
extern char* unRLE_iterations(const char* in, int iteration);

int main() {
    // Test RLE
    char* resultat = RLE("aaabbc");
    assert(strcmp(resultat, "3a2b1c") == 0);
    free(resultat);

    resultat = RLE("WWWWWWWWWWWWW");
    assert(strcmp(resultat, "9W4W") == 0);
    free(resultat);

    // Test RLE_iterations
    resultat = RLE_iterations("aaabbc", 1);
    assert(strcmp(resultat, "3a2b1c") == 0);
    free(resultat);

    resultat = RLE_iterations("abc", 2);
    assert(strcmp(resultat, "111a111b111c") == 0);
    free(resultat);

    // Test unRLE
    char* decompresse = unRLE("3a2b1c");
    assert(strcmp(decompresse, "aaabbc") == 0);
    free(decompresse);

    decompresse = unRLE("9W4W");
    assert(strcmp(decompresse, "WWWWWWWWWWWWW") == 0);
    free(decompresse);

    // Test unRLE_iterations
    decompresse = unRLE_iterations("3a2b1c", 1);
    assert(strcmp(decompresse, "aaabbc") == 0);
    free(decompresse);

    decompresse = unRLE_iterations("111a111b111c", 2);
    assert(strcmp(decompresse, "abc") == 0);
    free(decompresse);

    printf("Tous les tests ont réussi.\n");

    return 0;
}
