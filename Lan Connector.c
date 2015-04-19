#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void) {

    char charIn;
    char charHostName[100], command[1000],sCommandFile[1000], charPath[1000], charPathZwei[1000];
    char* charUsername, charPathFolder;

    charUsername = getenv( "USERNAME" );
    sprintf(charPath ,"C:\\Users\\%s\\AppData\\Roaming\\.MrDjSoft\\Lan-Connector", charUsername);
    sprintf(charPathFolder, "C:\\Users\\%s\\AppData\\Roaming\\.MrDjSoft", charUsername);

    start:
    mkdir( charPathFolder );
    system("cls");
    system("color 0a");
    system("title LAN-Party Utilities                                                                                  By MrDj 2015");
    printf("[1] Host\n");
    printf("[2] Client\n");
    printf("[3] Open last Connection(WIP)\n");
    printf("[X] Kill Connection\n");
    printf("Eingabe: ");
    scanf("%c", &charIn);
    fflush(stdin);

/*Connect to Host*/
    connect:
    if ( charIn == '2' )   {

        system( "net use X: /delete" );
        system( "cls" );
        printf( "Enter the Name you get from the Host!\n" );
        printf( "Input> " );
        scanf( "%s", &charHostName );
        sprintf( sCommandFile, "echo %s >%s\\Last.txt", charHostName, charPath );
        mkdir( charPath );
        system( sCommandFile );
        system( "cls");
        sprintf( command, "net use X: \\\\%s\\LAN-DRIVE", charHostName );
        system( command );
        printf( "Connected!\n" );

        system( "pause" );
        goto start;
    }

/*Host Setup*/
    host:
    if ( charIn == '1' ) {

        system("cls");
        printf("Verzeichnis wird erstellt!\n");
        if ( mkdir("C:\\Lan-Folder") == -1 ) {
            printf("Verzeichnis gefunden!\n");
        }
        if ( mkdir("C:\\Lan-Folder") == 0 ) {
            system("net share LAN-DRIVE=C:\\Lan-Folder /GRANT:Jeder,FULL");
            printf("Verzeichnis erstellt!\n\n");
        }
        system("echo Bitte teile den Nutzern diesen Namen mit: ");
        printf("\n");
        system("echo %computername%");
        system("pause");
        goto start;

    }

/*Open last*/
    open:
    if ( charIn == '3' ) {

        system("cls");
        printf("This feature is still WIP (Work-In-Progress)\n");


        if( access( charPath, F_OK ) != -1 ) {

            printf("Existiert!");
            printf("\n");
            return 2;

        } else {

            printf("Existiert nicht!");
            mkdir( charPath );
            printf("\n");

            if ( access( charPath, F_OK ) != -1 )  {

                printf("Has been created");

            }
            return -1;

        }



        goto start;

    }

/*Test Stuff*/
    test:
    if ( charIn == 't' )    {

        printf("\n\nNothing to see here!\n\n");
        system("pause");

        goto start;
    }


/*Kill connections*/

    if ( charIn == 'x' || charIn == 'X' ) {

        kill:
        system("cls");
        system("net use X: /delete");

    }


    return 0;
}
