/* Spell check used for finding Linux Kernel spelling mistakes
 * Author: crazyoreo0
 *
 * Created on May 12, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
 * Usage: SpellChecker <fileName>
 */
int main(int argc, char** argv) {
    
    //if user has given us other than one param, it is an error:
    if(argc != 2) {
        printf("Error occurred!");
        usage();
        return(EXIT_FAILURE);
    }
    
    FILE *f;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    // locations where certain letters begin in the dictionary file
    int otherPos = 0;
    long aPos, bPos, cPos, dPos, ePos, fPos, gPos, hPos, iPos, jPos, kPos, lPos, mPos, nPos, oPos, pPos, qPos, rPos, sPos, tPos, uPos,
            vPos, wPos, xPos, yPos, zPos;
    
    int lineCounter = 0;
    
    f = fopen("/home/crazyoreo0/NetbeansProjects/SpellChecker/SpellChecker/words.txt","r");
    if(f==NULL) {
        printf("Error occurred! Dictionary file does not exist, please contact uroshm@gmail.com.");
        return (EXIT_FAILURE);
    }
        
    //we manually checked the file and know there are 466550 lines (with 0 indexed, subtract one):
    char *dictionary[466550];
    
    //read through the dictionary file and set locations for easier searching later:
    while ((read = getline(&line, &len, f)) != -1) {
        //initial operation for each line:
        dictionary[lineCounter] = malloc(50);
        strcpy(dictionary[lineCounter],line);
        lineCounter++;
        
        //go ahead and set up locations:
        if(aPos==0 && ('a'==line[0] || 'A'==line[0])) {
            aPos=lineCounter;
        } else if(bPos==0 && ('b'==line[0] || 'B'==line[0])) {
            bPos=lineCounter;
        }  else if(cPos==0 && ('c'==line[0] || 'C'==line[0])) {
            cPos=lineCounter;
        }  else if(dPos==0 && ('d'==line[0] || 'D'==line[0])) {
            dPos=lineCounter;
        }  else if(ePos==0 && ('e'==line[0] || 'E'==line[0])) {
            ePos=lineCounter;
        }  else if(fPos==0 && ('f'==line[0] || 'F'==line[0])) {
            fPos=lineCounter;
        }  else if(gPos==0 && ('g'==line[0] || 'G'==line[0])) {
            gPos=lineCounter;
        }  else if(hPos==0 && ('h'==line[0] || 'H'==line[0])) {
            hPos=lineCounter;
        }  else if(iPos==0 && ('i'==line[0] || 'I'==line[0])) {
            iPos=lineCounter;
        }  else if(jPos==0 && ('j'==line[0] || 'J'==line[0])) {
            jPos=lineCounter;
        }  else if(kPos==0 && ('k'==line[0] || 'K'==line[0])) {
            kPos=lineCounter;
        }  else if(lPos==0 && ('l'==line[0] || 'L'==line[0])) {
            lPos=lineCounter;
        }  else if(mPos==0 && ('m'==line[0] || 'M'==line[0])) {
            mPos=lineCounter;
        }  else if(nPos==0 && ('n'==line[0] || 'N'==line[0])) {
            nPos=lineCounter;
        }  else if(oPos==0 && ('o'==line[0] || 'O'==line[0])) {
            oPos=lineCounter;
        }  else if(pPos==0 && ('p'==line[0] || 'P'==line[0])) {
            pPos=lineCounter;
        }  else if(qPos==0 && ('q'==line[0] || 'Q'==line[0])) {
            qPos=lineCounter;
        }  else if(rPos==0 && ('r'==line[0] || 'R'==line[0])) {
            rPos=lineCounter;
        }  else if(sPos==0 && ('s'==line[0] || 'S'==line[0])) {
            sPos=lineCounter;
        }  else if(tPos==0 && ('t'==line[0] || 'T'==line[0])) {
            tPos=lineCounter;
        }  else if(uPos==0 && ('u'==line[0] || 'U'==line[0])) {
            uPos=lineCounter;
        }  else if(vPos==0 && ('v'==line[0] || 'V'==line[0])) {
            vPos=lineCounter;
        }  else if(wPos==0 && ('w'==line[0] || 'W'==line[0])) {
            wPos=lineCounter;
        }  else if(xPos==0 && ('x'==line[0] || 'X'==line[0])) {
            xPos=lineCounter;
        }  else if(yPos==0 && ('y'==line[0] || 'Y'==line[0])) {
            yPos=lineCounter;
        }  else if(zPos==0 && ('z'==line[0] || 'Z'==line[0])) {
            zPos=lineCounter;
        }
    }

    //cleanup dictionary file:
    fclose(f);
    len = sizeof(dictionary);
    for(int i = 0; i < 466550; i++) {
        for(int j = 0; j < strlen(dictionary[i]); j++) {
            if(dictionary[i][j]) {
                dictionary[i][j] = tolower(dictionary[i][j]);
//                printf("%c",dictionary[i][j]);
            }
        }
//        printf("\n%s",dictionary[i]);
    }
    if(line)
        free(line);    
    
    // let's read the input file now (argument) :
    FILE *f1;
    char * line1 = NULL;
    size_t len1 = 0;
    ssize_t read1;
    
    f1 = fopen(argv[1],"r");
    if(f1==NULL) {
        printf("Error occurred! Input file does not exist, please contact uroshm@gmail.com.");
        return (EXIT_FAILURE);
    }
    
    char buf[40];
    while (fscanf(f1,"%s",buf) != EOF) {
        for(int i = 0; i < sizeof(&buf)-1; i++) {
            if(buf[i]!=NULL) {
            buf[i]=tolower(buf[i]);
            printf("%c",buf[i]);    
            }
            
        }
        printf("\n");
//        printf("%s\n",&buf);
        
    }
    
    //cleanup the input file:
    fclose(f1);
    if(line1)
        free(line1);
    for(int i = 0; i < 466550; i++) {
        free(dictionary[i]);
    }
    
    return (EXIT_SUCCESS);
} 

void usage() {
    printf("\n");
    printf("Usage : SpellChecker <fileName>");
    return;
}