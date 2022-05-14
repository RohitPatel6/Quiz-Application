#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "quiz.h"
#include "conio2.h"
using namespace std;

bool User::input()
{
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(25,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(25,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<"QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"       "<<"*";
       gotoxy(25,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       gotoxy(58,4);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);
       gotoxy(20,7);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(20,8);
              cout<<"*"<<"     ";
       gotoxy(20,9);
              cout<<"*"<<"     ";
       gotoxy(20,10);
              cout<<"*"<<"     ";
       gotoxy(20,11);
              cout<<"*"<<"     ";
       gotoxy(20,12);
              cout<<"*"<<"     ";
       gotoxy(20,13);
              cout<<"*"<<"     ";
       gotoxy(20,14);
              cout<<"*"<<"     ";
       gotoxy(20,15);
              cout<<"*"<<"     ";
       gotoxy(20,16);
              cout<<"*"<<"     ";
       gotoxy(60,8);
              cout<<"*"<<"     ";
       gotoxy(60,9);
              cout<<"*"<<"     ";
       gotoxy(60,10);
              cout<<"*"<<"     ";
       gotoxy(60,11);
              cout<<"*"<<"     ";
       gotoxy(60,12);
              cout<<"*"<<"     ";
       gotoxy(60,13);
              cout<<"*"<<"     ";
       gotoxy(60,14);
              cout<<"*"<<"     ";
       gotoxy(60,15);
              cout<<"*"<<"     ";
       gotoxy(20,16);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(23,9);
       cout<<"        "<<"Enter UserId:";
       gotoxy(44,9);
       cin.getline(userId,20);

       if(strcmp(userId,"0")==0)
              return false;

       gotoxy(23,10);
       cout<<"        "<<"Enter Password:";
       gotoxy(46,10);

    char ch;
    int i=0;
    while(1)
    {
       ch=getch();
       if(ch==13)
        {
              break;
        }
        if(ch==8)
        {
               if(i==0)
                  continue;
               cout<<"\b \b";
               i--;
               continue;
        }
        cout<<ch;
        delay(200);
        cout<<"\b*";
        pwd[i]=ch;
        i++;
     }
     pwd[i]='\0';
     if(strcmp(pwd,"0")==0)
        return false;
     return true;
}

void User::setUserDetails(string userId,string name,string pwd)
{
    strcpy(this->userId,userId.c_str());
    strcpy(this->userName,name.c_str());
    strcpy(this->pwd,pwd.c_str());
}

void Admin::createAdmin(string userId,string name,string pwd)
{
       fstream fobj("Admin.bin",ios::in | ios::binary);
       if(fobj.fail())
       {
            fobj.open("Admin.bin",ios::out|ios::binary);
            Admin adminUser;
            adminUser.setUserDetails(userId,name,pwd);
            fobj.write((char*)&adminUser,sizeof(Admin));
            cout<<"File created!"<<endl;
            getch();
       }
       fobj.close();
}






bool User::checkUserExists(string usertype)
{
      if(strcmp(userId,"0")==0 || strcmp(pwd,"0")==0)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Both fields are mandatory";
              getch();
              return 0;
      }
      ifstream fin;
      User* uptr;

      if(usertype=="Admin")
      {
             fin.open("Admin.bin",ios::in|ios::binary);
             uptr=new Admin;

      }else if(usertype=="Student")
      {
             fin.open("Student.bin",ios::in|ios::binary);
             uptr=new Student;
      }else
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Invalid User Type!!";
              getch();
              return 0;
      }

      bool userIdFound=false;
      bool userpwdFound=false;

      while(1)
      {
             fin.read((char*)uptr,sizeof(*uptr));
             if(fin.eof())
               break;
             if(strcmp(userId,uptr->userId)==0)
             {
                    userIdFound=true;
                    if(strcmp(pwd,uptr->pwd)==0)
                    {
                           userpwdFound=true;
                    }
             }
      }
      bool result=false;
      if(userIdFound==false)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"No such User exists!!!";
              getch();
              return 0;
      }
      else if(userIdFound&&userpwdFound==false)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Invalid Password!!!";
              getch();
              return 0;
      }
      else
      {
             strcpy(userName,uptr->userName);
             result=true;
      }
      fin.close();
     return result;
}

