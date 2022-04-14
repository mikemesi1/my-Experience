#include"admin.h"
void admin(vector<order> &orderList, brackets &brackets)
{
	bool done = false;
	int option;
	while (!done)
	{
		cout << "\t\tWelcome Admin.\n\tWhat would you like to do?\n";
		cout << "\tOption 0: Exit Admin interface.\n";
		cout << "\tOption 1: Print all the current orders.\n";
		cout << "\tOption 2: Set the different prices and weight brackets for item shipping.\n";
		cout << "\tOption 3: Search for an order.\n";
		cin >> option;
		if (option == 0)	//terminates the admin interface
		{
			done = true;
			cout << "Have a great day Admin.\n";
		}
		else if (option == 1)	//prints out all of the current orders in the class vector passed in
		{
			cout << "Printing all current orders.\n";
			for(unsigned i =0; i < orderList.size(); i++){
				orderList[i].print_order();

			}
		}
		else if (option == 2)	//Sets the wight bracket ranges and their prices for shipping
		{
			bool set=false;
			int a,b;
			while(!set)								//let 
			{
				cout << "Whould you like to set the prices for the shipping weight(1), or the boundaries for the shipping price(2)? (0 to quit)\n";
				cin >>a;
				if(a==0)
				{
					set=true;		//break loop and go back to the first while loop to ask what admin would like to do.
				}
				else if(a==1)		// move into setting low, medium, or high weight price
				{
					cout << "Would you like to set low, medium or high weight prices?(1,2,3 respectively and 0 to quit)\n";
					cin >> b;		
					if(b==0)
					{
						set=true;
					}
					else if(b==1)	//set low weight price
					{
						float newprice;
						cout << "What would you like to change the low weight price to?\n";
						cin >> newprice;
						brackets.set_brprc0(newprice);
						cout << "The new first bracket price is: $"<< brackets.get_brprc0();
					}
					else if(b==2)	//set medium weight price
					{
						float newprice;
						cout << "What would you like to change the medium weight price to?\n";
						cin >> newprice;
						brackets.set_brprc1(newprice);
						cout << "The new second bracket price is: $"<< brackets.get_brprc1();

					}
					else if(b==3)	//set high weight price
					{
						float newprice;
						cout << "What would you like to change the high weight price to?\n";
						cin >> newprice;
						brackets.set_brprc2(newprice);
						cout << "The new third bracket price is: $"<< brackets.get_brprc2();

					}
				}
				else if(a==2)	//change the shipping weight boundaries 
				{
					int c;
					cout << "would you like to change the boundary between the lower and medium weight ranges or the medium and higher weight?\n(1 and 2 respectiely 0 to quit)";
					cin >>c;
					if(c==0)		//if the user wants to quit make set true and move out of loop.
					{
						set=true;
					}
					else if(c==1)	//set first shipping weight boundary.
					{
						float newweight;
						cout << "What would you like to set the lower-medium weight boundary at?\n";
						cin>>newweight;
						brackets.set_brwt1(newweight);
						cout << "The new first weight boundary is: "<<brackets.get_wt1();

					}
					else if(c==2)	//set second shipping weight boundary.
					{
						float newweight;
						cout << "What would you like to set the lower-medium weight boundary at?\n";
						cin>>newweight;
						brackets.set_brwt2(newweight);
						cout << "The new second weight boundary is: "<<brackets.get_wt2();
					}
				}
			}
			
		}
		else if (option == 3)	// allows the searching of orders based on date, order status, and price range.
		{
			bool sflag;
			int choice;
			cout << "please choos your searching parameters\n";
			cout << "\tOption 0: don't search.\n";
			cout << "\tOption 1: search by date\n";
			cout << "\tOption 2: Search by status.\n";
			cout << "\tOption 3: Search by price range.\n";
			cin >> choice;
			if(choice ==0)//allows user to cancel search.
			{
				cout << "Canceling search...\n\n";	
			}
			else if(choice ==1)	//allows the user to search by date
			{
				int day=0, month=0, year=0;
				cout << "what date would you like to search by?(day,month,year seperated by a space)\n";
				cin >> day;
				cin >> month;
				cin >> year;
				
//					The next if and corrosponding if else statements deal with the different   combonations of date input the admin may desire to search by.				
					if((day==0&&month==0&&year==0) || (day<0||month<0||year<0))		//if nothing was entered
						cout << "Please put a valid input starting with day, then month and then year, or select option 1 to print existing orders\n\n";
					else if(day ==0 && month ==0 &&year!=0)		//if just the year is input
					{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if(orderList[i].getYear()==year)
								{
									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}

					}
					else if(day==0 &&month!=0 && year!=0)	//if the month and the year are input
					{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if((orderList[i].getYear()==year)&&(orderList[i].getMonth()==month))
								{
									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();

								}
							}

					}
					else if(day!=0 && month!=0 && year!=0)	//if all the parameters are set
					{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if(orderList[i].getYear()==year&&(orderList[i].getMonth()==month)&&(orderList[i].getDay()==day))
								{
									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}

					}
					else if(day!=0 && month!=0 && year==0)	//if just day and month are set
					{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if(orderList[i].getMonth()==month&&(orderList[i].getMonth()==month))
								{
									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}

					}
					else if(day!=0 && month==0 &&year==0)	//if just day is set
					{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if(orderList[i].getDay()==day)
								{
									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}

					}
					else if(day==0 &&month!=0&&year==0)		//if just month is set
					{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if((orderList[i].getMonth()==month))
								{
 									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}

					}


			}
			else if(choice ==2)	//if the admin would like to look at fulfilled orders or unfulfilled
			{
				int status =0;
				cout << "which would you like to see?(1 for fulfilled, 2 for unfullfilled)\n";	
				cin >> status;
				if(status ==0)
					cout << "Okay, returning to home\n";
				else if(status ==1)		//search for fulfilled
				{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if(orderList[i].getstatus()==true)
								{
									if(!sflag)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}
					
				}
				else if(status ==2)	//search unfulfilled
				{
						for(unsigned i=0;i<orderList.size();i++)
							{
								if(orderList[i].getstatus()==false)
								{
									if(sflag==false)
										sflag=true;
  				   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}
				}
			}
			else if(choice ==3)//search by a price range
			{
				int lower, higher;
				cout << "Enter the two numbers you would like the price tobe between.(lower, then higher\n";
				cin >> lower;
				cin >>higher;
						for(unsigned i=0;i<orderList.size();i++)
							{
								if((lower<orderList[i].getPrice()) && (orderList[i].getPrice() < higher))
								{
									if(sflag==false)
										sflag=true;  	 
	 			   			        std::cout << i << ":";
							        orderList[i].print_order();
								}
							}
			}
			if(sflag==false)	//if the search was unsuccesful
			{
				cout << "Sorry there were no orders with that information.\n";
			}
		}
		else				//wrong input
			cout << "That was not a valid choice, try again\n\n";
	}

}