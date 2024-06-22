
def RLE(s):

    """Fonction permet de prendre une chaîne de caractères en entrée et retourne cette chaîne de caractères encodée en RLE"""

    Message_A_Encoder = s

    # Si la chaine vide alors on retourne une chaine vide.
    if not Message_A_Encoder:
        return ""
    
    # Pour l'instant, le message qui est en train d'être encodé est vide.
    Message_En_Train_Detre_Encode = ""
    
    # Initialisation du compteur de caractères qui se répètent.
    Compteur_De_Caractere_Qui_Se_Repete = 1
    
    # position actuelle du programme dans la chaîne d'entrée est le premier caractère du message.
    Position_Actuelle_Dans_Le_Message = Message_A_Encoder[0] # 0 est l'index du premier caractère dans le message.
    
    # Boucle for qui se repète pour chaque caractère dans le message.
    for i in range(1, len(s)):

        # La position suivante du programme devient le ième caractère dans le message.
        Position_Suivante_Dans_Le_Message = Message_A_Encoder[i]

        # Si le caractère actuel est le même que le prochain caractère, par exemple, si on a [AA]HHHTTT
        if Position_Suivante_Dans_Le_Message == Position_Actuelle_Dans_Le_Message:

            # Incrémenter le compteur de caractères qui se répètent
            Compteur_De_Caractere_Qui_Se_Repete += 1


            # Si le compteur de caractères qui se répètent dépasse 9 alors on doit le diviser en plusieurs groupes de 9
            if Compteur_De_Caractere_Qui_Se_Repete > 9:
                Compteur_De_Caractere_Qui_Se_Repete -= 9

                # On ajotue le groupe de 9 caractères à la chaîne de résultat
                Message_En_Train_Detre_Encode+= "9" + Position_Actuelle_Dans_Le_Message
        
        # Si le caractère actuel est différent du prochain caractère par exemple, si on a AA[H]HHTTT
        else:

            # On ajoute le nombre obtenu avec compteur de caractères qui se répètent et le caractère actuel à la chaîne de résultat.
            Message_En_Train_Detre_Encode += str(Compteur_De_Caractere_Qui_Se_Repete) +Position_Actuelle_Dans_Le_Message

            # On remet le compteur de caractères qui se répètent à 1 car on a un nouveau caractère et donc on doit recommencer à compter
            Position_Actuelle_Dans_Le_Message = Position_Suivante_Dans_Le_Message
            Compteur_De_Caractere_Qui_Se_Repete = 1

    # On ajoute le dernier groupe de caractères à la chaîne de résultat.
    Message_En_Train_Detre_Encode += str(Compteur_De_Caractere_Qui_Se_Repete) + Position_Actuelle_Dans_Le_Message

    # C'est bon on a fini d'encoder le message, on retourne le message encodé.
    Message_Encode = Message_En_Train_Detre_Encode

    return Message_Encode


def RLE_recursif(s, iterations):
    
    """Fonction permet de prendre une chaîne de caractères en entrée et retourne cette chaîne de caractères encodée en RLE"""

    # Le nombre de répétitions
    Nombre_De_Repetition = iterations

    # Si le nombre de répétitions est inférieur à 1 alors exception
    if Nombre_De_Repetition < 1:
        raise Exception("Le nombre de repetition doit être au moins (>1)")
    
    # Le message qui sera encodé
    Message_En_Train_Detre_Encode = s

    # Boucle pour encoder le message n fois
    for i in range(Nombre_De_Repetition):
        Message_En_Train_Detre_Encode= RLE(Message_En_Train_Detre_Encode)
    
    # C'est bon on a fini d'encoder le message, on retourne le message encodé.
    Message_Encode = Message_En_Train_Detre_Encode
    return Message_Encode

def unRLE(s):

    """Fonction permet de prendre une chaîne de caractères encodée en RLE en entrée et retourne cette chaîne de caractères décodée"""

    # Si la chaine vide alors on retourne une chaine vide.
    if not s:
        return ""
    
    # Pour l'instant, le message qui est en train d'être décodé est vide.
    Message_En_Train_Detre_Decode = ""

    # Initialisation du compteur de caractères qui se répètent.
    Compteur_De_Caractere_Qui_Se_Repete = 0

    # Boucle for qui se repète pour chaque caractère dans le message.
    for i in range(0, len(s)):

        # Si le caractère est un chiffre alors on le convertit en un entier et le stocker dans Compteur_De_Caractere_Qui_Se_Repete
        if s[i].isdigit():
            Compteur_De_Caractere_Qui_Se_Repete = int(s[i]) # Cela va nous permettre de savoir combien de fois on doit répéter le caractère suivant donc si on a 5A alors AAAAA

        # Si le caractère n'est pas un chiffre alors on doit le répéter Compteur_De_Caractere_Qui_Se_Repete fois
        else:
            Message_En_Train_Detre_Decode += s[i] * Compteur_De_Caractere_Qui_Se_Repete

    # C'est bon on a fini de décoder le message, on retourne le message décodé.
    Message_Decode = Message_En_Train_Detre_Decode
    return Message_Decode

def unRLE_recursif(s, iterations):
    """Fonction qui ne fonctionne pas qui est censé permettre de prendre une chaîne de caractères encodée en RLE en entrée et retourne cette chaîne de caractères décodée"""

    # Le nombre de répétitions
    Nombre_De_Repetition = iterations

    # Si le nombre de répétitions est inférieur à 1 alors exception
    if Nombre_De_Repetition < 1:
        raise Exception("Le nombre de repetition doit être au moins (>1)")
    
    # Le message qui sera décodé
    Message_En_Train_Detre_Decode = s

    # Boucle pour décoder le message n fois
    for i in range(Nombre_De_Repetition):
        Message_En_Train_Detre_Decode = unRLE(Message_En_Train_Detre_Decode)
    
    # C'est bon on a fini de décoder le message, on retourne le message décodé.
    Message_Decode = Message_En_Train_Detre_Decode
    
    # C'est bon on a fini de décoder le message, on retourne le message décodé.
    return Message_Decode