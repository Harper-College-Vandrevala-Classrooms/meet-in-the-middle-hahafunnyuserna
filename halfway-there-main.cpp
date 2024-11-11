#include <iostream>     
#include <fstream>    
#include <string>    
#include <vector>

using namespace std;

int calculateMedian(const string &filename)
{
    std::vector<int> group;
    ifstream file(filename); 
    string line;
    int count = 0; 

    if (file.is_open())
    { 
        while (getline(file, line, ','))
        { 
            group.push_back(stoi(line));
            count++;
        }
        count++;


        file.close(); 
    } else {
        cout << "Failed to open the file." << endl; 
        return 0; 
    }

    if (count > 0)
    { 
        if ((count + 1) % 2 == 0)
        {
            return ((group[(count/2) - 1] + group[(count/2)])/2);
        } else {
            return (group[(count/2) - 1]); 
        }
    } else {
        cout << "No numbers found in the file." << endl; 
        return 0; 
    }
}

double calculateMean(const string &filename)
{
    ifstream file(filename); 
    string line;
    double sum = 0; 
    double count = 0; 

    if (file.is_open())
    { 
        while (getline(file, line, ','))
        { 
            sum += stoi(line);
            count++;
        }

        file.close(); 
    } else {
        cout << "Failed to open the file." << endl; 
        return 0; 
    }

    if (count > 0)
    { 
        return (sum / count); 
    } else {
        cout << "No numbers found in the file." << endl; 
        return 0; 
    }
}

int main()
{
    string filename;
    cout << "Please enter the file to search.\n";
    cin >> filename;
 
    double average = calculateMean(filename); 
    cout << "Average: " << average << endl; 

    int median = calculateMedian(filename);
    cout << "Median: " << median << endl;
    return 0; 
}