package iut.sae.algo;

public class Simplicite54 {

    public static String RLE(String in) {

        // Transformer le chaîne en tableau de caractères
        char[] message = in.toCharArray();
        // Initialisation de la chaîne compressée
        String compression = "";
        // Parcours des caractères du tableau (de la chaîne)
        int i = 0;
        // Tant que l'on n'arrive pas au bout du message
        while (i < in.length()) {
            // On note une occurence
            int nb_occurences = 1;
            // Tant que les 2 voisins sont identiques, qu'on est en dessous de 10 occurences et qu'on n'a pas atteint la fin du message
            while (i + 1 < in.length() && message[i] == message[i + 1] && nb_occurences < 9) {
                i++;
                nb_occurences++;
            }
            // On ajoute la chaîne obtenue à la chaîne de résultat
            compression += "" + nb_occurences + message[i];
            // On passe au caractère suivant
            i++;
        }
        // On retourne la chaîne compressée
        return compression;
    }

    public static String RLEIteration(String in, int iteration) {
        String compression = in;
        for (int i = 0; i < iteration; i++) {
            compression = RLE(compression);
        }
        return compression;
    }
}
