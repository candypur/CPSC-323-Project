# CPSC-323-Project

TEAM MEMBERS: Project Group 6
Angela Reyes, Kent Nguyen, Jared Olalde


Project Description: Data Processing Project

# Objective: 
The objective of this project is to develop a
data processing application that reads data from an input
file, processes the data, removes excess space and
comments from the code, tokenizes the remaining code,
and prints the output in a tabular form.

# To-Dos:

1. Write code in the language of your choice to read
data from an input file.

3. Process the data to remove excess space and
comments from the code.

5. Tokenize the remaining code.
6. Print the code after removing excess space and
comments.

7. Tokenize the remaining code and print output in
tabular form.

Example Input:

# This is a sample code
It adds two numbers
def add(a, b):
Add two numbers
result = a + b
return result
Test the function
print(add(5, 3))

Output1 - Code after removing excess space and
comments:

def add(a, b):
result = a + b
return result
print(add(5, 3))

Output2 - Tokenized code in tabular form:

Category           Tokens
Keywords           def, return, print
Identifiers        add, a, b, result
Operators          =, +
Delimiters         (, ), :, ,
Literals           5, 3

*The presented table is just a sample format. Feel free to
choose any preferred format for displaying the
information.

# Project Submission Guidelines:

Group Collaboration:
- This project should be completed in a group of three
members.
- Each group member is required to contribute
actively to the project.

GitHub Repository Submission:
- One designated person from each group should
upload the completed project to a GitHub
repository.
- The GitHub repository should be publicly accessible.

Submission Requirements:
- Include the names of all team members in the
README.md file of the GitHub repository.
- Provide a link to the GitHub repository in the
Canvas submission.

# Collaboration Expectations:
- Collaboration among all team members is essential
for completing the project.
- All team members must actively participate in the
development process, contributing code,
documentation, and other necessary elements.
- Regular communication among team members is
encouraged to discuss project progress, distribute
tasks, and address any issues or challenges
encountered during development.
Evaluation Criteria:
- Contributions from all team members are required
and will be evaluated.
- Marks may be deducted for individuals who do not
actively collaborate or contribute significantly to the
project.
- Commit history on GitHub should reflect
contributions from all team members.
- Code Readability and Structure: 20%
- Implementation of File Reading and Data Processing:
30%
- Removal of Excess Space and Comments: 20%
- Tokenization of Code: 20%
- Output Presentation: 10%

# Submission Deadline:
The project submission deadline is on 31st March 2024. It
is essential to adhere to the specified deadline to avoid
any penalties.

# Academic Dishonesty:
If plagiarism or cheating is detected, a grade of '0' will be
assigned to all members of the team, and the incident
will be reported to the department. Please ensure
honesty in your work.

# Note:
Effective collaboration and communication are critical to
the success of the project. Please ensure all team
members are actively engaged and contribute their fair
share to the project.

# Code for evaluating your project:

Python:
def calculate_sum(a, b):
This function calculates the sum of two numbers
return a + b
Main function
if __name__ == "__main__":
num1 = 10
num2 = 20
Calculate the sum
result = calculate_sum(num1, num2)
Print the result
print("Sum:", result)

C++:
#include <iostream>
using namespace std;
// Function to calculate the sum of two integers
int calculate_sum(int a, int b) {
// This function calculates the sum of two
numbers
return a + b;
}