string User::getName()
{
     string name(userName);
     return name;
}

void Admin::addQuestion()
{
       Question obj;
       obj.add();
       clrscr();
}

void Question::add()
{
     fstream fobj("Question.bin",ios::app|ios::binary|ios::in);
      if(!fobj)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fobj.seekg(0,ios::end);

      if(fobj.tellg()==0)
         qesId=1;
      else
      {
           fobj.seekg(-1*sizeof(*this),ios::end);
           fobj.read((char*)this,sizeof(*this));
           qesId++;
      }

      char choice;
      do
      {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(25,1);
              for(int i=1; i<=25; i++)
              cout<<"*";
              gotoxy(25,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<"QUIZ APPLICATION";
              textcolor(LIGHTGREEN);
              cout<<"  "<<"*";
              gotoxy(25,3);
              for(int i=1; i<=25; i++)
              cout<<"*";

              gotoxy(58,4);
              textcolor(WHITE);
              cout<<"Press 0 to Exit/Go back";

              textcolor(LIGHTGREEN);
              gotoxy(20,5);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(20,6);
                     cout<<"*"<<"     ";
              gotoxy(20,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(20,8);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<""<<"Add Question";

              textcolor(YELLOW);
              gotoxy(1,10);
                 cout<<"Enter Question:";


            textcolor(YELLOW);

            string str;

            gotoxy(1,10);
               cout<<"Enter Question:";

           getline(cin,str,'*');

           if(strcmp(str.c_str(),"0")==0)
           {
                     textcolor(LIGHTRED);
                     gotoxy(1,24);
                     cout<<"Closing add Question...";
                     getch();
                     break;
           }

           strncpy(ques,str.c_str(),499);

           gotoxy(1,11);
               cout<<"Carries Marks:";
            cin>>totalMarks;

            cin.ignore();

            gotoxy(1,13);
               cout<<"OPTIONS";

            gotoxy(1,14);
               cout<<"(a)";
            gotoxy(4,14);
                getline(cin,str);
            strncpy(op1,str.c_str(),99);

            gotoxy(1,15);
               cout<<"(b)";
            gotoxy(4,15);
                getline(cin,str);
            strncpy(op2,str.c_str(),99);

            gotoxy(1,16);
               cout<<"(c)";
            gotoxy(4,16);
                getline(cin,str);
            strncpy(op3,str.c_str(),99);

           gotoxy(1,17);
               cout<<"(d)";
            gotoxy(4,17);
                getline(cin,str);
            strncpy(op4,str.c_str(),99);


          while(1)
          {
                  gotoxy(1,19);
                  textcolor(YELLOW);
                  gotoxy(1,19);
                      cout<<"Enter Correct ans(a/b/c/d):    \b";
                  cin>>ans;
                  if(ans=='a' || ans=='b' || ans=='c' || ans=='d')
                  {
                         break;
                  }
                  else{
                         textcolor(LIGHTRED);
                         gotoxy(30,20);
                         cout<<"Invalid option entered! please try again.";
                         getch();
                  }
          }
       fobj.write((char*)this,sizeof(*this));
       gotoxy(30,21);
       textcolor(LIGHTGREEN);
       cout<<"Quesion Added successfully";
       getch();
       textcolor(LIGHTRED);
       gotoxy(1,23);
       cout<<"Do you want to add more question (Y/N):";
       cin>>choice;
       qesId++;
      }while(choice=='y' || choice=='Y');
}
void Admin :: viewQuestion()
{
       Question obj;
       obj.viewQuestion();
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(18,1);
       for(int i=1; i<=35; i++)
       cout<<"*";
       gotoxy(18,2);
       cout<<"*"<<"   ";
       textcolor(LIGHTBLUE);
       cout<<"No More Question Present....";
       textcolor(LIGHTGREEN);
       cout<<"  "<<"*";
       gotoxy(18,3);
       for(int i=1; i<=35; i++)
       cout<<"*";
       getch();
}

void Question :: viewQuestion()
{
    ifstream fin("Question.bin",ios::in | ios::binary);
    if(!fin)
    {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No question present!!";
            getch();
            return;
    }
     fin.seekg(0,ios::beg);
    while(1)
    {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(25,1);
              for(int i=1; i<=25; i++)
              cout<<"*";
              gotoxy(25,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<"  QUIZ APP";
              textcolor(LIGHTGREEN);
              cout<<"        "<<"*";
              gotoxy(25,3);
              for(int i=1; i<=25; i++)
              cout<<"*";

              textcolor(LIGHTGREEN);
              gotoxy(20,5);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(20,6);
                     cout<<"*"<<"     ";
              gotoxy(20,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(20,8);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"  "<<"SHOW QUESTION DETAILS";

              Question obj;
              fin.read((char*)&obj,sizeof(Question));
              obj.show();
              if(fin.eof())
              {
                     break;
              }
              getch();
      }
}


void Question::show()
{
       textcolor(YELLOW);
       gotoxy(1,10);
       cout<<"Q."<<this->qesId<<" ";
       for(int i=0; this->ques[i]!='\0'; i++)
       {
              cout<<this->ques[i];
       }
       cout<<endl<<endl;
       cout<<"Carries marks: "<<this->totalMarks<<endl<<endl;
       cout<<"a. "<<this->op1<<endl;
       cout<<"b. "<<this->op2<<endl;
       cout<<"c. "<<this->op3<<endl;
       cout<<"d. "<<this->op4<<endl<<endl;
       textcolor(LIGHTGREEN);
       cout<<"Correct Option is: "<<this->ans;
}

void Admin :: removeQuestion()
{
      Question obj;
      obj.Remove();
      clrscr();
}

void Question :: Remove()
{
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(25,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(25,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<"QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"       "<<"*";
       gotoxy(25,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       gotoxy(58,4);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);
       gotoxy(20,7);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(20,8);
              cout<<"*"<<"     ";
       gotoxy(20,9);
              cout<<"*"<<"     ";
       gotoxy(20,10);
              cout<<"*"<<"     ";

       gotoxy(60,8);
              cout<<"*"<<"     ";
       gotoxy(60,9);
              cout<<"*"<<"     ";
       gotoxy(60,10);
              cout<<"*"<<"     ";


       gotoxy(20,11);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(22,9);
       cout<<"     Enter Question Id:";

       ifstream fin("Question.bin",ios::in | ios::binary);
       if(!fin)
       {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fin.seekg(0,ios::end);
      if(fin.tellg()==0)
      {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No More Question Present....";
            getch();
            return;
      }
      fin.seekg(0,ios::beg);

      ofstream fout("temp.bin",ios::out|ios::binary);
      if(!fout)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Sorry! removal not possible!";
            getch();
            return;
      }

      int id;
      bool valid=true;
      bool found=false;
      do
      {
           textcolor(LIGHTGREEN);
           gotoxy(22,13);
           cout<<"\t\t\t\t\t\t\t\t";
           valid=true;
           gotoxy(45,9);
           cout<<"\t\t";
           gotoxy(45,9);
           cin>>id;
           if(id == 0)
           {
                  fin.close();
                  fout.close();
                  remove("temp.bin");
                  return;
           }
           if(id < 0)
           {
                 textcolor(LIGHTRED);
                 gotoxy(25,13);
                 cout<<"ID Can't be negative!!!!";
                 getch();
           }
           else
           {
                   while(1)
                   {
                          fin.read((char*)this,sizeof(*this));
                          if(fin.eof())
                              break;
                          if(id == this->qesId)
                          {
                                 found=true;
                                 continue;
                          }else{
                                 fout.write((char*)this,sizeof(*this));
                          }
                   }
                   fin.close();
                   fout.close();
                   if(found)
                   {
                        textcolor(LIGHTGREEN);
                        gotoxy(25,13);
                        cout<<"Question removed Successfully!!!";
                        getch();
                        remove("Question.bin");
                        rename("temp.bin","Question.bin");
                        return;
                   }
                   else
                   {
                        textcolor(LIGHTRED);
                        gotoxy(25,13);
                        cout<<"Question Id not found!!!";
                        getch();
                        remove("temp.bin");
                   }
           }
      }while(valid);
      getch();
}


void Admin::addStudent()
{
       Student obj;
       obj.add();
       clrscr();
}

void Student::add()
{
     int id;
     char stuId[20];
     string str;

     fstream fobj("Student.bin",ios::app|ios::binary|ios::in);
      if(!fobj)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fobj.seekg(0,ios::end);
      if(fobj.tellg()==0)
         id=1;
      else
      {
           fobj.seekg(-1*sizeof(*this),ios::end);
           fobj.read((char*)this,sizeof(*this));
           char* pos=strchr(userId,'-');
           if(pos!=NULL)
           {
                  id=atoi(pos+1);
                  id++;
           }
      }
      char choice;
      fobj.seekg(0,ios::end);
      do
      {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(25,1);
              for(int i=1; i<=25; i++)
              cout<<"*";
              gotoxy(25,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<"QUIZ APP";
              textcolor(LIGHTGREEN);
              cout<<"        "<<"*";
              gotoxy(25,3);
              for(int i=1; i<=25; i++)
              cout<<"*";

              gotoxy(58,4);
              textcolor(WHITE);
              cout<<"Press 0 to Exit/Go back";

              textcolor(LIGHTGREEN);
              gotoxy(20,5);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(20,6);
                     cout<<"*"<<"     ";
              gotoxy(20,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(20,8);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"  "<<"Add Students";

              textcolor(YELLOW);
              gotoxy(1,10);
                 cout<<"Enter Student Name:";


            textcolor(YELLOW);
           cin.ignore();
           getline(cin,str);
           strncpy(userName,str.c_str(),49);

           if(strcmp(userName,"0")==0)
           {
                     textcolor(LIGHTRED);
                     gotoxy(1,24);
                     cout<<"Closing add Question...";
                     getch();
                     fobj.close();
                     break;
           }

           gotoxy(1,11);
               cout<<"Enter Student Password:";

          textcolor(YELLOW);
           getline(cin,str);
           strncpy(pwd,str.c_str(),19);
           if(strcmp(pwd,"0")==0)
           {
                     textcolor(LIGHTRED);
                     gotoxy(1,24);
                     cout<<"Closing add Question...";
                     getch();
                     fobj.close();
                     break;
           }

          sprintf(stuId,"STU-%d",id);
          strcpy(userId,stuId);

          fobj.write((char*)this,sizeof(*this));
          gotoxy(30,21);
          textcolor(LIGHTGREEN);
          cout<<"Student Added successfully";
          getch();
          textcolor(LIGHTRED);
          gotoxy(1,23);
          cout<<"Do you want to add more Student (Y/N):";
          cin>>choice;
          id++;
       }while(choice=='y' || choice=='Y');
       fobj.close();
}




void Admin :: viewStudent()
{
       Student obj;
       obj.showStudentDetails();
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(18,1);
       for(int i=1; i<=35; i++)
       cout<<"*";
       gotoxy(18,2);
       cout<<"*"<<"   ";
       textcolor(LIGHTBLUE);
       cout<<"No More Student Present....";
       textcolor(LIGHTGREEN);
       cout<<"  "<<"*";
       gotoxy(18,3);
       for(int i=1; i<=35; i++)
       cout<<"*";
       getch();
}

void Student :: showStudentDetails()
{
    ifstream fin("Student.bin",ios::in | ios::binary);
    if(!fin)
    {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No Student present!!";
            getch();
            return;
    }
    fin.seekg(0,ios::beg);
    while(1)
    {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(25,1);
              for(int i=1; i<=25; i++)
              cout<<"*";
              gotoxy(25,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<"  QUIZ APP";
              textcolor(LIGHTGREEN);
              cout<<"        "<<"*";
              gotoxy(25,3);
              for(int i=1; i<=25; i++)
              cout<<"*";

              textcolor(LIGHTGREEN);
              gotoxy(20,5);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(20,6);
                     cout<<"*"<<"     ";
              gotoxy(20,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(20,8);
              for(int i=20; i<=55; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"  "<<"SHOW STUDENT DETAILS";

              fin.read((char*)this,sizeof(*this));
              if(fin.eof())
              {
                     break;
              }
              else
              {
                 show();
                 getch();
              }
      }
}

void User::show()
{
       textcolor(YELLOW);
       gotoxy(1,10);
       cout<<"Student Id:"<<userId<<endl;
       cout<<"Student Name: "<<userName<<endl;
       cout<<"Student Password: "<<pwd<<endl;
}

void Admin :: removeStudent()
{
      Student obj;
      obj.Remove();
      clrscr();
}

void Student :: Remove()
{
       string str;
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(25,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(25,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<"QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"       "<<"*";
       gotoxy(25,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       gotoxy(58,4);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);
       gotoxy(20,7);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(20,8);
              cout<<"*"<<"     ";
       gotoxy(20,9);
              cout<<"*"<<"     ";
       gotoxy(20,10);
              cout<<"*"<<"     ";

       gotoxy(60,8);
              cout<<"*"<<"     ";
       gotoxy(60,9);
              cout<<"*"<<"     ";
       gotoxy(60,10);
              cout<<"*"<<"     ";


       gotoxy(20,11);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(22,9);
       cout<<"     Enter Studnet Id:";

       ifstream fin("Student.bin",ios::in | ios::binary);
       if(!fin)
       {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fin.seekg(0,ios::end);
      if(fin.tellg()==0)
      {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No More Student Present....";
            getch();
            return;
      }
      fin.seekg(0,ios::beg);

      ofstream fout("temp.bin",ios::out|ios::binary);
      if(!fout)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Sorry! removal not possible!";
            getch();
            return;
      }
      bool valid=true;

      bool found=false;

     cin.ignore();

      do
      {
           textcolor(LIGHTGREEN);
           gotoxy(22,13);
           cout<<"\t\t\t\t\t\t\t\t";
           valid=true;
           gotoxy(45,9);
           cout<<"\t\t";
           gotoxy(45,9);
           getline(cin,str);
           if(str == "0")
           {
                  fin.close();
                  fout.close();
                  remove("temp.bin");
                  return;
           }
           if(str.size() < 3)
           {
                 textcolor(LIGHTRED);
                 gotoxy(25,13);
                 cout<<"ID Must have 3 characters!!!!";
                 getch();
           }
           else
           {
                   while(1)
                   {
                          fin.read((char*)this,sizeof(*this));
                          if(fin.eof())
                              break;
                          if(strcmp(this->userId,str.c_str())==0)
                          {
                                 found=true;
                                 continue;
                          }else{
                                 fout.write((char*)this,sizeof(*this));
                          }
                   }
                   fin.close();
                   fout.close();
                   if(found)
                   {
                        textcolor(LIGHTGREEN);
                        gotoxy(25,13);
                        cout<<"Student removed Successfully!!!";
                        getch();
                        remove("Student.bin");
                        rename("temp.bin","Student.bin");
                        return;
                   }
                   else
                   {
                        textcolor(LIGHTRED);
                        gotoxy(25,13);
                        cout<<"Student Id not found!!!";
                        getch();
                        remove("temp.bin");
                   }
           }

      }while(valid);

      getch();
}



















