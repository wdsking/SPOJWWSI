#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int matrixColumns;
	cin >> matrixColumns;
	int matrixRows;
	cin >> matrixRows;
	
	double* vector = new double[matrixRows];

	double** matrix = new double*[matrixRows];
	for (int i = 0; i < matrixRows; i++)
	{
		matrix[i] = new double[matrixColumns];
	}

	for (int y = 0; y < matrixRows; y++)
	{
		for (int x = 0; x < matrixColumns; x++)
		{
		
			cin >> matrix[y][x];
			
		}
		cin >> vector[y];
		
	}
	double** transposedMatrix = new double*[matrixColumns];
	for (int i = 0; i < matrixColumns; i++)
	{
		transposedMatrix[i] = new double[matrixRows];
	}
	for (int y = 0; y < matrixRows; y++)
	{
		for (int x = 0; x < matrixColumns; x++)
		{

			transposedMatrix[x][y] = matrix[y][x];

		}
		

	}
	double* resultMatrix = new double[matrixColumns] {};

	for (int x = 0; x < matrixColumns; x++)
	{
		for (int y = 0; y < matrixRows; y++)
		{
			resultMatrix[x] += transposedMatrix[x][y] * vector[y];
		}
		printf("%.7g ", resultMatrix[x]);
		
	}
	for (int i = 0; i < matrixRows; i++)
	{
		delete[] matrix[i];
	}
	for (int i = 0; i < matrixColumns; i++)
	{
		delete[] transposedMatrix[i];
	}

	delete[] matrix;
	delete[] transposedMatrix;
	delete[] resultMatrix;
	delete[] vector;

	return 0;
}