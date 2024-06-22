#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Déclarez la fonction externe pour l'utiliser dans les tests
extern char* fctRLE(char chaine[]);

void test_fctRLE() {
    char *result;

    // Test 1 : Chaîne vide
    result = fctRLE("");
    assert(strcmp(result, "") == 0);

    // Test 2 : Chaîne sans répétition
    result = fctRLE("abcdef");
    assert(strcmp(result, "1a1b1c1d1e1f") == 0);
    free(result);

    // Test 3 : Chaîne avec répétitions courtes
    result = fctRLE("aaabbc");
    assert(strcmp(result, "3a2b1c") == 0);
    free(result);

    // Test 4 : Chaîne avec répétitions longues
    result = fctRLE("aaaaaaaaaaa");
    assert(strcmp(result, "9a2a") == 0);
    free(result);

    // Test 5 : Chaîne avec répétitions multiples et longues
    result = fctRLE("aaaaaaaaaaabbbbbbbbbbbb");
    assert(strcmp(result, "9a2a9b3b") == 0);
    free(result);

    // Test 6 : Chaîne avec caractères spéciaux
    result = fctRLE("aaabbb@@@");
    assert(strcmp(result, "3a3b3@") == 0);
    free(result);

    // Test 7 : Chaîne avec des caractères en majuscule et minuscule
    result = fctRLE("aAaAaA");
    assert(strcmp(result, "1a1A1a1A1a1A") == 0);
    free(result);

    printf("Tous les tests de fctRLE ont réussi.\n");
}

int main() {
    test_fctRLE();
    return 0;
}
