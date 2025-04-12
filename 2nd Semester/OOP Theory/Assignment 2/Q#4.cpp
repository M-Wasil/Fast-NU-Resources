#include <iostream>
#include <string>
using namespace std;

const int MAX_ASSIGNMENTS=10;
const int MAX_STUDENTS_PER_TA=10;
const int MAX_PROJECTS_PER_TA=2;
const int MAX_USERS=50;

const string SUBMIT_ASSIGNMENT="submit assignment";
const string VIEW_PROJECTS="view projects";
const string MANAGE_STUDENTS="manage_students";
const string ASSIGN_PROJECTS="assign projects";
const string FULL_LAB_ACCESS="full_lab_access";

unsigned int calculateHash(const string& password){
    unsigned int hash=5381;
    for(char c:password){
        hash=hash*33+static_cast<unsigned int>(c);
    }
    return hash;
}

class User{
protected:
    string name;
    string id;
    string email;
    unsigned int hashed_password;
    string permissions[5];
    int permissionCount;
public:
    User():permissionCount(0){}
    
    User(const string& n,const string& i,const string& e,const string& password,const string perms[],int permCount):name(n),id(i),email(e),permissionCount(permCount){
        hashed_password=calculateHash(password);
        for(int i=0;i<permCount;i++){
            permissions[i]=perms[i];
        }
    }
    
    bool authenticate(const string& password) const{
        return hashed_password==calculateHash(password);
    }
    
    virtual void displayInfo() const{
        cout<<"\nUser Information:"
            <<"\nName: "<<name
            <<"\nID: "<<id
            <<"\nEmail: "<<email
            <<"\nPermissions: ";
        for(int i=0;i<permissionCount;i++){
            cout<<permissions[i]<<" ";
        }
    }
    
    bool hasPermission(const string& permission) const{
        for(int i=0;i<permissionCount;i++){
            if(permissions[i]==permission){
                return true;
            }
        }
        return false;
    }
    
    bool accessLab(const string& action){
        if(hasPermission(action)){
            cout<<"\nAccess granted to perform: "<<action;
            return true;
        }else{
            cout<<"\nAccess denied. You don't have permission to: "<<action;
            return false;
        }
    }
    
    string getName() const{return name;}
    string getId() const{return id;}
    string getEmail() const{return email;}

    virtual ~User(){}
};

class Student:public User{
protected:
    int assignments[MAX_ASSIGNMENTS];
    int assignmentCount;
public:
    Student():assignmentCount(0){
        for(int i=0;i<MAX_ASSIGNMENTS;i++){
            assignments[i]=0;
        }
        permissions[0]=SUBMIT_ASSIGNMENT;
        permissionCount=1;
    }
    
    Student(const string& n,const string& i,const string& e,const string& password):assignmentCount(0){
        name=n;
        id=i;
        email=e;
        hashed_password=calculateHash(password);
        permissions[0]=SUBMIT_ASSIGNMENT;
        permissionCount=1;
        for(int i=0;i<MAX_ASSIGNMENTS;i++){
            assignments[i]=0;
        }
    }
    
    void displayInfo() const override{
        User::displayInfo();
        cout<<"\nRole: Student";
        if(assignmentCount==0){
            cout<<"\nNo assignments available.";
        }else{
            cout<<"\nAssignments Status: ";
            for(int i=0;i<assignmentCount;i++){
                cout<<"\nAssignment "<<i+1<<": "<<(assignments[i]?"Submitted":"Pending");
            }
        }
    }
    
    bool addAssignment(){
        if(assignmentCount<MAX_ASSIGNMENTS){
            assignments[assignmentCount]=0;
            assignmentCount++;
            cout<<"\nNew assignment added successfully!";
            return true;
        }
        cout<<"\nCannot add more assignments. Maximum limit reached!";
        return false;
    }
    
    bool submitAssignment(int assignmentNum){
        if(assignmentNum>0&&assignmentNum<=assignmentCount){
            if(assignments[assignmentNum-1]==0){
                assignments[assignmentNum-1]=1;
                cout<<"\nAssignment "<<assignmentNum<<" submitted successfully!";
                return true;
            }else{
                cout<<"\nAssignment "<<assignmentNum<<" was already submitted!";
                return false;
            }
        }
        cout<<"\nInvalid assignment number! Must be between 1 and "<<assignmentCount;
        return false;
    }
    
    int getAssignmentCount() const{return assignmentCount;}
};

class TA:public User{
    Student* managedStudents[MAX_STUDENTS_PER_TA];
    int studentCount;
    string projects[MAX_PROJECTS_PER_TA];
    int projectCount;
public:
    TA():studentCount(0),projectCount(0){
        permissions[0]=VIEW_PROJECTS;
        permissions[1]=MANAGE_STUDENTS;
        permissionCount=2;
    }
    
    TA(const string& n,const string& i,const string& e,const string& password):studentCount(0),projectCount(0){
        name=n;
        id=i;
        email=e;
        hashed_password=calculateHash(password);
        permissions[0]=VIEW_PROJECTS;
        permissions[1]=MANAGE_STUDENTS;
        permissionCount=2;
    }
    
    void displayInfo() const override{
        User::displayInfo();
        cout<<"\nRole: Teaching Assistant";
        cout<<"\nManaged Students: "<<studentCount;
        if(projectCount==0){
            cout<<"\nNo projects assigned.";
        }else{
            cout<<"\nCurrent Projects: ";
            for(int i=0;i<projectCount;i++){
                cout<<"\n- "<<projects[i];
            }
        }
    }
    
    bool addStudent(Student* student){
        if(studentCount<MAX_STUDENTS_PER_TA){
            managedStudents[studentCount]=student;
            studentCount++;
            cout<<"\nStudent "<<student->getName()<<" assigned successfully!";
            return true;
        }
        cout<<"\nCannot assign more students. Maximum limit reached!";
        return false;
    }
    
