#include <iostream> 
#include <vector> 
#include <string>


void printVector(std::vector<int> vector){
    for (int n : vector){
        std::cout << n;
    } 
}


std::vector<int> toBinary(int number){
    int workingNum = number; 
    std::vector<int> result;

    while (workingNum >= 1){
        if (workingNum % 2 == 0){
            result.insert(result.begin(), 0);
        } else if (workingNum % 2 == 1){
            result.insert(result.begin(), 1);
        }
        workingNum = workingNum / 2;

    }
    return(result);
}


std::vector<int> toBinaryPoint (double number){
    int leftNum = (int)number;
    double rightNum = number - leftNum;

    std::vector<int> left = toBinary(leftNum);
    std::vector<int> right;

    while(rightNum != 0.0){
        rightNum = rightNum * 2; 

        if (rightNum >= 1.0){
            right.push_back(1);
            rightNum -= 1.0;
        } else {
            right.push_back(0);

        }
    } 
    std::cout << "Binary Result for " << number << " is: "; 
    printVector(left);
    std::cout << '.' ; 
    printVector(right);
    std::cout << std::endl; 
    return right; 
}


void runProg(){
    std::string num; 
    std::cout << "Enter number to convert: ";
    std::cin >> num;
    std::vector<int> result;

    if (num.find('.') != std::string::npos){ 
        double numDouble = std::stod(num);
        toBinaryPoint(numDouble);
    } else {
        int numInt = std::stoi(num);
        result = toBinary(numInt);
        std::cout << "Binary Result for " << num << " is: ";
        printVector(result);
    }

}


int main(){
    runProg();
    return 0;
}