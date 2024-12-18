#include <iostream>
#include <algorithm>    //adds algorithms like (std::for_each, std::sort, std::remove_if, std:reverse, etc.)
#include <functional>   //adds functionals like (std::plus, std::minus, std::greater, std::equal_to, etc.)
#include <numeric>      //adds numerics like (std::accumulate, std::reduce, std::inner_product, std::partial_sum, etc. 
#include <vector>

int main() 
{
    std::cout << "~~~~~~~~~~ Colours 1 ~~~~~~~~~~" << std::endl;
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)

    std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

    std::vector<std::string> before_purple;
    std::vector<std::string> after_purple;

    //resize result vectors to the same size as the input vector
    before_purple.resize(colours.size());
    after_purple.resize(colours.size());

    auto it = std::partition_copy(colours.begin(), colours.end(), before_purple.begin(), after_purple.begin(), [](const std::string& colour) 
        { 
            return colour < "purple"; 
        }
    );

    //resize the result vectors for memory cleanup
    before_purple.resize(std::distance(before_purple.begin(), it.first));
    after_purple.resize(std::distance(after_purple.begin(), it.second));

    //print the results
    std::cout << "Strings before 'purple': ";
    for (const auto& colour : before_purple) 
    {
        std::cout << colour << ", ";
    }
    std::cout << std::endl;

    std::cout << "Strings after 'purple': ";
    for (const auto& colour : after_purple) 
    {
        std::cout << colour << ", ";
    }
    std::cout << std::endl;
    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na

    std::cout << "~~~~~~~~~~ Colours 2 ~~~~~~~~~~" << std::endl;
    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

        //convert each string in the vector to uppercase
        for (std::string& colour : colours) 
        {
            std::transform(colour.begin(), colour.end(), colour.begin(), [](unsigned char c) 
                { 
                    //returns the word to uppercase
                    return std::toupper(c); 
                });
        }

        //print the modified vector
        std::cout << "Uppercase strings: ";
        for (const auto& colour : colours) 
        {
            std::cout << colour << " ";
        }
        std::cout << std::endl;
        // 2) alle elementen UPPERCASE te maken.
    }

    std::cout << "~~~~~~~~~~ Colours 3 ~~~~~~~~~~" << std::endl;
    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

        //sort list for std::unique
        std::sort(colours.begin(), colours.end());

        //std::unique checks duplicates conmsecutive thats why we had to sort before first
        auto new_end = std::unique(colours.begin(), colours.end());

        //erase the 
        colours.erase(new_end, colours.end());
        std::cout << "Unique colours: ";
        for (const auto& colour : colours) 
        {
            std::cout << colour << " ";
        }
        std::cout << std::endl;
        // 3) alle dubbele te verwijderen
    }

    std::cout << "~~~~~~~~~~ Numbers 1 ~~~~~~~~~~" << std::endl;
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](double num) 
            {
                return num < 0; 
            }), numbers.end());

        std::cout << "Numbers after numbers.erase(): ";
        for (double num : numbers)
        {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
        // 1) alle negatieve elementen te verwijderen
    }

    std::cout << "~~~~~~~~~~ Numbers 2 ~~~~~~~~~~" << std::endl;
    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

        std::for_each(numbers.begin(), numbers.end(), [](double number) 
        {
            // % cannot be used on a double in C++.... WHY NOT? ugh fine i'll do a cast for int
            int intNumber = static_cast<int>(number);
            std::cout << number << " is " << ((intNumber % 2 == 0) ? "even" : "odd") << std::endl;
        });
        // 2) voor alle elementen te bepalen of ze even of oneven zijn
    }

    std::cout << "~~~~~~~~~~ Numbers 3 ~~~~~~~~~~" << std::endl;
    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

        //sum
        double sumResult = std::accumulate(numbers.begin(), numbers.end(), 0.0);
        std::cout << "Sum Result: " << sumResult << std::endl;

        //average
        double averageResult = sumResult / numbers.size();
        std::cout << "Average Result: " << averageResult << std::endl;

        //product
        double productResult = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());
        std::cout << "Product Result: " << productResult << std::endl;
        // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    }

    return 0;
}