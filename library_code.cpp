#include<bits/stdc++.h>
#include<fstream>
using namespace std;

vector<pair<string,string>> student_login = {
    {"nishantr20","nishant"},{"tejasr20","tejas"},{"uttamk20","uttam"},{"aarchie20","aarchie"}
};

vector <pair<string,string>> prof_login = {
    {"indranilsaha","indranil"},{"urbichatterjee","urbi"},{"rajatmittal","rajat"}
};

vector<pair<string,string>> librarian_login = {
    {"raghunath","xyz"}
};
bool studentt,proff;
string Myuser, Mybook;

vector<vector<string>> book_info{{"book1","author1","ISBN1","publication1"},{"book2","author2","ISBN2","publication2"},{"book3","author3","ISBN3","publication3"},{"book4","author4","ISBN4","publication4"},{"book5","author5","ISBN5","publication5"}};
vector<string> list_of_books {"book1","book2","book3","book4","book5"};
map<string,string> due_time_calculator;
map<string,vector<string>> issued_books;

int book_search(string name){
    for(int i=0; i<book_info.size(); i++){
        if(book_info[i][0]==name) return (i+1);
    }
    return 0;
}

 int check_availablity(string name){
     for(int i=0; i<list_of_books.size(); i++){
         if(list_of_books[i]==name) return (i+1);
     }
     return 0;
 }
class book{
    public:
    //     char bookTitle[100],bookAuthor[100],bookISBN[100],publication[100];
    // book(){
    //     strcpy(bookTitle,"No Book in data");
    //     strcpy(bookAuthor,"No Author in data");
    //     strcpy(bookISBN,"No ISBN in data");
    //     strcpy(publication,"No publication in data");
    // }

    void Book_Request();
//     void Show_duedate(){
//         // current date/time based on current system
// //    time_t now = time(0);
   
// //    // convert now to string form
// //    char* dt = ctime(&now);

// //    cout << "The local date and time is: " << dt << endl;
//     }
    void display_all_books();
    void show_Issued_books(){
        cout<<"Enter username of the user whose issued books you want to see:\n";
        string s;
        cin>>s;
        cout<<"The list of Books issued are\n";
        for(auto books : issued_books[s]){
            cout<<books<<"\n";
        }
    }
    
    
};

void book:: Book_Request(){

    string book_name;
    string issuer_name;
    
    cout<<"Please enter the name of the book you want to issue\n";
    cin>>book_name;
    if(!check_availablity(book_name)){
        cout<< "book is not available for issue\n";
    }
    else{
        
        cout<< "book is available for issue \n please re-enter your username to issue the book\n";
        cin >> issuer_name;
        
        remove(list_of_books.begin(),list_of_books.end(),book_name);
        issued_books[issuer_name].push_back(book_name);
        cout<< "book issued successfully \n Thank You\n";
    }


}

void book::display_all_books(){
    for (int i = 0; i < book_info.size(); i++) {
        for (int j = 0; j < book_info[i].size(); j++)
            cout << book_info[i][j] << " ";
        cout << endl;
    }
}


class book_database{
    public:
    void Add_book_to_list();


    void Update_book(){
        string old_name;
        cout<< "Enter name of the book to be updated\n";
        cin >> old_name;
        if(book_search(old_name)){
            remove(list_of_books.begin(),list_of_books.end(),old_name);
            int j=book_search(old_name);
            book_info.erase(book_info.begin()+j-1);
            string new_book_name,new_book_author,new_book_ISBN,new_book_publication;
    cout<< "Enter new name of the book to be updated\n";
    cin >>new_book_name;
    list_of_books.push_back(new_book_name);
    cout<< "Enter new author of the book to be updated\n";
    cin>> new_book_author;
    cout << "Enter new ISBN number of the book to be updated\n";
    cin >> new_book_ISBN;
    cout << "Enter the new name of the book publication to be updated\n";
    cin >> new_book_publication;

book_info.push_back({new_book_name,new_book_author,new_book_ISBN,new_book_publication});
    cout<< "Book updated successfully.\n Thank you";
        }
        else cout<< "Book does not exist in the database \n Thank you\n";
    }


    void Delete_book(){
        cout << "Enter name of the book you want to delete\n";
        string del_book;
        cin >> del_book;
        if(!check_availablity(del_book)){
            cout<< "the book is issued by some user, can't be removed from the library untill it is returned\n";
        }
        else{
            remove(list_of_books.begin(),list_of_books.end(),del_book);
            int j=book_search(del_book);
            book_info.erase(book_info.begin()+j-1);
            cout<< "book has been deleted successfully\n";
        }

    }
    
    
};

