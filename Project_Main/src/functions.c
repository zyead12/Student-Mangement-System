#include "function_prototype.h"
struct node *head = NULL; // define the head pointer

void add_student(const struct student *const ptr) // to receive student structure in pointer to structure
{

	struct node *link = NULL, *current = NULL;
	link = (struct node*) malloc(sizeof(struct node));
	// assign data of student in node
	if (link == NULL) {
		printf("sorry no memory free to insert that student\n");
		return;
	}
	strcpy(link->data.name, ptr->name);
	link->data.id = ptr->id;
	link->data.age = ptr->age;
	link->data.gba = ptr->gba;

	if (head == NULL) {        // IF LIST EMPTY ADD ELEMNT
		link->next = NULL;
		head = link;
		printf("the student with id = %d added successfully..\n", ptr->id);
		return;
	}
	current = head;
	while (current != NULL) // TO CHECK IF ID EXIST
	{
		if (current->data.id == ptr->id) {
			printf("Sorry This id = %d Is Reserved!\n ", ptr->id);
			return;
		}
		current = current->next;
	}
	current = head;

	while (current->next != NULL) // NO ID EXIST AND NO LIST EXIST
	{
		current = current->next; // to reach last node
	}
	current->next = link;
	link->next = NULL;
	printf("the student with id = %d added successfully..\n", ptr->id);

}
void displayStudents(void) {
	struct node *current = head;
	if (head == NULL) {
		printf("sorry, there is no students yet!\n");
		return;
	}
	printf("Students List : \n");
	while (current != NULL) {

		printf("[ ID : %d , NAME : %s , AGE : %d , GPA : %0.2f  ]\n",
				current->data.id, current->data.name, current->data.age,
				current->data.gba);
		current = current->next;
	}

}
void searchStudentByID(int id) {
	struct node *current = head;
	if (head == NULL) {
		printf("sorry, there is no students yet!\n"); // condition can remove because line 79 same meaning
		return;
	}
	while (current != NULL) {
		if ((current->data.id) == id) {
			printf("Student Found : \n");
			printf("[ ID : %d , NAME : %s , AGE : %d , GPA : %0.2f  ]\n",
					current->data.id, current->data.name, current->data.age,
					current->data.gba);
			return;
		}
		current = current->next;
	}
	printf("sorry,the student has given that id = %d not exist!\n", id);
}
void updateStudentByID(int id) {
	struct node *current = head, *exist = NULL;
	enum SearchState check = NotFound;
	if (head == NULL) {
		printf("sorry, there is no students yet!\n");
		return;
	}
	while (current != NULL) {
		if ((current->data.id) == id) {
			check = Found;
			exist = current;

		}
		current = current->next;
	}
	if (check == Found) {
		printf("Enter The New Details Of Student With ID = %d \n", id);
		update_details_with_id(&(exist->data));
		printf("-----------------------------------------\n");

		printf("Student Details Are Updated Successfully.. \n");
		return;
	} else {
		printf("sorry,the student has given that id = %d not exist!\n", id);
	}

}
float caluclateAvarageGPA(void) {
	float sum = 0, AVR = 0;
	int count = 0;
	struct node *current = head;
	if (head == NULL) {
		return AVR;

	}
	while (current != NULL) {
		count++;
		sum += current->data.gba;
		current = current->next;
	}
	AVR = sum / count;
	return AVR;

}
void searchHighestGPA(void) {
	struct node *current = head, *stumax = NULL; // pointer to student with max GPA
	float max;

	if (head == NULL) {
		printf("sorry, there is no students yet!\n"); // condition can remove because line 79 same meaning
		return;
	}
	max = head->data.gba;
	while (current != NULL) {
		if ((float) current->data.gba > (float) max) {
			max = current->data.gba;
			stumax = current;
		}
		current = current->next;
	}

	printf("[ ID : %d , NAME : %s , AGE : %d , GPA : %0.2f  ]\n",
			stumax->data.id, stumax->data.name, stumax->data.age,
			stumax->data.gba);

// if more than student with highest GPA return last student // under
}

