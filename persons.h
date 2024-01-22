#ifndef PERSONS_H
#define PERSONS_H

#include <QDate>
#include <string>
using namespace std;

class Person
{
protected:
    long int un_id;
    string name, sname, fname, num_pass, date_of_birth, more_info;

public:
    Person();
    Person(long int un_id, string name, string sname, string fname, string num_pass, string date_of_birth, string more_info);

    void set_ID(long int un_id);
    void set_Sname(string sname);
    void set_Name(string name);
    void set_Fname(string fname);
    void set_NumPass(string num_pass);
    void set_DateOfBirth(const QDate &date_of_birth);
    void set_MoreInfo(string more_info);

    int get_ID();
    string get_Sname();
    string get_Name();
    string get_Fname();
    string get_NumPass();
    string get_DateOfBirth();
    string get_MoreInfo();
};

class Students : public Person
{
protected:
    static unsigned long int count;
    string school;
    string specialty;
    string group;

public:
    Students();
    Students(long int un_id, string name, string sname, string fname, string num_pass, string date_of_birth, string more_info, string school, string speciality, string group);
    static void reset_count();

    void set_School(string school);
    void set_Speciality(string specialty);
    void set_Group(string group);

    string get_School();
    string get_Speciality();
    string get_Group();
};

#endif // PERSONS_H
