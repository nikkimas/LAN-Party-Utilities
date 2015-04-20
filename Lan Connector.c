#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void) {

    printf("test1\n");
    char* charUsername;
    char charPath[1000], charPathMainFolder[1000];
    char charIn;

    printf("test2\n");

    charUsername = getenv( "USERNAME" );

    sprintf(charPath ,"C:\\Users\\%s\\AppData\\Roaming\\.MrDjSoft\\Lan-Connector", charUsername);
    sprintf(charPathMainFolder, "C:\\Users\\%s\\AppData\\Roaming\\.MrDjSoft", charUsername);
    printf("%s\n", charPath);

    start:
    fflush(stdin);
    mkdir( charPathMainFolder );
    system("cls");
    system("color 0a");
    system("title LAN-Party Utilities                                                                                  By MrDj 2015");
    printf("[1] Host\n");
    printf("[2] Client\n");
    printf("[3] Open last Connection(WIP)\n");
    printf("[X] Kill Connection\n");
    printf("[C] Close Programm\n");
    printf("Eingabe: ");
    scanf("%c", &charIn);
    fflush(stdin);

    switch( charIn )    {

        case '1':
            host();
            break;
        case '2':
            client();
            break;
        case '3':
            memory();
            break;
        case 'x':
            kill();
            break;
        case 'X':
            kill();
            break;
        case 'c':
            killProgramm();
            break;
        case 'C':
            killProgramm();
            break;
        case 'H':
            easterEgg();
            break;
        default:
            system("cls");
            printf("Unknown Option: %c \n! Please try again!\n", charIn);
            system("pause");
            goto start;
            break;

    }
    return (0);
}

int host (void) {

    system("cls");
    printf("Verzeichnis wird erstellt!\n");
    if ( mkdir("C:\\Lan-Folder") == -1 ) {
        printf("Verzeichnis gefunden!\n");
    }
    if ( mkdir("C:\\Lan-Folder") == 0 ) {
        printf("Verzeichnis erstellt!\n\n");
    }
    system("net share LAN-DRIVE=C:\\Lan-Folder /GRANT:Jeder,FULL");
    system("echo Bitte teile den Nutzern diesen Namen mit: ");
    printf("\n\n");
    printf("\n");
    printf("######################################################\n");
    printf("\n");
    system("echo                     %computername%");
    printf("\n");
    printf("######################################################\n");
    printf("\n");
    system("pause");
    main();

}

int client (void) {

    char charHostName[100], command[1000],sCommandFile[1000], charPath[1000];
    char* charUsername, charPathFolder;

    system("cls");
    printf("1");

    charUsername = getenv( "USERNAME" );
    printf("2");
    sprintf(charPath ,"C:\\Users\\%s\\AppData\\Roaming\\.MrDjSoft\\Lan-Connector", charUsername);
    printf("3");

    system( "net use X: /delete" );
    system( "cls" );
    printf( "Enter the Name you get from the Host!\n" );
    printf( "Input> " );
    scanf( "%s", &charHostName );
    sprintf( sCommandFile, "echo %s>%s\\Last.txt", charHostName, charPath );
    mkdir( charPath );
    system( sCommandFile );
    system( "cls");
    sprintf( command, "net use X: \\\\%s\\LAN-DRIVE", charHostName );
    system( command );
    printf( "Connected!\n" );

    system( "pause" );
    main();

}

int memory (void)  {

    char charHostName[100], command[1000],sCommandFile[1000], buf[100];
    char charPath[100];
    char* charPathFolder, charUsername;

    charUsername = getenv( "USERNAME" );
    system("cls");
    printf("This feature is still WIP (Work-In-Progress)\n");

    printf("1\n");
    sprintf(charPath ,"C:\\Users\\%c\\AppData\\Roaming\\.MrDjSoft\\Lan-Connector\\Last.txt", charUsername);
    printf("2\n");
    printf("C:\\Users\\%c\\AppData\\Roaming\\.MrDjSoft\\Lan-Connector\\Last.txt", charUsername);
    printf("3\n");
    FILE *ptr_file;


    printf("Existiert!");
    printf("\n");
    system("cls");
    ptr_file = fopen("C:\\Users\\David\\AppData\\Roaming\\.MrDjSoft\\Lan-Connector\\Last.txt", "r");
    printf("\n%c", charPath);
    fgets(buf, 1000, ptr_file);
    printf("\n");
    printf("name: %s", buf);

    sprintf( command, "net use X: \\\\%s\\LAN-DRIVE", buf );
    system( command );
    printf("%s", command );
    printf("\n\n");
    printf( "Connected!\n" );
    system("pause");

        main();
        return -1;
}

int killProgramm(void) {

    system("cls");
    system("pause");
    system("exit");

}

int kill(void) {

    system("cls");
    system("net use X: /delete");
    system("pause");
    main();

}

int easterEgg(void) {

    int intTempVar = 15;
    do {
        intTempVar = intTempVar - 1;
        system("color 0a");
        system("color a0");
        system("color 0a");
    }while(intTempVar != 0 );
    system("cls");
    main();

}
