#ifndef SOCIALLINK_H
#define SOCIALLINK_H


class SocialLink
{
public:
    SocialLink(const char* name, int amountofdays);
    void setRank(int rank);
    void setMaxRank(int rank);
    void incrementRank();
    void setlinkToStart(const char* nameoflink, int rank);
    void setParameterNeeded(const char* parameter, int rank);

private:
    int pointsNeeded[10];
    bool relationship;
    const char* statNeeded[10];
    int availableDays;
    int angermeter;
    int rank;
    int maxrank;
    char* answers;
    const char* flags;
    bool plantodate;
    const char* name;
    bool linkNeeded;
    const char* linkNeededToStart;
    int linkNeededToStartRank;
};

#endif // SOCIALLINK_H
