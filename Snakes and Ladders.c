#include <stdio.h>
#include <stdlib.h>

    //BOARD PRINTER
void printBoard (char board[18][18]) {
    int x,y;
    for(y=0;y<8;y++){
        for (x=0;x<18;x++) {
            printf("%c", board[x][y]);
        }
    }
}
void printUserManual (){
printf("\nWelcome to Snakes & Ladders: Programmed in C\n");
printf("\nThis Snakes & Ladders game, programmed in C, allows 4 players to play against each other. In the case that there is only");
printf("\none player, the program will then assign 3 CPU players. In addition, the program also allows the user to modify the ");
printf("\nboard  by changing the placement of the snakes and ladders. Note that the user is only allowed to modify the placement ");
printf("\nof the snakes or ladders and not the dimensions of the board. Doing so will render the program unplayable.\n");
printf("\n\nHOW TO PLAY THE GAME\n");
printf("1. Type '1' and press enter to begin the game. (Otherwise, type '2' and press enter to quit the game)\n");
printf("2. Input the number of players (1-4) and press enter. Again, if the user chooses to play alone, there will be 3 CPU players.\n");
printf("3. The game will then ask for the players to input their tokens. The players can choose any character or symbol found in the keyboard.\n");
printf("However, it is not recommended that the user picks 'S' or 'L' as their tokens because it may conflict with the letters that represent the snakes and ladders.\n");
printf("4. Once that is all set, just click enter to progress through every turn.\n\n");
printf("HOW TO MODIFY THE BOARD\n");
printf("1. In the folder where the program is located, find the text file labeled as board.txt\n");
printf("2. Open the file.\n");
printf("3. In the file, you will find the board with the preset locations of the snakes and ladders. Simply change the locations \n");
printf("of the 'S', 's', or 'Z' and 'L', 'l', or 'I'. Dont forget to fill in the underscores. \n\n");
}
void Logo () {
    printf("     ______  ___  __    ___    __  ___ ______  ______\n");
    printf("    |  ____||   `|  |  /   `  |  |/  /|  ____||  ____|\n");
    printf("    |____  ||       | /  _  ` |     < |  ____||____  |\n");
    printf("    |______||__|`___|/__/ `__`|__|\___`|______||______|\n");
    printf("\t\t\t  ___  __   __ \n");
    printf("\t\t\t |   `|  | |_/  \n");
    printf("\t\t\t |       |\n");
    printf("\t\t\t |__|`___|\n");
    printf("  __        ___    _____   _____   ______  _____   ______\n");
    printf(" |  |      /   `  |     ` |     ` |  ____||     ` |  ____|\n");
    printf(" |  |___  /  _  ` |  |   ||  |   ||  ____||     < |____  |\n");
    printf(" |______|/__/ `__`|_____/ |_____/ |______||__|\___`|______|\n\n");
}
void Menu () {
    printf("\t\t[1] Start\n");
    printf("\t\t[2] Manual\n");
    printf("\t\t[3] Quit\n\n");
}
main () {
    char raw [200];
    char board [18][18];

    int i=0, x, y;
    int var[2], num, snake;
    int ladder;
    FILE *fp;

//extract file
    fp = fopen ("board.txt", "r");
    while (!feof(fp)) {
        fscanf(fp,"%c",&raw [i]);
        i++;
    }
    fclose(fp);

// put into multi-dimensional array
    x=0;
    y=0;
    i=0;
    while(y<8) {
        board[x][y]=raw[i];
        i++;
        x++;
        if (i%18==0) {
            y++;
            x=0;
        }
    }

    // find snake (s) down
    num=0;
    var[0]=0, var[1]=0;
    for(y=7;y>-1;y--){
        for (x=0;x<18;x++) {
            var[num]++;
            if (board[x][y]=='\n'){
                var[num]=var[num]-2;
            }
            if (board[x][y]=='s') {
                num++;
            }
        }
    }
    snake=var[1]/2;
    //find snake (S) down
    int snake2;
    num=0;
    var[0]=0, var[1]=0;
    for(y=7;y>-1;y--){
        for (x=0;x<18;x++) {
            var[num]++;
            if (board[x][y]=='\n'){
                var[num]=var[num]-2;
            }
            if (board[x][y]=='S') {
                num++;
            }
        }
    }
    snake2=var[1]/2;
    //find snake (Z) down
    int snake3;
    num=0;
    var[0]=0, var[1]=0;
    for(y=7;y>-1;y--){
        for (x=0;x<18;x++) {
            var[num]++;
            if (board[x][y]=='\n'){
                var[num]=var[num]-2;
            }
            if (board[x][y]=='Z') {
                num++;
            }
        }
    }
    snake3=var[1]/2;
    // find ladder [l] up
    num=0;
    var[0]=0, var[1]=0;
    for(y=7;y>-1;y--){
        for (x=0;x<18;x++) {
            var[num]++;
            if (board[x][y]=='\n'){
                var[num]=var[num]-2;
            }
            if (board[x][y]=='l') {
                num++;
            }
        }
    }
    ladder=var[1]/2;
    // find ladder (L) up
    int ladder2;
    num=0;
    var[0]=0, var[1]=0;
    for(y=7;y>-1;y--){
        for (x=0;x<18;x++) {
            var[num]++;
            if (board[x][y]=='\n'){
                var[num]=var[num]-2;
            }
            if (board[x][y]=='L') {
                num++;
            }
        }
    }
    ladder2=var[1]/2;
    //fing ladder (I) up
    int ladder3;
    num=0;
    var[0]=0, var[1]=0;
    for(y=7;y>-1;y--){
        for (x=0;x<18;x++) {
            var[num]++;
            if (board[x][y]=='\n'){
                var[num]=var[num]-2;
            }
            if (board[x][y]=='I') {
                num++;
            }
        }
    }
    ladder3=var[1]/2;


// game play
    int player1[4];
    player1[0]=0, player1[1]=0;
    player1[2]=0, player1[3]=0;
    char symbol[4];
    char temp1[4];
    int k, p;
    int scount[4], scount2[4], scount3[4], lcount[4], lcount2[4], lcount3[4];
    for(p=0;p<4;p++){
        scount[p]=0;
        scount2[p]=0;
        scount3[p]=0;
        lcount[p]=0;
        lcount2[p]=0;
        lcount3[p]=0;
    }
    int dice;
    srand(time(NULL));
    int choice;
    char wew;

    Logo();
    Menu();
    printf("\tEnter choice: ");
    scanf("%d", &choice);

    while (choice!=3) {
    //to start game
        if (choice==1){
        //number of players
            printf("\tInput Number of players [1-4]: ");
            scanf("%d", &k);
            //assign symbol per character
            for(p=0;p<k;p++){
                printf("\tEnter symbol for player %d: ", p+1);
                scanf("%s", &symbol[p]);
            }
    //to start with player 1
        p=0;
    // if 1 player
        if (k==1){
            symbol[1]='2';
            symbol[2]='3';
            symbol[3]='4';
            k=4;
        }
//game itself
        do {
    //dice
            printf("\nGive to player %d!\n", p+1);
            wew = getchar();
            printf("Player %d:\nPress ENTER to roll the dice", p+1);
            wew = getchar();
            dice = rand()%6 + 1;


        //replace
            if (player1[p]%8==0) {
                board[8*2-1][8-(player1[p]/8)]=temp1[p];
            }
            board [(player1[p]%8)*2-1][7-(player1[p]/8)]=temp1[p];
        //change
            player1[p]=player1[p]+dice;
            if(player1[p]==8||player1[p]==56||player1[p]==48||player1[p]==24){
                player1[p]--;
            }
            //if snake
            if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]=='s' && scount[p]==1) {
                player1[p]=player1[p]-snake;
            }
            for(y=7;y>=7-(player1[p]/8);y--){
                for (x=0;x<(player1[p]%8)*2+1;x++) {
                    if (board[x][y]=='s') {
                        scount[p]=1;
                    }
                }
            }

            //if snake2
            if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]=='S' && scount2[p]==1) {
                player1[p]=player1[p]-snake2;
            }
            for(y=7;y>=7-(player1[p]/8);y--){
                for (x=0;x<(player1[p]%8)*2+1;x++) {
                    if (board[x][y]=='S') {
                        scount2[p]=1;
                    }
                }
            }

            //if snake3
            if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]=='Z' && scount3[p]==1) {
                player1[p]=player1[p]-snake3;
            }
            for(y=7;y>=7-(player1[p]/8);y--){
                for (x=0;x<(player1[p]%8)*2+1;x++) {
                    if (board[x][y]=='Z') {
                        scount3[p]=1;
                    }
                }
            }

            //if ladder
            if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]=='l' && lcount[p]==0) {
                player1[p]=player1[p]+ladder;
            }
            for(y=7;y>=7-(player1[p]/8);y--){
                for (x=0;x<(player1[p]%8)*2+1;x++) {
                    if (board[x][y]=='l') {
                        lcount[p]=1;
                    }
                }
            }

            //if ladder2
            if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]=='L' && lcount2[p]==0) {
                player1[p]=player1[p]+ladder2;
            }
            for(y=7;y>=7-(player1[p]/8);y--){
                for (x=0;x<(player1[p]%8)*2+1;x++) {
                    if (board[x][y]=='L') {
                        lcount2[p]=1;
                    }
                }
            }

            //if ladder3
            if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]=='I' && lcount3[p]==0) {
                player1[p]=player1[p]+ladder3;
            }
            for(y=7;y>=7-(player1[p]/8);y--){
                for (x=0;x<(player1[p]%8)*2+1;x++) {
                    if (board[x][y]=='I') {
                        lcount3[p]=1;
                    }
                }
            }

        //get previous char
        if (board [(player1[p]%8)*2-1][7-(player1[p]/8)]!=symbol[0]&&board [(player1[p]%8)*2-1][7-(player1[p]/8)]!=symbol[1]&&board [(player1[p]%8)*2-1][7-(player1[p]/8)]!=symbol[2]&&board [(player1[p]%8)*2-1][7-(player1[p]/8)]!=symbol[3]){
            temp1[p]=board [(player1[p]%8)*2-1][7-(player1[p]/8)];
        }
        else {
            temp1[p]='_';
        }
            if (player1[p]%8==0) {
                temp1[p]=board[8*2-1][8-(player1[p]/8)];
                board[8*2-1][8-(player1[p]/8)]=symbol[p];
            }
            board [(player1[p]%8)*2-1][7-(player1[p]/8)]=symbol[p];
            printBoard(board);
            printf("\n");

        //change player (2) is the # of players
            p++;
            if (p==k){
                p=0;
            }
        }while (player1[p]<65);
        printf("player %d WINS\n\n", p+1);
//ask to play again
            printf("\tPress 1 to exit ");
            scanf("%d", &choice);
            if (choice==1){
                choice=3;
            }
            player1[0]=0, player1[1]=0;
            player1[2]=0, player1[3]=0;
            for(p=0;p<4;p++){
                scount[p]=0;
                scount2[p]=0;
                scount3[p]=0;
                lcount[p]=0;
                lcount2[p]=0;
                lcount3[p]=0;
            }
        }
    //user manual
        else if(choice==2){
            printUserManual ();
            Menu();
            printf("\tEnter choice: ");
            scanf("%d", &choice);
        }
    //invalid choice
        else {
            printf("\tInvalid input\n\n");
            Menu();
            printf("\tPls enter input again: ");
            scanf("%d", &choice);
        }
    }
}
