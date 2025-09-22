#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countLines(string& filePath, vector<string>& acii) { //declares as refrences to not make another copy
    ifstream file(filePath); // opesn the file
    int count = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) { // gets the line from file while in loop
            count++;
            cout << line << "   :    " << count << endl;
            acii.push_back(line); // adds to vector
        }
    }
    else {
        cerr << "Error opening the file";
        return 1; // indicates error
    }
    file.close();
    return count;
}

void writeLine(string& filePath, string& htmlB, vector<string>& acii, int& count) {
    ofstream file(filePath, ios::out | ios::trunc); // declares output and clears the file
    cout << "cleared" << endl;
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            string concat = acii[i] + htmlB; // concats 
            cout << concat << endl;
            file << concat << endl; // writes to file
        }
    }
    else {
        cerr << "Error opening the file";
    }
    file.close();
}

void reverseAcii(vector<string>& acii, int& count, vector<string>& reversedAcii) {
    for(int i = 0; i < count; i++) {
        reversedAcii.push_back(acii[count - 1 - i]); // adds to vector in reverse order
	}
	cout << "Reversed Acii:" << endl;
}

int main()
{
    // vars
    string htmlB = "<br>";
    string filePath = "input.txt";
    string fileAcii = "output.txt";
	string reversedFileAcii = "reversedOutput.txt";
    vector<string> acii;
	vector<string> reversedAcii;

    //functions
    int count = countLines(filePath, acii);
	reverseAcii(acii, count, reversedAcii);
    writeLine(fileAcii, htmlB, acii, count);
    writeLine(reversedFileAcii, htmlB, reversedAcii, count);


    return 0; // end of program
}
