#Michael Mesi
#Z1910569
#CSCI466-PE1

#1
USE BabyName;	#(1) selects the database to use for the script

#2
show tables;	#(2) Shows all the tables in the database

#3
Describe BabyName;	#(3) describes the collumns and types in for the table/all of them in the database

#4
select distinct name 'Names in 1999'	#(4) selects each distinct name for the year 1999(my birth year)
from BabyName
where year = '1999' 
limit 50;

#5
select distinct year	#(5) selects every year my name shows up
from BabyName			#in BabyName table
where name = 'Michael';		#name is michael

#6
select distinct name, max(count) 'Most Common Male Name in 1984'	#(6) counts all the distinct male names for the year 1984 and chooses the most common
from BabyName		#in BabyName table
where year = '1984'	#year is 1984
and gender = 'm';	#gender is male

#6
select distinct name, max(count) 'Most Common Female Name in 1984'	#(6) counts all the distinct female names for the year 1984 and chooses the most common
from BabyName		#in BabyName table
where year = '1984'	#year is 1984
and gender = 'f';	#gender is female

#7
select count(distinct name)'Names', place
from BabyName
group by place
order by count(distinct name) desc;

#8
select distinct name 'Names similar to michael', count, gender, year, place #(8) displays all the names that sound like michael in alphabetical order, by count nad then year.
from BabyName
where soundex(name) = soundex('michael')
group by name
order by name, count, year
limit 50;

#9
select count(name) 'Number of Names in 1974' 	#(9) Counts all of the names in 1974 with repeats
from BabyName
where year = '1974';

#10
select count(name) 'Total Rows In Table' #(10) counts the total rows using name as it is not allowed to be null
from BabyName;

#11
select count(distinct name) 'Different Male Names In 1962'		#(11) counts all the disinct male names in the year 1962
from BabyName
where gender = 'm'
and year = '1962';

#11
select count(distinct name) 'Different Female Names In 1962'		#(11) countsd all the distinct female names in the year 1962
from BabyName		
where gender = 'f'			
and year ='1962';

