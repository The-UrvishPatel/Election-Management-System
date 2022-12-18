#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL DECLARATIONS

#define CANDIDATE1 "BJP"
#define CANDIDATE2 "Congress"
#define CANDIDATE3 "AAP"
#define CANDIDATE4 "BSP"
#define CANDIDATE5 "NOTA"

int votesCount[5] = {0, 0, 0, 0, 0}, max_i[5] = {0}, j = 0, voters = 0;

// FILE HANDLING

FILE *fp;

// STRUCTURE

struct details
{
    char name[50];
    int code;
};

// FUNCTIONS

int castVote();
void voteCount();
int getLeadingCandidate();

// Main Function


int main()
{
    fp = fopen("2022.txt", "a");
    printf("###### Welcome to Election/Voting 2022 #####");
    printf("\n\nList of Condidates\n\n");

    printf("1. %s \n2. %s \n3. %s \n4. %s \n5.
    %s",CANDIDATE1,CANDIDATE2,CANDIDATE3,CANDIDATE4,CANDIDATE5);
    fprintf(fp,"###### Welcome to Election/Voting 2022 #####");
    fprintf(fp,"\n\nList of Condidates\n\n");
    fprintf(fp,"1. %s \n2. %s \n3. %s \n4. %s \n5.
    %s",CANDIDATE1,CANDIDATE2,CANDIDATE3,CANDIDATE4,CANDIDATE5);

    vote:

    printf("\n\n-----------------------------------------------------------------------------------------------------
    -");
    fprintf(fp,"\n\n-------------------------------------------------------------------------------------------------
    -");

    voters++;

    printf("\n\n### Voter No.: %d : Enter your details ###",voters);

    fprintf(fp,"\n\nVoter Number : %d",voters);

    struct details det;

    printf("\n\nEnter your Name: ");
    fflush(stdin);
    gets(det.name);

    printf("\nEnter your Voter ID number: ");
    scanf("%d",&det.code);
    fprintf(fp,"\n\nName of Voter : %s \nVoter ID number of the voter :
    %d\n",det.name,det.code);

    printf("\n\n### 2. Cast the Vote ###");

    int select=castVote();
    switch(select)
    {
        case 1:
            fprintf(fp, "\nVoted to Candidate[%d] BJP\n\n", select);
            break;
        case 2:
            fprintf(fp, "\nVoted to Candidate[%d] Congress\n\n", select);
            break;
        case 3:
            fprintf(fp, "\nVoted to Candidate[%d] AAP\n\n", select);
            break;
        case 4:
            fprintf(fp, "\nVoted to Candidate[%d] BSP\n\n", select);
            break;
        case 5:
            fprintf(fp, "\nVoted to Candidate[%d] NOTA\n\n", select);
            break;
    }

    printf("\n\n### Press R for Result OR Press V for next vote : ");
    char choice;
    scanf(" %c",&choice);

    main_option:

    switch(choice)
    {
        case 'R':
        {
            printf("\n\n### Vote Count ###");
            voteCount();
            printf("\n\n### Leading Candidate ###\n\n");
            getLeadingCandidate();
        option:
    printf("\n\n### Do you want to proceed for next vote? \n\nPress Y for Yes and N for No :
    ");
    scanf(" %c",&choice);

    if(choice=='Y')
    goto vote;

    else if(choice=='N')
    {
                printf("\n\nThanks for voting\n\n");
                goto final_result;
    }

    else
    {
                printf("\n\n!!! Invalid Input ~ Error");
                goto option;
    }
        }
        case 'V':
        {
            goto vote;
        }
        default:
        {
            printf("\n\n!!! Invalid Input ~ Error");
            goto main_option;
        }
    }

    final_result:
    printf("\n\n### Final Vote Count ###");

    voteCount();

    fprintf(fp,"\n\n### Final Vote Count ###\n");
    fprintf(fp,"\n %s - %d ", CANDIDATE1, votesCount[0]);
    fprintf(fp,"\n %s - %d ", CANDIDATE2, votesCount[1]);
    fprintf(fp,"\n %s - %d ", CANDIDATE3, votesCount[2]);
    fprintf(fp,"\n %s - %d ", CANDIDATE4, votesCount[3]);
    fprintf(fp,"\n %s - %d ", CANDIDATE5, votesCount[4]);
    printf("\n\n### Final Voted Candidate ###\n\n");

    int max=getLeadingCandidate();

    if(j==1)
    {
            fprintf(fp, "\n\nCANDIDATE[%d] is leading having %d votes\n\n", (max_i[j - 1] + 1), max);
    }
    else
    {
            for (int i = 0; i < j; i++)
                fprintf(fp, "CANDIDATE[%d] ", (max_i[i] + 1));
            fprintf(fp, "are leading having same %d vote count", max);
    }
    fprintf(fp,"\n\nTotal Voters = %d\n",voters);
    fprintf(fp,"\nThank You!!!");
    printf("Thank You!!!\n");
    fclose(fp);

    return 0;

}


// Cast Vote Function

int castVote()
{
    int choice;
    printf("\n\n### Please choose your Candidate ####\n\n");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. %s", CANDIDATE5);
    printf("\n\nInput your choice (1 - 5) : ");
    scanf("%d", &choice);
    votesCount[choice - 1]++;
    printf("\nThanks for vote !!");
    return choice;
}



// Vote Count Function

void voteCount()
{
    printf("\n\n##### Voting Statics ####");
    printf("\n %s - %d ", CANDIDATE1, votesCount[0]);
    printf("\n %s - %d ", CANDIDATE2, votesCount[1]);
    printf("\n %s - %d ", CANDIDATE3, votesCount[2]);
    printf("\n %s - %d ", CANDIDATE4, votesCount[3]);
    printf("\n %s - %d ", CANDIDATE5, votesCount[4]);
}



// Get Leading Candidate Function

int getLeadingCandidate()
{
    int max = votesCount[0];
    for (int i = 0; i < 5; i++)
    {
        if (votesCount[i] > max)
        {
            max = votesCount[i];
        }
    }
    j = 0;
    for (int i = 0; i < 5; i++)
    {
        if (votesCount[i] == max)
        {
            max_i[j] = i;
            j++;
        }
    }
    if (j == 1)
    {
        printf("CANDIDATE[%d] is leading having %d votes", (max_i[j - 1] + 1), max);
    }
    else
    {
        for (int i = 0; i < j; i++)
            printf("CANDIDATE[%d] ", (max_i[i] + 1));
        printf("are leading having same %d vote count", max);
    }
    printf("\n\nTotal Voters = %d\n\n", voters);
    return max;
}