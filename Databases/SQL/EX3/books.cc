#include<iostream>
#include<mysql.h>
#include<string>
#include<iomanip>
using namespace std;



int main()
{
	mysql_library_init(0,NULL,NULL);	//open library

	MYSQL *connect, mysql;			// create pointer to database and a mysql object
	MYSQL_ROW row;				//set up a row variable to hold row of data returned
	MYSQL_RES *result, *_result;			//set up result object to holds query result

	connect =  mysql_init(&mysql);		//get init
	connect = mysql_real_connect(connect, "courses", "z1910569", "1999Jul20", "henrybooks", 0, NULL, 0);	//establish a connection to the database



	if(connect)	//if succesful preform the actions, else fail.
	{
		string search;	//string to hold user's search
		string getl;
		cout <<"Welcome! if you would like to search a book title type t. if you would like to search an author, type a.\n If you would like to show a list of all books, type l, and if you would like to quit type q\n\n";
		char a = 'x';	//set char to nothing that is a choice

		while(a!= 'q')	// until the user wants to quit
		{
			search.clear();	//clear out contents of search string
			cout << "What would you like to do?\n";
			cin >> a;


			if(a=='t'){	//if the user wants to search a title(part 3)
				cout << "What title would you like to search for?\n";
				cin >> search;
				cout << endl << search << endl;
				getline(cin, getl);
				cout << endl << search << endl;
				search +=getl;
				string stmt = "SELECT Book.BookCode, Title, AuthorFirst, AuthorLast, Price FROM Book, Author, Wrote WHERE Book.BookCode = Wrote.BookCode AND Author.AuthorNum = Wrote.AuthorNum AND Book.Title = '" + search + "';";
			        //stmt += "' ORDER BY Wrote.Sequence;";
				const char *stmt_str= stmt.c_str();	//convert to const char string

				mysql_query(connect, stmt_str);		//preform query
				result=mysql_use_result(connect);	//put results into result
				string br = "SELECT OnHand, BranchName, BranchLocation FROM Branch, Book, Inventory WHERE Book.Title = " + search +  " AND Book.BookCode = Inventory.BookCode AND Branch.BranchNum = Inventory.BranchNum;";
				//concatonate string to enact search
				const char *br_str = br.c_str();	//set const char string equal to query

				cout << "\n\n";
				cout << setw(8) << right << "BookCode "<< setw(50) << left << "Title" << setw(16) << left << "Author" << setw(8) << right << "Price\n";	//output header
				cout << setw(8) << right << "======== "<< setw(50) << left << "====================================================" << setw(16) << left << "================" << setw(8) << right << "========\n";
				//output last part of header
				if((row = mysql_fetch_row(result))!=NULL)	//fetch the first row from search and put into row
					{
				cout << endl << "$" << endl;
				cout << setw(8) << right << row[0]<< setw(50) << left << row[1] << setw(16) << left << row[2] << setw(8) << right << row[3] << row[4] << endl;;	//output results from search formatted
				mysql_query(connect, br_str);	//preform another query
				_result=mysql_use_result(connect);	//store itsx result into _result
				while((row=mysql_fetch_row(_result))!=NULL)	//until the list is empty keep iterating through it
					cout << setw(9) << left << "-" << row[0] << "Available at " << row[1] << " " << row[2] << endl;	//output list formatted
					}
				}

			else if(a=='a'){	//else if the user wants to search for author:X
				cout<<"What Author would you like to search for?\n";
				cin >> search;
				getline(cin, search);	//get whole line
				string stmt = "SELECT BookCode, Title, AuthorLast, AuthorFirst, Price FROM Book, Wrote, Author WHERE Author.AuthorLast = "+ search + " OR Author.AuthorFirst = " + search +";"; //concat string
				const char *stmt_str= stmt.c_str();	//set const char string equal to query
				mysql_query(connect, stmt_str);		//preform query
				string br = "SELECT OnHand, BranchName, BranchLocation FROM Branch, Book, Inventory WHERE Book.Title AND Author.AuthorFirst = " + search +" OR Author.AuthorLast = "+ search;
			        br +" Book.BookCode = Inventory.BookCode AND Branch.BranchNum = Inventory.BranchNum;";	//concat string for secoind query
                                const char *br_str = br.c_str();	//set const char string equal

                                while((result=mysql_use_result(connect))!=NULL){	//until thge end of the list

					cout << "\n\n";
                                	cout << setw(8) << right << "BookCode "<< setw(50) << left << "Title" << setw(16) << left << "Author" << setw(8) << right << "Price\n";//header
                                	cout << setw(8) << right << "======== "<< setw(50) << left << "====================================================" << setw(16) << left << "================" << setw(8) << right << "========\n";
                                	//end of header
					row = mysql_fetch_row(result);	//put results into row
					cout << setw(8) << right << row[0]<< setw(50) << left << row[1] << setw(16) << left << row[2] << setw(8) << right << row[3] << row[4];
					mysql_query(connect, br_str);	//	preform query
                              		_result=mysql_use_result(connect);	//put results from query into _result
                               		while((row=mysql_fetch_row(_result))!=NULL)	//until the end of the list
                                        	cout << setw(9) << left << "-" << row[0] << "Available at " << row[1] << " " << row[2] << endl;	//output results formatted

				}
			}

			else if(a == 'l'){	//else if the user just wants every book and its info
				cout << "Here is the list...\n\n\n";
				const char *stmt_str= "SELECT Title, Price, AuthorFirst, AuthorLast FROM Book, Wrote, Author WHERE Book.BookCode = Wrote.BookCode AND Author.AuthorNum = Wrote.AuthorNum ORDER BY Wrote.Sequence;";
				mysql_query(connect, stmt_str);	//preform query
				result= mysql_use_result(connect);	//store results into result
				cout << setw(52) << left << "Title:" << setw(12) << left << "Price:" << setw(14) << right << "Authors" << endl;	//heeader
				cout << "------------------------------------------------------------------------------------------------------\n";//header
				while((row = mysql_fetch_row(result))!=NULL)	//until the list is empty, output in a formatted way
					cout <<setw(50) << left << row[0] <<"  $" << setw(12) << left<< row[1] <<setw(12) << right << row[2] <<" "<<  row[3] <<endl;
				cout << "------------------------------------------------------------------------------------------------------\n\n";

			}//else if q then quit
			else if(a=='q'){
				cout <<"Thank you for trying my program.\n\n Have a great day!\n\n\n";
			}

			else{//if its none of the above interpret as error and go again
				cout <<"I'm sorry that is not a valid option, please try again\n\n";
			}
		}


	}
	else//if fails to open database exit program
	{
		mysql_errno(connect);
		exit(1);
	}
	 mysql_close(connect);//close connection
	 mysql_library_end();//close library

	return 0;
}