    bool addProject(const string& projectName){
        if(projectCount<MAX_PROJECTS_PER_TA){
            projects[projectCount]=projectName;
            projectCount++;
            cout<<"\nProject '"<<projectName<<"' added successfully!";
            return true;
        }
        cout<<"\nCannot add more projects. Maximum limit reached!";
        return false;
    }
};

class Professor:public User{
    TA* tas[MAX_USERS];
    int taCount;
public:
    Professor():taCount(0){
        permissions[0]=ASSIGN_PROJECTS;
        permissions[1]=FULL_LAB_ACCESS;
        permissionCount=2;
    }
    
    Professor(const string& n,const string& i,const string& e,const string& password):taCount(0){
        name=n;
        id=i;
        email=e;
        hashed_password=calculateHash(password);
        permissions[0]=ASSIGN_PROJECTS;
        permissions[1]=FULL_LAB_ACCESS;
        permissionCount=2;
    }
    
    void displayInfo() const override{
        User::displayInfo();
        cout<<"\nRole: Professor";
        cout<<"\nTAs Working With: "<<taCount;
    }
    
    bool assignProject(TA* ta,const string& projectName){
        if(ta->addProject(projectName)){
            tas[taCount]=ta;
            taCount++;
            cout<<"\nProject '"<<projectName<<"' assigned to TA "<<ta->getName();
            return true;
        }
        return false;
    }
};

void authenticateAndPerformAction(User* user,const string& action){
    string password;
    cout<<"\nEnter password for "<<user->getName()<<": ";
    cin>>password;

    if(user->authenticate(password)){
        cout<<"\nAuthentication successful!";
        user->accessLab(action);
    }else{
        cout<<"\nAuthentication failed!";
    }
}

void createUser(User* users[],int& userCount){
    if(userCount>=MAX_USERS){
        cout<<"\nMaximum number of users reached!";
        return;
    }
    int role;
    cout<<"\nSelect role:";
    cout<<"\n1. Student\n2. TA\n3. Professor\nChoice: ";
    cin>>role;
    cin.ignore();
    string name,id,email,password;
    cout<<"Enter name: ";
    getline(cin,name);
    cout<<"Enter ID: ";
    getline(cin,id);
    cout<<"Enter email: ";
    getline(cin,email);
    cout<<"Enter password: ";
    getline(cin,password);
    for(int i=0;i<userCount;i++){
        if(users[i]->getId()==id){
            cout<<"\nError: User with this ID already exists!";
            return;
        }
    }
    switch(role){
        case 1:
            users[userCount]=new Student(name,id,email,password);
            break;
        case 2:
            users[userCount]=new TA(name,id,email,password);
            break;
        case 3:
            users[userCount]=new Professor(name,id,email,password);
            break;
        default:
            cout<<"\nInvalid role selection!";
            return;
    }
    userCount++;
    cout<<"\nUser created successfully!";
}

void addAssignmentToStudent(User* users[],int userCount){
    string id;
    cout<<"Enter student ID to add assignment: ";
    getline(cin,id);
    for(int i=0;i<userCount;i++){
        if(users[i]->getId()==id){
            Student* student=dynamic_cast<Student*>(users[i]);
            if(student){
                student->addAssignment();
                return;
            }
        }
    }
    cout<<"\nStudent with ID '"<<id<<"' not found!";
}

int main(){
    User* users[MAX_USERS];
    int userCount=0;
    
    users[userCount++]=new Student("Muhammad Wasil","S1001","k240790@nu.edu.pk", "Fast1234");
    users[userCount++]=new TA("Abdullah Shabir","T2001","k240619@nu.edu.pk", "Fast12Ta34");
    users[userCount++]=new Professor("Ashhad Iqbal","P3001", "k240565@nu.edu.pk", "Fast12Prof99");
    
    Student* student=dynamic_cast<Student*>(users[0]);
    if(student){
        student->addAssignment();
        student->addAssignment();
    }
    
    TA* ta=dynamic_cast<TA*>(users[1]);
    if(ta&&student){
        ta->addStudent(student);
    }
    
    Professor* prof=dynamic_cast<Professor*>(users[2]);
    if(prof&&ta){
        prof->assignProject(ta,"AI Research Project");
    }
    
    cout<<"=== Displaying All Users ==="<<endl;
    for(int i=0;i<userCount;i++){
        users[i]->displayInfo();
        cout<<"\n----------------"<<endl;
    }
    
    cout<<"\n=== Testing Authentication and Permissions ==="<<endl;
    cout<<"\nTesting Student:"<<endl;
    authenticateAndPerformAction(users[0],SUBMIT_ASSIGNMENT); 
    authenticateAndPerformAction(users[0],FULL_LAB_ACCESS);   
    
    cout<<"\nTesting TA:"<<endl;
    authenticateAndPerformAction(users[1],MANAGE_STUDENTS);   
    authenticateAndPerformAction(users[1],ASSIGN_PROJECTS);  
    
    cout<<"\nTesting Professor:"<<endl;
    authenticateAndPerformAction(users[2],FULL_LAB_ACCESS);   
    authenticateAndPerformAction(users[2],SUBMIT_ASSIGNMENT);
    
    cout<<"\n=== Testing Student Assignment Submission ==="<<endl;
    if(student){
        cout<<"Before submission:"<<endl;
        student->displayInfo();
        cout<<"\nSubmitting assignment 1:"<<endl;
        student->submitAssignment(1);
        cout<<"\nAfter submission:"<<endl;
        student->displayInfo();
    }
    
    for(int i=0;i<userCount;i++){
        delete users[i];
    }
    return 0;
}
