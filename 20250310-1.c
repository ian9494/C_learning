#include <stdio.h>
#include <string.h>

struct HealthProfile {
    char lastName[10];
    char firstName[10];
     union {
      int genderUnknown;
      char gender;
    } s;
};

int main() {
    struct HealthProfile hp[100];
    int count = 0;
    int male = 0, female = 0, unknown = 0;
    char input[30];

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "end", 3) == 0) {
            break;
        }

        sscanf(input, "%s %s %c", hp[count].lastName, hp[count].firstName, &hp[count].s.gender);

        if (hp[count].s.gender == 'M') {
            male++;
        } else if (hp[count].s.gender == 'F') {
            female++;
        } else {
            hp[count].s.gender = 0;
            unknown++;
        }

        count++;
    }

    printf("F: %d(", female);
    for (int i = 0; i < count; i++) {
        if (hp[i].s.gender == 'F') {
            printf("%s %s ", hp[i].firstName, hp[i].lastName);
            if (--female > 0) {
                printf(", ");
            }
        }
    }
    printf(")\n");

    printf("M: %d(", male);
    for (int i = 0; i < count; i++) {
        if (hp[i].s.gender == 'M') {
            printf("%s %s ", hp[i].firstName, hp[i].lastName);
            if (--male > 0) {
                printf(", ");
            }
        }
    }
    printf(")\n");
    
    printf("U: %d(", unknown);
    for (int i = 0; i < count; i++) {
        if (hp[i].s.gender == 0) {
            printf("%s %s ", hp[i].firstName, hp[i].lastName);
            if (--unknown > 0) {
                printf(", ");
            }
        }
    }
    printf(")\n");

    return 0;
}