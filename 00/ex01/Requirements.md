# Make a PhoneBook

## Two Classes:
### PhoneBook 
- array of contacts; Maximum 8 contacts; if 9th contact replace oldest one by the new one. Not dynamically allocated
### Contact
- Private - anything that will always be used inside a class is private and anything that can be used outside a class is public

### Program Design
At startup program is empty; the program only accepts ADD, SEARCH, EXIT
ADD- save new contact, add fields one at a time, cannot save contact that is empty.
SEARCH - display a specific contact, 4 columns - index, first name, last name, nickname. Each column is 10 characters wide, text right aligned, truncate and the last displayable character must be replaced by a dot
EXIT - Program quits and the contacts are lost forever
Any other input is discarded


### References
https://cplusplus.com/reference/iomanip/setw/
https://cplusplus.com/reference/string/string/
