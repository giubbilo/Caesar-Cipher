#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    int key;
    char exit;
    bool found = false;
    string plain_text, cipher_text;
    
    cout << endl << "Type your message here. Do not write numbers or symbols (space is accepted) ";
    getline(cin, plain_text);
    // Check if there is any number or symbol
    for(char c : plain_text)
    {
        if(!isalpha(c) && !isspace(c))
        {
            cout << "Error! You entered a number or a symbol in the message. Retype the message " << endl;
            getline(cin, plain_text);
        }
    }
    // Key generator
    srand(time(0));
    do
    {
        key = rand() % 26;
    } while (key <= 3); // We do not want an "easy key" so, at least one equal to 4
    // Cipher text
    for(char c : plain_text)
    {   
        if(isalpha(c))
        {
            char cipher_char = c + key;
            if(islower(c))
            {   
                char base_l = 'a';
                cipher_text += static_cast<char>((c - base_l + key) % 26 + base_l);
            }    
                else if (isupper(c))
                {
                    char base_U = 'A';
                    cipher_text += static_cast<char>((c - base_U + key) % 26 + base_U);
                }   
        }
            else 
            {
                cipher_text += c;
            }
    }

    cout << endl << "Plain text is: " << plain_text;
    cout << endl << "Cipher text is: " << cipher_text;
    cout << endl << "Key is: " << key;

    cout << endl << endl << "Press any key and hit enter to continue... ";
    cin >> exit;
    return 0;
}
