#Pset 5 : speller

##Project
The challenge ahead of you is to implement the fastest spell checker you can!
By "fastest," though, we’re talking actual, real-world, noticeable time—none of that
asymptotic stuff this time.

##TODO

In dictionary.c we have to implement 4 functions -
1. *load* : Load the dictionary from the txt file, using hashfunction.
2. *check* : We have to check whether the supplied word is in the dictionary or not.
3. *size* : It returns the number of words in the dictionary if loaded else 0.
4. *unload* : It unloads the dictionary and return true if successful else return false.

We can implement the dictionary by linked list and hashtable. For every word, it will be hashed 
to get the index of the hashtable. Hashtable will be a collection of linkedlist.