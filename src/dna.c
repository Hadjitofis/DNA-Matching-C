#include <stdio.h>// Δηλώνω τις βιβλιοθήκες που θα χρησιμοποιήσω
#include <stdlib.h>
#include<string.h>
void getMAXSEQ(char** str1, char** str2, int len1, int len2) {
    int maxLen = 0;
    int endIndex = 0;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int length = 0;
            while (i + length < len1 && j + length < len2 && (*str1)[i + length] == (*str2)[j + length]) {
                length++;
            }
            if (length > maxLen) {
                maxLen = length;
                endIndex = i + length; //Το τέλος της μεγαλύτερης συμβολοσειράς
            }
        }
    }

    // Τυπώνω την μεγαλύτερη συμβολοσειρά
    for (int i = endIndex - maxLen; i < endIndex; i++) {
        printf("%c", (*str1)[i]);
    }
    printf("\n");
}


int getDNA(char **dna, FILE* fo) //function για να φτιάχνω τον πίνακα με τους Χαρακτήρες του DNA
{
    int len = 0;
    char c;
    c = fgetc(fo); //Παίρνω τον πρώτο χαράκτήρα του αρχείου
    while (c != EOF) //όσο δεν έχει τελειώσει το αρχείο
    {
        // Δεσμεύω μνήμη για το string
        *dna = (char*)realloc(*dna, (len + 1) * sizeof(char));
        if (*dna == NULL) {
            return -1;
        }if (c == 'A' || c == 'G' || c == 'T' || c=='C')//Αν ο χαρακτήρας που έπιασα είναι σωστός τον προσθέτω στο dna
        {
            (*dna)[len] = c;
            len++;
        }
        
        c = fgetc(fo);
    }
    if (len > 0) {
        *dna = realloc(*dna, (len + 1) * sizeof(char)); //Βάζουμε το κενό των strings
        if (*dna == NULL) {
            return -1;
        }

        (*dna)[len] = '\0';
    }
    return len;//Αφού ο πίνακας dna επιστρέφει πίσω με τις αλλαγές που του έχω κάνει το function μου επιστρέφει το length του.
}
int main(int argc, char* argv[]) {
    if (argc != 3) //Ελέγχω ότι χρησιμοποιήθηκαν σωστά τα arguments
    {
        printf("Error: arguments missing. Usage: ./dna dnafile1 dnafile2\n");
        return 1;
    }
    FILE* dna1 = fopen(argv[1], "r");
    if (dna1 == NULL)//Ελέγχω ότι ανοιξαν σωστά τα αρχεία 
    {
        printf( "Error: cannot open file %s\n", argv[1]);
        return 1;
    }

    FILE* dna2 = fopen(argv[2], "r");
    if (dna2 == NULL) {
        printf( "Error: cannot open file %s\n", argv[2]);
        fclose(dna1); //Αν δεν ανοιξε το δεύτερο αρχείο κλείνω το πρώττο το οποίο είναι ηδη ανοιχτό
        return 1;
    }
    
    char* str1 = NULL; // Pointer για να αποθηκεύσω το πρώτο DNA
    char* str2 = NULL; // Pointer για να αποθηκεύσω το δεύτερο DNA
    int len1 = 0;
    int len2 = 0;
    len1 = getDNA(&str1, dna1);
    len2 = getDNA(&str2, dna2);
    if (len1 == -1 || len2 == -1)  // Ελέγχω ότι δούλεψε η δέσμευση μνήμης
        { return 1; }
        if (strcmp(argv[1], argv[2]) == 0)//Αν συγκρίνω τα ίδια αρχεία δεν υπάρχει λογος να ψάχνω maxsequence απλα τυπώνω το αρχείο
        {
            for (int i = 0; i < len1; i++) {
                printf("%c", (str1)[i]);
            }

        }
        else //Αν το αρχεία είναι διαφορετικά τότε βρίσκω την maxseq και την τυπώνω
        {

            getMAXSEQ(&str1, &str2, len1, len2);
        }


        free(str1); //Ελευθερώνω την μνήμη
        free(str2);
        fclose(dna1);//Κλείνω τα αρχεία
        fclose(dna2);
        return 0;
    }

