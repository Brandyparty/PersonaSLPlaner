#include "sociallink.h"
#include "stdio.h"
#include <string>
#include "qtextstream.h"

SocialLink::SocialLink(const char* name, int amountofdays)
{
    qDebug("%s", qUtf8Printable("<LINK>"));
    /*
    int pointsNeeded[10];
    bool relationship;
    char* statNeeded[10];
    int availableDays;
    int angermeter;
    int rank;
    char* answers;
    char* flags;
    bool plantodate;
    char* name;
    bool linkNeeded;
    const char* linkNeededToStart;
    int linkNeededToStartRank;
    */
    this->linkNeeded = false;
    this->angermeter = 45;
    this->rank = 0;
    this->maxrank = 10;
    this->name = name;
    this->availableDays = amountofdays;
    //QTextStream(stdout) << this->name;
    //QTextStream(stdout) << this->availableDays;
    qDebug("%s", qUtf8Printable(this->name));
    //qDebug("%s", qUtf8Printable(std::to_string(this->availableDays)));
    //qDebug() << this->name;
    qDebug ("%d", this->availableDays);
}

void SocialLink::setRank(int rank) {
    this->rank = rank;
    qDebug ("%s", "StartRank:");
    qDebug ("%d", this->rank);
}

void SocialLink::setMaxRank(int rank) {
    this->maxrank = rank;
    qDebug ("%s", "MaxRank:");
    qDebug ("%d", this->maxrank);
}

void SocialLink::incrementRank() {
    this->rank++;
    qDebug ("%d", this->rank);
}
void SocialLink::setlinkToStart(const char* nameoflink, int rank) {
    this->linkNeeded = true;
    this->linkNeededToStart = nameoflink;
    this->linkNeededToStartRank = rank;
    qDebug ("%s", "LinkNeeded:");
    qDebug ("%s", this->linkNeededToStart);
    qDebug ("%d", this->linkNeededToStartRank);
}
void SocialLink::setParameterNeeded(const char* parameter, int rank) {
    //char* txt = _strdup(parameter);
    //strcpy_s(txt, txt);
    //unsigned long long length = std::to_string(rank).length();
    //txt[] = to_string(rank);
    //.std::to_string(rank);
    this->statNeeded[rank-1] = parameter;
    qDebug ("%s", this->statNeeded[rank-1]);
    qDebug ("%d", (rank-1));
}
