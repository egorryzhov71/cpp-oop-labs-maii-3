#include "/workspaces/C++/include/fivee.h"
#include <iostream>

int main(){
    try{
        Five num1("3");    
        Five num2("10");   
        Five num3("123");   
        Five num4("44444");  
        
        std::cout << "3: " << num1.tostring() << std::endl;
        std::cout << "10: " << num2.tostring() << std::endl; 
        std::cout << "123: " << num3.tostring() << std::endl;
        std::cout << "44444: " << num4.tostring() << std::endl;
        
        Five sum = num1.plus(num2);
        std::cout << "3 + 10 = " << sum.tostring() << std::endl;

    } catch (const std::exception& e){
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}