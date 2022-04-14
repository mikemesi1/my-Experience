CREATE TABLE User ( 				#creates User table
Name CHAR(40) NOT NULL, 			#creates collum 'Name' with max length of 40chars
USERID CHAR(16) NOT NULL UNIQUE PRIMARY KEY,	#creates userid collumn 
TransactionNUM INT UNIQUE, 			#creates transaction number collumn
Symbol CHAR(16) UNIQUE NOT NULL,		#creates a scollumn for stock symbol.
FOREIGN KEY (TransactionNUM) REFERENCES Stock(TransactionNUM) #marks transaction# as foreign key and denotes home table
);

CREATE TABLE Stock (				#creates stock table
Symbol char(16) NOT NULL UNIQUE PRIMARY KEY,	#creates the symbol collumn
COName char(40) NOT NULL UNIQUE,		#creates the company name collumn
Highest_Buy_Price INT,				#creates a collumn with the highest buy price for stocks
Lowest_Sell_Prices INT,				#creates a collumn for the lowest sell price of stocks
OrderNUM INT UNIQUE,				#creates a collumn for the order number 
UserID CHAR(40) NOT NULL UNIQUE,		#creates collumn for the UserID 
FOREGN KEY (UserID) REFERENCES User(UserID),	#denotes user id as a foreign key and it's home table.
FOREGN KEY (OrderNUM) REFERENCES Order(OrderNUM)	#denotes order number as a foregin key and its home table.
);

CREATE TABLE Transaction (			#creates transaction table
TransactionNUM INT UNIQUE,			#creates transaction collumn
Date DATE,					#creates date collumn
AccountNUM INT NOT NULL UNIQUE,			#creates account number collumn
OrderNUM INT UNIQUE,				#creates order number collumn
UserID CHAR(40),				#creates UserID collumn
FOREGN KEY (UserID) REFERENCES User(UserID),	#denotes UserID as a foreign key and states its home table
FOREGN KEY (OrderNUM) REFERENCES Order(OrderNUM),	#denotes order number as a foreign key and states its home table	
FOREGN KEY (AccountNUM) REFERENCES BankAccount(AccountNUM)	#denotes account number as a foreign key and states its home table 
);

CREATE TABLE BankAccount (					#creates bank account table
TransactionNUM INT UNIQUE,					#creates transaction number collumn
AccountNUM INT NOT NULL UNIQUE PRIMARY KEY,					#creates account number collumn
Balance INT NOT NULL,						#creates balance collumn
FOREGN KEY (TransactionNUM) REFERENCES Transaction(TransactionNUM) #marks transactionNUM as foreign key and denotes home table
);

CREATE TABLE BankActivity (			#Creates Bank activity Table
TransactionNUM INT UNIQUE,			#creates transaction number collumn
AccountNUM INT NOT NULL UNIQUE,			#creates account number collumn
WithdrawlAmount INT,				#creates withdrawl amount collumn
DeposItAmount INT,				#creates deposit amount collumn
PRIMARY KEY (TransactionNUM), (AccountNUM)	#denotes transactionNUM and 
FOREGN KEY (TransactionNUM) REFERENCES Transaction(TransactionNUM),	#denotes transactionNUM as a foreign key and states is home table
FOREGN KEY (AccountNUM) REFERENCES BankAccount(AccountNUM)		#denotes account number as a foreign key and states its home table
);

CREATE TABLE TransactionType (					#creates transactionType table
TransactionNUM INT UNIQUE,					#creates transaction number collumn
OrderNUM INT UNIQUE,						#creates a collumn for the order number
Buy? CHAR(3),							#creates a collumn for denoting the buying of a stock
Sell CHAR(3), 							#creates a collumn for denoting the selling of a stock
PRIMARY KEY (TransactionNUM), (OrderNUM),			#sets transactionNUM and OrderNUM as the orimary keys
FOREGN KEY (TransactionNUM) REFERENCES Transaction(TransactionNUM),	#denotes transactionNUM as a foreign key and states is home table
FOREGN KEY (OrderNUM) REFERENCES Order(OrderNUM)			#denotes order number as a foreign key and states its home table	
);

CREATE TABLE OrderAmount (					#Creates OrderAmount table
OrderNUM INT UNIQUE NOT NULL UNIQUE,				#Creates OrderNum collumn
Symbol CHAR(16) NOT NULL UNIQUE,				#creates symbol collumn
OrderAmount INT NOT NULL,					#Creates order amount collumn
PRIMARY KEY (Symbol), (OrderNUM),				#denotes symbol and orderNum as the primary keys
FOREGN KEY (OrderNUM) REFERENCES Order(OrderNUM),		#denotes order number as a foreign key and states its home table
FOREGN KEY (Symbol) REFERENCES Stocks(Symbol)			#denotes symbol as a foreign key and states its home table
);

CREATE TABLE UserStocks (					#creates UserStocks Table
UserID CHAR(40) NOT NULL,					#creates collumn for the UserID	
Symbol CHAR(16) NOT NULL UNIQUE					#creates a collumn for the symbols of the stocks
UserStockAmount INT,						#creates cllomn for stock amounts
PRIMARY KEY (Symbol), (UserID),					#sets primary keys as symbol and UserID											
FOREGN KEY (UserID) REFERENCES User(UserID),			#denotes UserID as a foreign key and states its home table
FOREGN KEY (Symbol) REFERENCES Stocks(Symbol)			#denotes symbol as a foreign key and states its home table
);