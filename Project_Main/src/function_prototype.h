/*
 * function_prototype.h
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCTION_PROTOTYPE_H_
#define FUNCTION_PROTOTYPE_H_
struct student {
	int id;
	char name[30];
	int age;
	float gba;
};
struct node {
	struct student data;
	struct node *next;
};
enum SearchState {
	NotFound, Found
};
enum choices {
	AddStudent = 1,
	DisplayStudent,
	SearchStudentByID,
	UpdataStudentInformation,
	DeleteStudentByID,
	CalculateAvargeGPA,
	SearchStudentWithHighestGPA,
	Exit
};

void add_student(const struct student *const ptr);        //To Add New Student
void displayStudents(void);                              // To Display All Students Information
void searchStudentByID(int id);                         // To Search Student By ID
void updateStudentByID(int id);                        // To UPdate Student Information By ID
float caluclateAvarageGPA(void);                      // To Display Average GPA For ALL  Students
void searchHighestGPA(void);                         // return last student only with high GPA (if high GPA is repeated)
void searchHighestGPA_V2(void);                     //return all student  with high GPA (if high GPA is repeated)
void deleteStudent(int id);                        // To Delete Student By ID
void input_student_details(struct student *st);   // To take New Student Information
void update_details_with_id(struct student *st); // To Take Updated Student Information
void menu(void);                                // To Display MENU
void deleted_all_list(void);                   // To Deleted ALL Space Reserved In Memory After Exit

#endif /* FUNCTION_PROTOTYPE_H_ */
