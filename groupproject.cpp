#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream check_file;
    ofstream create_file;
    string filename;
    string message;
    string n_f_name;
	string answer1;
	string answer2;
	string answer3;
	string line;
	string line_detect;
	do{
		cout<<"if you want to  check file enter[f]"<<endl;
		cout<<"if you want to create file  enter[c]"<<endl;
		cin>>answer1;
	}while(answer1!="f" && answer1!="c");
    if(answer1=="f")
    {

            cout<<"enter file name"<<endl;
            cin>>filename;
            filename=filename+".txt";
            check_file.open(filename.c_str());
            if(check_file.is_open())
            {
                cout<<"--- file opened successfully ---"<<endl;
                cout<<"--- file contents ---------------"<<endl;
                while(getline(check_file,line))
                {
                    line_detect.append(line);
                    cout<<line<<endl;
                }
                cout<<"-------------------------------------------------------"<<endl;
                cout<<"do you want to save this file content to an other file[yes/no]"<<endl;
                cin>>answer2;
                if(answer2=="yes")
                {
                    cout<<"enter new file name"<<endl;
                    cin>>n_f_name;
                    n_f_name=n_f_name+".txt";
                    create_file.open(n_f_name.c_str(),ios::app);
                    if(create_file.is_open())
                    {

                        create_file<<line_detect;
                        cout<<"your data has been successfully copied to your new file"<<endl;
                    }
                    else
                    {

                        return 0;
                    }
                }
            }
            else

            {
                cout<<"file doesnot exit\n";
                return 0;
            }
        }



            else if(answer1=="c")
            {
                cout<<"create new file name"<<endl;
                cin>>n_f_name;
                n_f_name=n_f_name+".txt";
                create_file.open(n_f_name.c_str(),ios::app);
                if(create_file.is_open())
                {
                	
                    cout<<"write your message here"<<endl;
                    getline(message,create_file);
                    create_file<<message<<endl;
                    cout<<"your data has been successfully copied to your new file"<<endl;
                    create_file.close();
                }
                else
                {
                    return 0;
                }
            }

        else if(check_file.fail())
        {
            cout << "file not exist" << endl;
            cout<<"do you want to create file"<<endl;
            cin>>answer2;
        }
        check_file.close();
    return 0;
}
