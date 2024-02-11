#include <bits/stdc++.h>
using namespace std;
map<string,string>passwordDB;
map<string,bool>isUsed;
map<string,pair<string,string>>userInfo;
void removeExtraSpaces(string &s){
    string filtered;
    for(auto i:s){
        if(i!=' ')
            filtered+=i;
    }
    s=filtered;
}
void resetPassword(){
    cout<<"\t\t\t\t\t\tWelcome To Our Reset Password Page"<<endl;
    string userName, newPassword;
    cout<<"Please Enter Your Username: ";
    Insert_User:
    getline(cin, userName);
    removeExtraSpaces(userName);
    if(userName.empty()||!isUsed.count(userName)){
        cout<<"Invalid Username!"<<endl;
        goto Insert_User;
    }
    cout<<"Please Enter New Password: ";
    Insert_Pass:
    getline(cin, newPassword);
    removeExtraSpaces(newPassword);
    if(newPassword.empty()){
        cout<<"Password cannot be empty!"<<endl;
        goto Insert_Pass;
    }
    passwordDB[userName] = newPassword;
    cout<<"Password reset successfully for user: "<<userName<<endl;
}
void signUp(){
    cout<<"\t\t\t\t\t\t Welcome To Our Sign Up Page"<<endl;
    string username,password,firstName,lastName;
    cout<<"Please Enter Username: ";
    Insert_User:
    getline(cin, username);
    removeExtraSpaces(username);
    if(username.empty()){
        cout<<"Username cannot be empty!"<<endl;
        goto Insert_User;
    }
    if(isUsed[username]){
        cout<<"Username already taken!"<<endl;
        goto Insert_User;
    }
    cout<<"Please Enter Your First Name: ";
    Insert_First:
    getline(cin, firstName);
    if(firstName.empty())
        goto Insert_First;
    cout<<"Please Enter Your Last Name: ";
    Insert_Last:
    getline(cin, lastName);
    if(lastName.empty())
        goto Insert_Last;
    cout<<"Please Enter Password: ";
    Insert_Pass:
    getline(cin, password);
    if(password.empty()){
        cout<<"Password cannot be empty!"<<endl;
        goto Insert_Pass;
    }
    isUsed[username]=true;
    passwordDB[username]=password;
    userInfo[username] = make_pair(firstName, lastName);
    cout<<"\t\t\t\t\t\t Successfully signed up. You can log in now."<<endl;
}
void logIn(){
    cout<<"\t\t\t\t\t\t Welcome To Our Log In Page"<<endl;
    string username, password;
    cout<<"Please Enter Username: ";
    Insert_User:
    getline(cin, username);
    if(username.empty()){
        cout<<"Invalid Username!"<<endl;
        goto Insert_User;
    }
    removeExtraSpaces(username);
    cout<<"Please Enter Password: ";
    Insert_Pass:
    getline(cin, password);
    if(password.empty()){
        cout<<"Invalid Password!"<<endl;
        goto Insert_Pass;
    }
    removeExtraSpaces(password);
    if(passwordDB.count(username)&&passwordDB[username]==password){
        cout<<"\t\t\t\t\t\t Login successful!"<<endl;
        cout<<"\t\t\t\t\t\t Your Information:"<<endl;
        cout<<"Username: \t"<<username<<endl;
        cout<<"First Name: \t"<<userInfo[username].first<<endl;
        cout<<"Last Name: \t"<<userInfo[username].second<<endl;
    }
    else{
        cout<<"Incorrect Password!"<< endl;
    }
}
int32_t main(){
    while (true) {
        cout<<"Welcome To Our Registration System"<<endl;
        cout<<"Please Select What You Want To Do And Enter The Corresponding Number:"<<endl;
        cout<<"\t 1. Log in"<<endl;
        cout<<"\t 2. Sign Up"<<endl;
        cout<<"\t 3. Reset Password"<<endl;
        cout<<"\t 4. Exit"<<endl;
        int choice;
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:
                logIn();
                break;
            case 2:
                signUp();
                break;
            case 3:
                resetPassword();
                break;
            case 4:
                cout<<"Exiting program..."<<endl;
                return 0;
            default:
                cout<<"Invalid choice! Please enter a valid number."<<endl;
                break;
        }
    }
    return 0 ;
}