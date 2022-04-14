 #include "wordcounter.h"   //file holding hash table class, necessary functions, the wordcount struct, and other necessary header files.


int main()
{

HT words;   //hashtable of words.
ifstream is;
string line;        //string holding line taken from input file.
string filename;    //name of input file.

cout <<"Enter your filename: ";
getline(cin, filename);

is.open(filename);
if(is.fail())       //if could not open file for any reason abort attempt.
{
    cout << "Error, could not open file. Aborting now\n";
    exit(3);
}
cout <<"Reading...\n\n";
while(!is.eof())        //reads file line by line.
{
    getline(is, line);
    words.processline(line);   //calls on processline to break line into words to put into the hash table.
}
is.close();                //close file when done with it.

words.printtable();         //print table.


    return 0;
}

HT ::HT()   //constructor
{
    words.resize(tblsize);  //sets table size.

}

void HT :: processline(string &s)       //processes the string passed in and breaks it down into individual words while removing punctuation.
{
    string::iterator it1, it2;  //iterators to be set at eh beginning of a word, and after the last character in a word to use assign() with.
    string temp;     //a temporary string to be set to a individual word so that it can be searched for within the hash table.
    locale loc;     //locale variable so isalpha() can be used.

    it1=s.begin();
    it2=s.begin();


    while(it1!=s.end())     //Until the end of the passed in string,Which is a whole line of the file.
    {   int signal=0;       //for signalling if the counter was incremented
        if(isalpha(*it2, loc))//checks for letter and incriments if is.
        {
            it2++;
        }
        else    //if not checks if space or punctuation
        {
            if(*it2==' ')   //if is space
            {
                temp.assign(it1,it2);   //assigns word value to temp
                cout <<temp<<" ";       //prints the contents of the file without punctuation.

                int index =hashfunc(temp); //gets the hashvalue
                if(words[index].size()==0)  //if list at that hash value is empty, just push front.
                {
                   wordcount NEW;
                   NEW.word =temp;
                   NEW.counter=1;   //set counter to 1.
                   words[index].push_front(NEW);
                   wordcount *p;
                   p=&words[index].front();
                   vp.push_back(p);

                   it2++;   //incriment passed the space to the next word
                   it1=it2; //set
                }
                else
                {
                   list<wordcount>:: iterator it =words[index].begin();
                   while(it!=words[index].end())    //until it hits the end of the list.
                   {
                       if(temp == it->word)         //if match found incriment counter and set signal to 1
                        {
                        it->counter++;
                        signal =1;      //signal for skipping insertion in case of duplicate for.
                        it2++;
                        it1=it2;
                        break;      //if found don't bother continuing the search and break

                        }
                       else     //otherwise move to the next member of the list.
                        it++;
                   }
                   if(signal ==0)   //if signal set to 0, make a new member of list at the end.
                   {
                        wordcount NEW;
                        NEW.word =temp;
                        NEW.counter=1;
                        words[index].insert(words[index].end(),NEW);    //insert at end then incriment
                        wordcount *p;
                        p=&words[index].back();
                        vp.push_back(p);
                        it1=it2;
                        it2++;
                   }
                }


            }
            else        //if it2 is not pointing to a space, find out if its end of line, or punctuation.
            {

                temp.assign(it1,it2);//assigns word value to temp
                if(it2!=s.end())   //if not end of line, skip over the punctuation and add remaining letters if any.
                {
                    string::iterator it3=it2;       //set it3 equal to it2.
                    it3++;
                    while(*it3!=' ' && it3!=s.end())    //until it hits a space, or end of line, check if any letters remain and push onto temp.
                    {
                        if(isalpha(*it3, loc))
                        {
                            temp.push_back(*it3);
                            it3++;

                        }
                        else
                            it3++;  //otherwise skip over char.
                    }
                }


                cout <<temp<<" ";   //prints the contents of the file without punctuation.
                int index =hashfunc(temp);      //sets hashvalue.
                list<wordcount>:: iterator it =words[index].begin();
                while(it!=words[index].end())   //until end of list, look for duplicate words.
                   {
                       if(temp == it->word)
                        {
                        it->counter++;
                        signal =1;  //if found set signal to 1 and break.
                        break;
                        }
                       else         //else keep moving through list.
                        it++;
                   }
                   if(signal ==0)   //if signal is equal to zero insert at end of list
                   {
                        wordcount NEW;
                        NEW.word =temp;
                        NEW.counter=1;
                        words[index].insert(words[index].end(),NEW);    //insert new word at end of list
                        wordcount *p;
                        p=&words[index].front();
                        vp.push_back(p);
                   }
                while(*it2!=' '&& it2!=s.end())
                {
                    it2++;
                }
                if(it2!=s.end())
                    it2++;
                it1=it2;

            }
        }

    }
cout <<endl;    //provides end of line in print out of file without
}

void HT :: printtable()
{
list<wordcount>::iterator it;
cout << "\n\n\tword:\t\tcount\n---------------------------------------\n";

for(int i=0; i<tblsize;i++)
{
    it =words[i].begin();
    while(it!= words[i].end())
    {
        cout <<"in slot"<<i<< "\t" << it->word << "\t\t" << it->counter << endl;
        it++;
    }
}
cout <<"\tordered list\n\t------------------\n";
for(int i=0; i<vp.size();i++)
{
        cout << "\t" << vp[i]->word << "\t\t" << vp[i]->counter << endl;
}
}


int HT:: hashfunc(string &s)
{

    int hashval=0;
    for(char ch:s)      //for every char in the string.
    {
        hashval= 5 * hashval + ch;
    }

    return hashval%tblsize;
}
