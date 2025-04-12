#include <iostream>
#include <vector>
using namespace std;

class Sport;
class Skill;
class Learners;

class Mentor{
    string name;
    int id;
    vector<Sport*> expertise;
    int max;
    vector<Learners*> assignedL;
public:
    Mentor(int iD, string n, int m) : id(iD), name(n), max(m) {}
    bool assignLearner(Learners* l);
    void removeLearner(Learners* l);
    void viewLearners();
    void provideGuidance();
    string getName(){
        return name;
    }
};
class Learners{
	string name;
	int studentID;
	int age;
	vector<Sport*> sports;
	Mentor* mentorAssigned;
	public:
		Learners(int id, string n, int a):studentID(id), name(n), age(a), mentorAssigned(nullptr){}
		void viewMentorDetails(){
			if (mentorAssigned != nullptr){
				cout << "Mentor Details: " << mentorAssigned->getName()<<endl;
			}else{
				cout << "No mentor Assigned" << endl;
			}
		}
		void updateSportsInterest(Sport* s){
			sports.push_back(s);
			cout << name<< " has added"<< s<< " to their sports interests." << endl;
		}
		void registerForMentorship(Mentor* m);
		string getName(){
        	return name;
    	}
    	Mentor* getMentor(){
        	return mentorAssigned;
    	}
    	void setMentor(Mentor* m){
        	mentorAssigned = m;
    	}
};
bool Mentor::assignLearner(Learners* l){
	if (assignedL.size()<max){
		assignedL.push_back(l);
		return true;
	}
	return false;
}
void Mentor::removeLearner(Learners* l){
	for (int i =0;i <assignedL.size();i++){
        if (assignedL[i] == l){
            assignedL.erase(assignedL.begin() + i);
            l->setMentor(nullptr);
            cout << l->getName() << " has been removed from mentor " << name << endl;
            return;
        }
   	}
}
void Mentor:: viewLearners(){
	cout << "Learners assigned to mentor " << name << ":" << endl;
    for (int i =0;i <assignedL.size(); i++){
        cout <<assignedL[i]->getName() << endl;
    }
}
void Mentor:: provideGuidance(){
	cout << "Mentor " << name << " is providing guidance to learners." << endl;
}

void Learners::registerForMentorship(Mentor* m){
	if (m->assignLearner(this)){
		mentorAssigned=m;
		cout << name << " has been assigned to mentor "<< m->getName()<<endl;
	}else{
		cout << "Mentor " <<m->getName()<< " is not available" << endl;
	}
}

class Sport{
	string name;
	int id;
	string description;
	vector<Skill*> reqSkills;
	public:
		Sport(string n,int iD,string d):name(n),id(iD),description(d){}
		void addSkill(Skill* s){
			reqSkills.push_back(s);
		}
		void removeSkill(Skill* s){
			for (int i =0;i <reqSkills.size();i++){
            	if (reqSkills[i] == s){
                	reqSkills.erase(reqSkills.begin()+i);
                	return;
            	}
        	}
		}
};
class Skill{
	string name;
	int id;
	string description;
	public:
		Skill(string n,int iD,string d):name(n),id(iD),description(d) {}
		void showSkillDetails(){
			cout << "Skill: " <<name << "\nDescription: " <<description <<endl;
		}
		void updateSkillDescription(string newD){
			description = newD;
        	cout << "Skill description updated." <<endl;
		}
};


int main(){
	vector<Mentor*> mentors;
    vector<Learners*> learners;
    vector<Sport*> sports;
    vector<Skill*> skills;
    int choice;
    do {
        cout << "\n1. Add Mentor\n2. Add Student\n3. Add Sport\n4. Add Skill"<<endl;
		cout <<"5. Register Student for Mentorship\n6. View Mentor Details\n7. Exit\nEnter your choice:  ";
        cin >> choice;
        switch (choice){
        	case 1:{
                int id, max;
                string name;
                cout << "Enter Mentor ID: ";
                cin >> id;
                cout << "Enter Mentor Name: ";
                cin >> name;
                cout << "Enter Maximum Learners: ";
                cin >> max;
                mentors.push_back(new Mentor(id, name, max));
                cout << "Mentor added successfully!" << endl;
                break;
            }
            case 2:{
                int id, age;
                string name;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin >> name;
                cout << "Enter Student Age: ";
                cin >> age;
                learners.push_back(new Learners(id, name, age));
                cout << "Student added successfully!" << endl;
                break;
            }
            case 3:{
                int id;
                string name, desc;
                cout << "Enter Sport ID: ";
                cin >> id;
                cout << "Enter Sport Name: ";
                cin >> name;
                cout << "Enter Sport Description: ";
                cin >> desc;
                sports.push_back(new Sport(name,id, desc));
                cout << "Sport added successfully!" << endl;
                break;
            }
            case 4:{
                int id;
                string name, desc;
                cout << "Enter Skill ID: ";
                cin >> id;
                cout << "Enter Skill Name: ";
                cin >> name;
                cout << "Enter Skill Description: ";
                cin >> desc;
                skills.push_back(new Skill(name,id, desc));
                cout << "Skill added successfully!" << endl;
                break;
            }
            case 5:{
                if (learners.empty() || mentors.empty()){
                    cout << "No students or mentors available!" << endl;
                    break;
                }
                cout << "Select a Student:\n";
                for (int i = 0; i < learners.size(); i++){
                    cout << i + 1 << ". " << learners[i]->getName() << endl;
                }
                int studentChoice;
                cin >> studentChoice;
                if (studentChoice < 1 || studentChoice > learners.size()){
                    cout << "Invalid choice!" << endl;
                    break;
                }
                cout << "Select a Mentor:\n";
                for (int i =0;i <mentors.size();i++){
                    cout << i + 1 << ". " << mentors[i]->getName() << endl;
                }
                int mentorChoice;
                cin >> mentorChoice;
                if (mentorChoice <1 || mentorChoice >mentors.size()){
                    cout << "Invalid choice!" << endl;
                    break;
                }
                learners[studentChoice-1]->registerForMentorship(mentors[mentorChoice - 1]);
                break;
            }
            case 6:{
                if (learners.empty()){
                    cout << "No students available!" << endl;
                    break;
                }
                cout << "Select a Student:\n";
                for (int i = 0; i < learners.size(); i++){
                    cout << i + 1 << ". " << learners[i]->getName() << endl;
                }
                int studentChoice;
                cin >> studentChoice;
                learners[studentChoice - 1]->viewMentorDetails();
                break;
            }
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }while (choice !=7);
	return 0;
}