void book_database :: Add_book_to_list(){
    string book_name,book_author,book_ISBN,book_publication;
    cout<< "Enter name of the book to be added\n";
    cin >> book_name;
    list_of_books.push_back(book_name);
    cout<< "Enter author of the book to be added\n";
    cin>> book_author;
    cout << "Enter ISBN number of the book to be added\n";
    cin >> book_ISBN;
    cout << "Enter the name of the book publication to be added\n";
    cin >> book_publication; 

    book_info.push_back({book_name,book_author,book_ISBN,book_publication});
    //strcpy(book.bookTitle, book_name);
}

class user_database{
    public: 
    void Add_user(){
        cout<<"Enter 1 : to add prof \n 2: add student\n";
        int chk;
        cin>>chk;
        string s,s1;
        cout<<"Enter the user name of the user to be added\n";
        cin>>s;
        cout<<"Enter the Password of the user to be added\n";
        cin>>s1;
        if(chk==2)student_login.push_back({s,s1});
        if(chk==1)prof_login.push_back({s,s1});
        cout<<"The User is Added Succesfully!\n";
    }
    void Update_user(){
        cout<<"Enter the user name of the user to be updated\n";


    }
    void Delete_user(){
         cout<< "Enter the type of user you want to delete\n 1 : For professor \n 2 : For student\n";
        int p;
        cin >> p;
            cout<<"Enter the user name of the user you want to delete\n";
            string s;cin>>s;

        if(p==1){
            bool found = false;
            for(auto items : prof_login){
                if(items.first == s){
                    pair<string,string> dt = items;
                    auto it = find(prof_login.begin(),prof_login.end(),dt);
                    prof_login.erase(it);
                    found = true;
                    cout<<"The user is deleted successfully\n";return;
                }
            }
            cout<<"The Given User do not exist\n";
            
        }
        else if(p==2){
            for(auto items : student_login){
                if(items.first == s){
                    pair<string,string> dt = items;
                    auto it = find(student_login.begin(),student_login.end(),dt);
                    student_login.erase(it);
                    cout<<"The user is deleted successfully\n";return;
                }
            }
            cout<<"The Given User do not exist\n";
        }
    }
    void Search_user(){
    
        cout<< "Enter the type of user you want to search\n 1 : For professor \n 2 : For student\n";
        int p;
        cin >> p;
            cout<<"Enter the user name of the user you want to search\n";
            string s;cin>>s;

        if(p==1){
            bool found = false;
            for(auto items : prof_login){
                if(items.first == s){
                    cout<<"The user exists\n";return;
                }
            }
            cout<<"The Given User do not exist\n";
            
        }
        else if(p==2){
            for(auto items : student_login){
                if(items.first == s){
                    cout<<"The user exists\n";return;
                }
            }
            cout<<"The Given User do not exist\n";
        }
    }

};

class user{
    public:
    string name;
    string ID;
    string password;

};

class professor : public user{
    public:
    int fine_amount=0;
    void calculate_fine(){
        int days;
        cout<< "Enter the number of days after which you are returning the book\n";
        cin >> days;
        if(days<=60){
            cout<< "The fine amount is zero\n";
        }
        else if(days>60){
            fine_amount=fine_amount+(days-60)*5;
        }
        cout<< "the fine amount is " << fine_amount;
    }
    void clear_fine(){
        fine_amount=0;
        cout<< "the fine is cleared";
    }
};

class student : public user{
    public:
    int fine_amount=0;
    void calculate_fine(){
        int days;
        cout<< "Enter the number of days after which you are returning the book\n";
        cin >> days;
        if(days<=30){
            cout<< "The fine amount is zero\n";
        }
        else if(days>60){
            fine_amount=fine_amount+(days-30)*2;
        }
        cout<< "the fine amount is " << fine_amount << "\n";
    }
    void clear_fine(){
        fine_amount=0;
        cout<< "the fine is cleared\n";
    }

};

class librarian : public user{
    public:
    void display_issued_books(){
        cout<<"The List of the issued books and users to whom they are issued is\n";
        for(auto books : issued_books){
            for(auto i: books.second){
                cout<<books.first<<" "<<i;

            }
        }
    }

};

class Login{
    string UserName;
    string Password;
    public:
    void askUserName(){
        cout<<"Please Enter Your User Name-\n";
        cin>>UserName;
    }
    void askPassword(){
        cout<<"Please Enter Your Password-\n";
        cin>>Password;
    }
    int validate(){
    if(studentt==true)for(auto i: student_login){
          if(i.first==UserName && i.second==Password){
              cout<<"You are successfully logged in.\n";
              return 2;
          }
    }
      else if(proff==true)    for(auto i: prof_login){
          if(i.first==UserName && i.second==Password){
              cout<<"You are successfully logged in.\n";
              return 1;
          }
      }
      else    for(auto i: librarian_login){
          if(i.first==UserName && i.second==Password){
              cout<<"You are successfully logged in.\n";
              return 3;
          }
    }
    cout<<"Invalid UserName or Password.\n";
    return 0;
    }
};

