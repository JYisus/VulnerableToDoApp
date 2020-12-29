/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  28/12/2020 12:59:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define TASKS_LIMIT 10

typedef struct {
	char text[256];
	int completed;
}Task;

void printHelp()
{
	system("clear");
	printf("To do list options:\n");
	printf("\t· Write anything to add a new task\n");
	printf("\t· \\h to print help\n");
	printf("\t· \\c and a task ID to complete it\n");
	printf("\t· \\d and a task ID to delete it\n");
	printf("\t· \\q to quit\n");
	printf("Press any key to continue\n");
	getchar();
}

void printTasks(int numberOfTasks, Task tasks[TASKS_LIMIT])
{
	system("clear");
	printf("To Do List\n");

	for(int i = 0; i < numberOfTasks; ++i)
	{
		char completed = ' ';
		if (tasks[i].completed == TRUE)
		{
			completed = 'x';
		}
		printf("%d. [%c]  %s\n",i+1, completed, tasks[i].text);
	}
}

char* inputTask()
{
	char task[256];
	printf("\\h: Help\t\\c: Complete\t\\d: Delete\t\\q: Close\n\n");
	printf("> ");
	gets(task);
	return task;
}

int getTaskNumber(char* taskInput)
{
	char character;
	int i,digit,number = 0;

	for(i=0; i < strlen(taskInput); ++i)
	{
		character = taskInput[i];
		if(character >= '0' && character <= '9')
		{
			digit = character - '0';
			number = number*10 + digit;

		}
	}

	return number;
}

int deleteTask(int numberOfTasks, Task tasks[TASKS_LIMIT], int taskToDelete)
{
	if(taskToDelete <= 0 || taskToDelete > numberOfTasks)
	{
		printf("Task with ID %d doesn't exist\n",taskToDelete);
		return FALSE;
	}

	int i;
	for(i = taskToDelete-1; i < numberOfTasks-1; ++i)
	{
		/* strcpy(tasks[i], tasks[i+1]); */
		tasks[i] = tasks[i+1];
	}

	return TRUE;
}

void completeTask(int numberOfTasks, Task tasks[TASKS_LIMIT], int taskToComplete)
{
	if(taskToComplete <= 0 || taskToComplete > numberOfTasks)
	{
		printf("Task with ID %d doesn't exist\n", taskToComplete);
		return;
	}

	tasks[taskToComplete-1].completed = TRUE;

}

int main(int argc, char **argv)
{

	int numberOfTasks = 0;
	/* char tasks[10][256]; */

	while(1)
	{
		Task tasks[TASKS_LIMIT];
		printTasks(numberOfTasks, tasks);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		if(numberOfTasks == 10) {
			printf("Reached limit of tasks\n");
		}

		char *newTask = inputTask();

		if(strcmp(newTask, "\\q") == 0)
		{
			return 0;
		}

		if(strncmp(newTask, "\\h",2) == 0)
		{
			printHelp();
			continue;
		}

		if(strncmp(newTask, "\\d",2) == 0)
		{
			int taskToDelete = getTaskNumber(newTask);
			int isDeleted = deleteTask(numberOfTasks, tasks, taskToDelete);
			if (isDeleted) {
				--numberOfTasks;
			}
			printTasks(numberOfTasks, tasks);
			continue;
		}

		if(strncmp(newTask, "\\c",2) == 0)
		{
			int taskToComplete = getTaskNumber(newTask);
			completeTask(numberOfTasks, tasks, taskToComplete);
			printTasks(numberOfTasks, tasks);
			continue;
		}

		if(numberOfTasks == TASKS_LIMIT) {
			continue;
		}

		strcpy(tasks[numberOfTasks].text, newTask);
		tasks[numberOfTasks].completed = FALSE;
		++numberOfTasks;


	}

}
