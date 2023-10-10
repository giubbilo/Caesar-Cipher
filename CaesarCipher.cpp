#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    int key;
    char exit;
    bool found = false;
    string plain_text, cipher_text;
    
    cout << endl << "Type your message here: ";
    getline(cin, plain_text);

    auto currentTime = chrono::high_resolution_clock::now().time_since_epoch();
    // Convert the duration to a seed value
    unsigned seed = static_cast<unsigned>(currentTime.count());
    // Create a random number generator with the current time as the seed
    default_random_engine rng(seed);
    // Create a distribution, for example, to generate random integers between 1 and 100
    uniform_int_distribution<int> distribution(1, 4096);
    
    do
    {
        key = distribution(rng) % 26;
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
