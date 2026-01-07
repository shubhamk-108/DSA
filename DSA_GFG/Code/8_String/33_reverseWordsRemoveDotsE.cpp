#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include <stack>
string reverseWords(string &str)
{
    reverse(str.begin(), str.end());

    int n = str.length();

    int write = 0;
    int start = 0;
    int end = 0;

    for (start; start < n; start++)
    {
        if (str[start] != '.')
        {
            if (write != 0)
            {
                str[write] = '.';
                write++;
            }
            end = start;
        
            while (end < n && str[end] != '.')
            {
                str[write] = str[end];
                write++; 
                end++;
            }
            reverse(str.begin() + write - (end - start), str.begin() + write);
            
            start = end;
        }        
    }

    str.erase(str.begin() + write, str.end());
    return str;
}

int main()
{
    string str = "....i.like.this...program.very....much....";
    cout << reverseWords(str);
    return 0;
}

// time space

/*
time: O(n)
space: O(1)

*/

// logic

/*

string reverseWords(string &str)
{
    // reverse the whole string
    reverse(str.begin(), str.end());

    int n = str.length();

    // write ptr will write in the same string (in place). This write pointer will build the string withou dots. It will ignore all the dots
    // and we explicitely place dot when we hit the end of word character.
    int write = 0;
    // start ptr will traverse inside loop like we usually do with i ptr. And it also denotes start of the word.
    int start = 0;
    // end pointer will find end of the word and while doing so it also do in place copy from one location to another.
    int end = 0;

    for (start; start < n; start++)
    {
        if (str[start] != '.')
        {
            // below if explanation in below to below while loop. It is about adding dot after each word and not before very first worf
            // that is at index 0.
            if (write != 0)
            {
                str[write] = '.';
                write++;
            }
            // we found start of word. thus initially end and start both at same idx then we increment end to find end of that word.
            end = start;
            // not equal to dot is above condition. Means it is the character and we are at the start of the character.
            // Now find end of word. If we encounter next dot that means it is the end of previous word and start of new word.
            while (end < n && str[end] != '.')
            {
                // if there are no dots prior to character. Ex : str = "shubham" then write, start and end all ptr are at 0.
                // so we are replacing here write ptr with end ptr. so s will be replaced by s itself and we increment write and end ptr.
                // then h will be replaced by h and so on for here onwards.

                // Now if there were trailing dots prior to that word. Ex: ...shubham. then write, start and end all ptr are at 0.
                // But when we see char like  if(str[start] != '.') then only we proceed. Means for dots we do nothing and just increment start ptr.
                // And when we found the char means it is the start of the word. Now increment end pointer and go to the end of the word
                // While doing so assign each char to the write index. Because start and end are traversing on messy string(which has lots of dots).
                // and write ptr is building string without multiple dots.
                // that ...shubham.. example above: for dots we will increment start. so start at idx 3. idex 3, it saw char. start of word.
                // write is waiting at index 0. Now end = start. That is write = index 0, start = index 3 and end = index 3.
                // Now str[write] = str[end]. means index 3rd s come at idx 0 where earlier was dot there. increment both write and end.
                // now write = idx 1 and end = idx 4. so h will go to 1st index where there was 2nd dot earlier. and increment both again.
                // we do this till we find next dot. And that means it is the end of the word and start of new word. So now start becomes end
                // that is start = end. and we again do same for the next word.
                // Now we do it for next word, before that we put dot there. so at the before this while loop add dot in str[write] and write++.
                // Just check before adding dot that is it the first index. because there should not be dot before very first word.
                str[write] = str[end];
                write++;
                end++;
            }
             // reverese that individual word.
            // How i calculated these indices. First calculate ending ptr. whereever is write pointer waiting that will be the end of that word.
            // and for the begin ptr: take the end pointer and subtract the length of the current word from that. How to get length : length is 
            // end - start ptr. So ending ptr is str.begin() + write. subtract length from that for begin ptr. (str.begin() + write - (end - start)
            reverse(str.begin() + write - (end - start), str.begin() + write);
            

            // Now we finished with that previous word. Now wherever we finished we will begin from the same word for the next word.
            // that is end of previous word is start of next word.
            start = end;
        }
       
    }
    //erase traling zeros due to we shifter characters to the left side so there is a possibility that there may be some dots at the very end.
    // to erase the very last characters is not the O(n) operation. It is O(1) because we do not need to shift chars to the left because we are 
    deleting last chars.
    str.erase(str.begin() + write, str.end());
    return str;
}




*/