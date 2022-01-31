#include <iostream>
#include <string.h>
#include "libLunartec.h"

using namespace std;

char *entete(char speed,char page='B',int ligne=0,char centre='A');
unsigned char checkSum(char data[]);
bool identifiant(char idText[],int id=0);

bool identifiant(char idText[],int id=0){
    if(id<0 || id>99){
        return false;
    }
    sprintf(txt, "<ID%02d>", id);
    return true;
}

unsigned char checkSum(char *data){
    char c=0;
    for(int i=0; data[i]!=0; i++)
        c=c^data[i];
    return c;
}

char *entete(char speed, char page, int ligne, char centre){
    if(speed==0)
        return 0;

    static char data[]="<L0><PB><FB><MA><WB><FB>";
    data[6]=page;
    data[2]=ligne+'0';
    data[14]=speed;
    data[10]=centre;

    return data;
}

int main()
{
    cout << "Afficheur Lunartec" << endl;

    cout << "Code ouverture lunartec : " << lunartecOpen(3) << endl;
    //lunartecMessageWrite("MONSIEUR METUSHI VOTRE MASQUE");

    char data[200];
    strcpy(data, entete('b')); //copie l'entête dans le tableau data
    strcat(data, ":) X/ ;) :\"( Xd XD o.O O.O\" :S :X :D"); // ajoute le message dans data
    //cout << data << endl; // pour vérification
    //printf("%2X\n", checkSum(data));
    //lunartecDataWrite(data);

    // code à mettre dans le main et à complèterchar text[200];
    char text[200];
    strcpy(text,"<ID00>");
    // copie de l’entête et du message (voir exo précédent)
    char checkStr[10];
    sprintf(checkStr,"%02X",checkSum(data)); // conversion 2 digits hexa
    // à terminer ...
    strcat(text, data);
    strcat(text, checkStr);
    strcat(text, "<E>");

    cout << text << endl;
    lunartecRawWrite(text);
    lunartecClose();

    return 0;
}


