#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Déclarez les fonctions externes pour les utiliser dans les tests
extern char* RLE(const char *in);
extern char* unRLE(const char *in);
extern char* RLE_it(char *in, int iteration);
extern char* unRLE_it(char *in, int iteration);

void test_RLE() {
    char *result;

    // Test 1 : Chaîne vide
    result = RLE("");
    assert(result == NULL);
    free(result);

    // Test 2 : Chaîne sans répétition
    result = RLE("abcdef");
    assert(strcmp(result, "1a1b1c1d1e1f") == 0);
    free(result);

    // Test 3 : Chaîne avec répétitions courtes
    result = RLE("aaabbc");
    assert(strcmp(result, "3a2b1c") == 0);
    free(result);

    // Test 4 : Chaîne avec répétitions longues
    result = RLE("aaaaaaaaaaa");
    assert(strcmp(result, "9a2a") == 0);
    free(result);

    // Test 5 : Chaîne avec répétitions multiples et longues
    result = RLE("aaaaaaaaaaabbbbbbbbbbbb");
    assert(strcmp(result, "9a2a9b3b") == 0);
    free(result);

    // Test 6 : Chaîne avec caractères spéciaux
    result = RLE("aaabbb@@@");
    assert(strcmp(result, "3a3b3@") == 0);
    free(result);

    // Test 7 : Chaîne avec des caractères en majuscule et minuscule
    result = RLE("aAaAaA");
    assert(strcmp(result, "1a1A1a1A1a1A") == 0);
    free(result);

    printf("Tous les tests de RLE ont réussi.\n");
}

void test_unRLE() {
    char *result;

    // Test 1 : Chaîne vide
    result = unRLE("");
    assert(result == NULL);
    free(result);

    // Test 2 : Chaîne sans répétition
    result = unRLE("1a1b1c1d1e1f");
    assert(strcmp(result, "abcdef") == 0);
    free(result);

    // Test 3 : Chaîne avec répétitions courtes
    result = unRLE("3a2b1c");
    assert(strcmp(result, "aaabbc") == 0);
    free(result);

    // Test 4 : Chaîne avec répétitions longues
    result = unRLE("9a2a");
    assert(strcmp(result, "aaaaaaaaaaa") == 0);
    free(result);

    // Test 5 : Chaîne avec répétitions multiples et longues
    result = unRLE("9a2a9b3b");
    assert(strcmp(result, "aaaaaaaaaaabbbbbbbbbbbb") == 0);
    free(result);

    // Test 6 : Chaîne avec caractères spéciaux
    result = unRLE("3a3b3@");
    assert(strcmp(result, "aaabbb@@@") == 0);
    free(result);

    // Test 7 : Chaîne avec des caractères en majuscule et minuscule
    result = unRLE("1a1A1a1A1a1A");
    assert(strcmp(result, "aAaAaA") == 0);
    free(result);

    printf("Tous les tests de unRLE ont réussi.\n");
}

void test_RLE_it() {
    char *result;

    // Test 1 : Chaîne avec une itération
    result = RLE_it("aaabbc", 1);
    assert(strcmp(result, "3a2b1c") == 0);
    free(result);

    // Test 2 : Chaîne avec deux itérations
    result = RLE_it("abc", 2);
    assert(strcmp(result, "111a111b111c") == 0);
    free(result);

    printf("Tous les tests de RLE_it ont réussi.\n");
}

void test_unRLE_it() {
    char *result;

    // Test 1 : Chaîne avec une itération
    result = unRLE_it("3a2b1c", 1);
    assert(strcmp(result, "aaabbc") == 0);
    free(result);

    // Test 2 : Chaîne avec deux itérations
    result = unRLE_it("111a111b111c", 2);
    assert(strcmp(result, "abc") == 0);
    free(result);

    printf("Tous les tests de unRLE_it ont réussi.\n");
}

int main() {
    test_RLE();
    test_unRLE();
    test_RLE_it();
    test_unRLE_it();
    return 0;
}
