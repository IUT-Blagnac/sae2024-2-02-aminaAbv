##################################################
#             Simplicité / Python                #
##################################################

def encodage_rle_simplicite(texte):
    
    resultat = ""

    compteur = 1

    taille_texte = len(texte)

    for i in range(taille_texte):

        if  i == taille_texte - 1 or texte[i] != texte[i + 1]:
            
            while compteur > 9:

                resultat += "9" + texte[i]

                compteur -= 9
                
            resultat += str(compteur) + texte[i]

            compteur = 1
        else:
            compteur += 1

    return resultat

##################################################
#             Simplicité / Python                #
##################################################