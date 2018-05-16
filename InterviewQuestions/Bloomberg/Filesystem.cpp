
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "Filesystem.h"



Directory * pWorkingDir;
Directory * pRoot;

struct Attributes
{
	char * name;
	int permission;
	unsigned int size;
	time_t create;
};


struct Directory
{
	Attributes attr;
	Directory * dirList;
	File * fileList;
	Directory * parent;

	Directory * next;

};

struct File
{
	Attributes attr;
	File * next;

};


void cd(char * folder)
{

	if (!strcmp(folder, "..") && !pWorkingDir->parent)
		return;

	if (!strcmp(folder, "..") && pWorkingDir->parent)
	{
		pWorkingDir = pWorkingDir->parent;
	}
	else
	{

		for (Directory * temp = pWorkingDir->dirList; temp != NULL; temp = temp->next)
		{
			if (!strcmp(temp->attr.name, folder))
			{
				pWorkingDir = temp;
				break;
			}
		}
	}
}

void Rec(Directory * dir)
{
	if (!dir)
		return;

	Rec(dir->parent);
	printf("\\%s", dir->attr.name);

}

void pwd()
{
	Rec(pWorkingDir);
}

void addFolder(char * folder)
{
	if (pWorkingDir)
	{
		Directory * dir = new Directory;
		dir->dirList = NULL;
		dir->fileList = NULL;
		dir->parent = pWorkingDir;
		dir->next = NULL;
		time(&dir->attr.create);
		dir->attr.name = new char[strlen(folder) + 1];
		strcpy(dir->attr.name, folder);
		dir->attr.permission = 0;
		dir->attr.size = 0;

		if (pWorkingDir->dirList == NULL || (strcmp(folder, pWorkingDir->dirList->attr.name) < 0))
		{
			dir->next = pWorkingDir->dirList;
			pWorkingDir->dirList = dir;
		}
		else
		{
			Directory * current = pWorkingDir->dirList;
			while (current->next != NULL && (strcmp(current->next->attr.name, folder) < 0))
			{
				current = current->next;
			}
			dir->next = current->next;
			current->next = dir;
		}
	}
}

void addFile(char * name)
{
	if (name)
	{
		File * file = new File;
		file->next = NULL;

		time(&file->attr.create);
		file->attr.name = new char[strlen(name) + 1];
		strcpy(file->attr.name, name);
		file->attr.permission = 0;
		file->attr.size = 0;
		++pWorkingDir->attr.size;

		if (pWorkingDir->fileList == NULL || (strcmp(name, pWorkingDir->fileList->attr.name) < 0))
		{
			file->next = pWorkingDir->fileList;
			pWorkingDir->fileList = file;
		}
		else
		{
			File * current = pWorkingDir->fileList;
			while (current->next != NULL && (strcmp(current->next->attr.name, name) < 0))
			{
				current = current->next;
			}
			file->next = current->next;
			current->next = file;
		}
	}

}

void print(Directory * dir, int indent)
{
	if (!dir)
		return;

	printf("%*s", indent, "");
	printf("%s\n", dir->attr.name);

	Directory * temp;
	for (temp = dir->dirList; temp; temp = temp->next)
	{
		print(temp, indent + 2);
	}


	File * tempF;
	for (tempF = dir->fileList; tempF; tempF = tempF->next)
	{
		printf("%*s", indent + 2, "");
		printf("%s\n", tempF->attr.name);
	}
}

void printTree()
{
	print(pRoot, 0);
}

void freeMem(Directory * dir)
{
	if (!dir)
		return;

	File * tempF;
	for (tempF = dir->fileList; tempF;)
	{
		File * tempF1;
		tempF1 = tempF;
		tempF = tempF->next;
		delete[] tempF1->attr.name;
		delete tempF1;
	}

	Directory * temp;
	for (temp = dir->dirList; temp;)
	{
		Directory * temp2;
		temp2 = temp;
		freeMem(temp);
		temp = temp->next;
		delete[] temp2->attr.name;
		delete temp2;
	}
}

void fileSystem()
{
	Directory root;
	root.dirList = NULL;
	root.fileList = NULL;
	root.parent = NULL;
	time(&root.attr.create);
	root.next = NULL;

	root.attr.name = new char;
	strcpy(root.attr.name, "");
	root.attr.permission = 0;
	root.attr.size = 0;

	pWorkingDir = pRoot = &root;


	while (1)
	{
		char input[100];
		puts("\n1. Change Directory");
		puts("2. Add Folder");
		puts("3. Add File");
		puts("4. Print FS");
		puts("5. Print Working Directory");
		puts("6. Exit");

		int menu;
		menu = getchar();
		getchar();
		switch (menu)
		{
		case '1':
			puts("Enter Dir");
			gets(input);

			cd(input);
			break;
		case '2':
			puts("Enter Dir");
			gets(input);
			addFolder(input);

			break;
		case '3':
			puts("Enter file");
			gets(input);
			addFile(input);

			break;
		case '4':
			printTree();
			break;
		case '5':
			pwd();
			break;
		case '6':
			freeMem(pRoot);
			return;

		}
	}

}