void searchHighestGPA_V2(void) // return all student have max GPA
{
	struct node *current = head;
	float max;

	if (head == NULL) {
		printf("sorry, there is no students yet!\n");
		return;
	}
	max = head->data.gba;
	while (current != NULL) {
		if ((float) current->data.gba > (float) max) {
			max = current->data.gba;

		}
		current = current->next;
	}
	printf("The Information of Highest Student GPA Is : \n");
	current = head;
	while (current != NULL) {
		if ((float) current->data.gba == (float) max) {

			printf("[ ID : %d , NAME : %s , AGE : %d , GPA : %0.2f  ]\n",
					current->data.id, current->data.name, current->data.age,
					current->data.gba);
		}
		current = current->next;
	}

}
void deleteStudent(int id) {
	struct node *current = NULL, *prev = NULL, *deleted = NULL;
	if (head == NULL) {
		printf("sorry, there is no students yet!\n"); // to check list and not acsses adrress 0
		return;
	}
	if (head->data.id == id) {

		deleted = head;
		head = head->next;
		free(deleted);
		printf("Student With ID = %d is deleted successfully..\n ", id);
		return;

	}
	current = head->next;
	prev = head;
	while (current != NULL) {
		if (current->data.id == id) {
			printf("Student With ID = %d is deleted successfully..\n ", id);
			deleted = current;
			prev->next = current->next;
			free(deleted);
			return;
		}
		current = current->next;
		prev = prev->next;
	}
	printf("sorry, the student with that id = %d not found!\n", id);

}
void menu(void) {
	do {
		int choice;
		int id;
		printf("--------------------------------------------\n");
		printf("1-Add Student\n");
		printf("2-Display Student\n");
		printf("3-Search Student By ID\n");
		printf("4-Update Student Information\n");
		printf("5-Delete Student By ID\n");
		printf("6-Calculate average GPA \n");
		printf("7-Search Student With Highest GPA \n");
		printf("8-Exit\n");
		printf("Enter Your Choice : ");

		if (scanf("%d", &choice) != 1) // to check if choices not a number
				{
			while (getchar() != '\n')
				;
			printf("-----------------------------------------\n");
			printf("Invalid input! Please enter a number.\n");

			continue;
		}
		printf("--------------------------------------------\n");
		switch (choice) {
		case AddStudent:
			struct student st;
			input_student_details(&st);
			printf("--------------------------------------------\n");
			add_student(&st);

			break;

		case DisplayStudent:
			displayStudents();
			break;
		case SearchStudentByID:
			printf("Enter The Student ID that You Want to search : ");

			if (scanf("%d", &id) != 1) // to check if choices not a number
					{
				while (getchar() != '\n')
					;
				printf("invalid input please enter valid number..\n");
				continue;
			}
			printf("--------------------------------------------\n");
			searchStudentByID(id);
			break;
		case UpdataStudentInformation:
			printf(
					"Enter The Student ID that You Want to Update His Information : ");
			if (scanf("%d", &id) != 1) // to check if choices not a number
					{
				while (getchar() != '\n')
					;
				printf("invalid input please enter valid number..\n");
				continue;
			}
			printf("--------------------------------------------\n");
			updateStudentByID(id);
			break;
		case DeleteStudentByID:
			printf("Enter The Student ID that You Want to Delete it : ");
			if (scanf("%d", &id) != 1) // to check if choices not a number
					{
				while (getchar() != '\n')
					;
				printf("invalid input please enter valid number..\n");
				continue;
			}
			printf("--------------------------------------------\n");
			deleteStudent(id);
			break;
		case CalculateAvargeGPA:
			printf("Average GPA = %0.2f\n", caluclateAvarageGPA());
			break;
		case SearchStudentWithHighestGPA:

			searchHighestGPA_V2();
			break;
		case Exit:
			deleted_all_list(); // to free all space reserved in heap
			printf("the program will exit! goodbye...");
			return;
		default:
			printf(
					"sorry, not valid number please enter valid number from 1 to 8\n");
		}
	} while (1);

}
void input_student_details(struct student *st) {
	printf("Enter student ID : ");
	while (scanf("%d", &(st->id)) != 1) {

		while (getchar() != '\n')
			;
		printf("-----------------------------------------\n");
		printf("invalid input please enter valid number..\n");
		printf("-----------------------------------------\n");
		printf("Enter student ID : ");
		continue;

	}
	printf("Enter student name : ");
	scanf("%s", st->name);

	printf("Enter student Age : ");
	while (scanf("%d", &(st->age)) != 1) {

		while (getchar() != '\n')
			;
		printf("-----------------------------------------\n");
		printf("invalid input please enter valid number..\n");
		printf("-----------------------------------------\n");
		printf("Enter student Age : ");
		continue;

	}
	printf("Enter student GPA : ");
	while (scanf("%f", &(st->gba)) != 1) {

		while (getchar() != '\n')
			;
		printf("-----------------------------------------\n");
		printf("invalid input please enter valid number..\n");
		printf("-----------------------------------------\n");
		printf("Enter student GPA : ");
		continue;

	}

}
void update_details_with_id(struct student *st) {
	printf("Enter student name : ");
	scanf("%s", st->name);
	printf("Enter student Age : ");
	while (scanf("%d", &(st->age)) != 1) {

		while (getchar() != '\n')
			;
		printf("invalid input please enter valid number..\n");
		printf("Enter student Age : ");
		continue;

	}
	printf("Enter student GPA : ");
	while (scanf("%f", &(st->gba)) != 1) {

		while (getchar() != '\n')
			;
		printf("-----------------------------------------\n");
		printf("invalid input please enter valid number..\n");
		printf("-----------------------------------------\n");
		printf("Enter student GPA : ");
		continue;

	}

}
void deleted_all_list(void) {
	struct node *current = head, *deleted = head;
	while (current != NULL) {
		free(deleted);
		current = current->next;
		deleted = current;
	}
}