int main(){

jump:
cout<<"enter your type\n";
cout<<"1 professor\n";
cout<<"2 student\n";
cout<<"3 librarian\n";
int opt;
cin>>opt;
if(opt==1){
    proff=true;
    studentt=false;
}
else if(opt == 2){
    proff=false;
    studentt=true;
}
else{
    proff=false;
    studentt=false;
}
 Login L;
 L.askUserName();
 L.askPassword();
 int validation = L.validate();

if(validation==0){
    goto jump;
}
if(validation==1){
    cout<< "************************Welcome professor*************************\n" ;
    professor P;
    book B;
    int command=-1;
    while(command!=7){
    cout<<"Enter your choice\n";
    cout<<"1: Issue a book\n";
    cout<<"2: list of issued books\n";
    cout<<"3: to see your fine\n";
    cout<<"4: show available books\n";
    cout<<"5: to clear your fine\n";
    cout<<"6: to show due date of the issued books\n";
    cout<<"7: to logout\n";
    
    cin>>command;
    if(command==1) B.Book_Request();
    if(command==2) B.show_Issued_books();
    if(command==3) P.calculate_fine();
    if(command==4) {
        for(auto i: list_of_books)cout<<"i \n";
    }
    if(command==5) P.clear_fine();
    if(command==6) cout<< "return the book after 60 days\n";
    if(command==7) {
        cout<< "successfully logged out\n";
        goto jump;
    }
    }
    //if(command==1)


}
if(validation==2){
cout<< "****************************Welome Student****************************\n";
    student S;
    book B;
    int command=-1;
    while(command!=7){
    cout<<"Enter your choice\n";
    cout<<"1: Issue a book\n";
    cout<<"2: list of issued books\n";
    cout<<"3: to see your fine\n";
    cout<<"4: show available books\n";
    cout<<"5: to clear your fine\n";
    cout<<"6: to show due date of the issued books\n";
    cout<<"7: to logout\n";
    
    cin>>command;
    if(command==1) B.Book_Request();
    if(command==2) B.show_Issued_books();
    if(command==3) S.calculate_fine();
    if(command==4) {
        for(auto i: list_of_books)cout<<"i \n";
    }
    if(command==5) S.clear_fine();
    if(command==6) "return the book after 30 days\n";
    if(command==7) {
        cout<< "successfully logged out\n";
        goto jump;
    }
    }
}

if(validation==3){
    cout<< "***************************Welcome librarian**************************\n";
    librarian S;
    book B;
    book_database bd;
    user_database ud;
    int command=-1;
    while(command!=7){
    cout<<"Enter your choice\n";
    cout<<"1 : Add book to database\n";
    cout<<"2 : Search a book from database\n";
    cout<<"3 : Delete a book from database\n";
    cout<<"4 : To update a book in the database";
    cout<<"5 : To check the list of issued books\n";
    cout<<"6 : To check the list of available books\n";
    cout<<"7 : To see the list of all users\n";
    cout<<"8 : To add a user\n";
    cout<<"9 : To search a user\n";
    cout<<"10 : To delete a user\n";
    cout<<"11 : To logout\n";
    cin>>command;

    if(command==1) bd.Add_book_to_list();
    if(command==2) {
        cout << "Enter the name of the book you want to issue\n";
        string mno;
        cin>>mno;
        int pqr= book_search(mno);
        if(!pqr)
        cout<< "book does not exists in database\n";
        else cout<< "book exists in the database\n";
    }
    if(command==3) bd.Delete_book();
    if(command==4) bd.Update_book();
    if(command==5) B.show_Issued_books();
    if(command==6) {
        for(int i=0; i<list_of_books.size(); i++){
            cout<< list_of_books[i] << "\n";
        }
    }
    if(command==7){
        for(int i=0; i<student_login.size(); i++){
            cout<< student_login[i].first << "\n";
        }
        for(int i=0; i<prof_login.size(); i++){
            cout<< prof_login[i].first << "\n";
        }
    }
    if(command==8) ud.Add_user();
    if(command==9) ud.Search_user();
    if(command==10) ud.Delete_user();
    if(command==11){
        cout<< "successfully logged out\n";
        goto jump;
    }
    }

//if(command==1)
}

}
