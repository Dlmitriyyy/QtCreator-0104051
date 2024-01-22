#include "persons.h"
#include <QDate>

Person::Person() : un_id(0), name(""), sname(""), fname(""), num_pass(""), date_of_birth(""), more_info("") {}

Person::Person(long int un_id, string name, string sname, string fname, string num_pass, string date_of_birth, string more_info)
{
    this->un_id = un_id;
    this->name = name;
    this->sname = sname;
    this->fname = fname;
    this->num_pass = num_pass;
    this->date_of_birth = date_of_birth;
    this->more_info = more_info;
}

void Person::set_ID(long int un_id) { this->un_id = un_id; }
void Person::set_Sname(string sname) { this->sname = sname; }
void Person::set_Name(string name) { this->name = name; }
void Person::set_Fname(string fname) { this->fname = fname; }
void Person::set_NumPass(string num_pass) { this->num_pass = num_pass; }
void Person::set_DateOfBirth(const QDate &date_of_birth) { this->date_of_birth = date_of_birth.toString().toStdString(); }
void Person::set_MoreInfo(string more_info) { this->more_info = more_info; }

int Person::get_ID() { return un_id; }
string Person::get_Sname() { return sname; }
string Person::get_Name() { return name; }
string Person::get_Fname() { return fname; }
string Person::get_NumPass() { return num_pass; }
string Person::get_DateOfBirth() { return date_of_birth; }
string Person::get_MoreInfo() { return more_info; }

unsigned long int Students::count = 1;

Students::Students()
    : Person(0, "", "", "", "", "", ""), school(""), specialty(""), group("")
{
}

Students::Students(long int un_id, string name, string sname, string fname, string num_pass, string date_of_birth, string more_info, string school, string speciality, string group)
    : Person(un_id, name, sname, fname, num_pass, date_of_birth, more_info), school(school), specialty(speciality), group(group)
{
    count++;
}

void Students::set_School(string school) { this->school = school; }
void Students::set_Speciality(string specialty) { this->specialty = specialty; }
void Students::set_Group(string group) { this->group = group; }

string Students::get_School() { return school; }
string Students::get_Speciality() { return specialty; }
string Students::get_Group() { return group; }

void Students::reset_count()
{
    count = 1;
}
