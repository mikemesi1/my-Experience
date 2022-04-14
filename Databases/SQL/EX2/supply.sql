#CSCI466-PE1
#z1910569

USE z1910569

DROP TABLE SP;
DROP TABLE S;   #REMOVES ALL TABLES THAT WERE BUILT IN PREVIOUS RUNS
DROP TABLE P;

CREATE TABLE S(
        S CHAR(10) UNIQUE NOT NULL PRIMARY KEY, #ID FOR SUPPLIERS
        SNAME CHAR(32) UNIQUE NOT NULL,                 #SUPPLIER NAME
        STATUS INT NOT NULL,                            #STORES?
        CITY CHAR(32) NOT NULL                          #CITY
);
INSERT INTO S
	VALUES('S1',
		'Smith',
		'20',
		'London'
	);

INSERT INTO S 
	VALUES('S2',
	       'Jones',
		'10',
		'Paris'
	
);
INSERT INTO S 
	VALUES('S3',
		'Blake',
		'30',
		'Paris'
	
);
INSERT INTO S 
	VALUES('S4',
		'Clark',
		'20',
		'London'
	
);
INSERT INTO S 
	VALUES('S5',
		'Adams',
		'30',
		'Athens'
	
);

CREATE TABLE P (
        p CHAR(10) UNIQUE NOT NULL PRIMARY KEY,         #ID FOR PARTS
        PNAME CHAR(32) NOT NULL,                 #PART NAME
        COLOR CHAR(12) NOT NULL,                        #COLOR
        WEIGHT INT NOT NULL                             #PART WEIGHT
);
INSERT INTO P 
	VALUES('P1',
		'Nut',
		'red',
		'12'
	
);
INSERT INTO P 
	VALUES('P2',
		'Bolt',
		'Green',
		'17'
	
);

INSERT INTO P 
	VALUES('P3',
		'Screw',
		'Blue',
		'17'
	

);
INSERT INTO P 
	VALUES('P4',
		'Screw',
		'Red',
		'14'
	
);
INSERT INTO P 
	VALUES('P5',
		'Cam',
		'Blue',
		'12'
	
);
INSERT INTO P 
	VALUES('P6',
		'Cog',
		'Red',
		'19'
	
);

CREATE TABLE SP(
        S CHAR(10) NOT NULL,
        P CHAR(10) NOT NULL,
        QTY INT NOT NULL,
        PRIMARY KEY(S, P),
        FOREIGN KEY(P) REFERENCES P(P),
        FOREIGN KEY(S) REFERENCES S(S)
);

INSERT INTO SP 
	VALUES('S1',
		'P1',
		'300'
);

INSERT INTO SP
	VALUES('S1',
		'P2',
		'200'


);

INSERT INTO SP
	VALUES('S1',
		'P3',
		'400'
);


INSERT INTO SP 
	VALUES('S1',
		'P4',
		'200'	
);

INSERT INTO SP 
	VALUES('S1',
		'P5',
		'100'
);
INSERT INTO SP 
	VALUES('S1',
		'P6',
		'100'
);


INSERT INTO SP 
	VALUES('S2',
		'P1',
		'300'	
);


INSERT INTO SP 
	VALUES('S2',
		'P2',
		'400'	
);


INSERT INTO SP 
	VALUES('S3',
		'P2',
		'200'	
);

INSERT INTO SP 
	VALUES('S4',
		'P2',
		'200'	
);

INSERT INTO SP 
	VALUES('S4',
		'P4',
		'300'	
);

INSERT INTO SP 
	VALUES('S4',
		'P5',
		'400'	
);



