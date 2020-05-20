//#include <iostream>
#include "main.h"

int TAB_SIZE = 7;
int TAB_SHIFT = 5;
int MAX_TAB_SIZE = 1000;

int main()
{
    std::cout << "Lista nr 1" << std::endl << "Zadanie 1" << std::endl;
    v_alloc_table_add_5(TAB_SIZE);

    std::cout << "Zadanie 2" << std::endl;
    int ***table;
    b_alloc_table_2_dim(table, 3, 2);

    std::cout << "Zadanie 3" << std::endl;
    std::cout << "b_dealloc_table_2_dim returns: " << std::boolalpha << b_dealloc_table_2_dim(table, 3, 2) << std::endl;
    return 0;
} // int main()

bool show(int* pi_table, int iSize)
{
    for (int ii = 0; ii < iSize; ii++)
        std::cout << "pi_table[" << ii << "] value is " << pi_table[ii] << " " << std::endl;
    std::cout << std::endl;
    return false;
} //bool show(int* iTable, int iSize)

bool show(int*** pi_table, int iSizeX, int iSizeY)
{
    for (int ix = 0; ix < iSizeX; ix++)
    {
        for (int iy = 0; iy < iSizeY; iy++)
        {
            std::cout << "pi_table[" << ix << "][" << iy << "] value is " << (*pi_table)[ix][iy] << " " << std::endl;
        } //for (int iy = 0; iy < iSizeY; iy++)
        std::cout << std::endl;
    } //for (int ix = 0; ix < iSizeX; ix++)
    return false;
} //bool show(int*** pi_table, int iSizeX, int iSizeY)

void v_alloc_table_add_5(int iSize)
{
    if (iSize <= 0 || iSize > MAX_TAB_SIZE) return;

    int* pi_table;
    pi_table = new int[iSize];

    for (int i = 0; i < iSize; i++)
        pi_table[i] = i + TAB_SHIFT;

    show(pi_table, iSize);

    delete[] pi_table;
} // void v_alloc_table_add_5(int iSize)

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
    if (iSizeX < 1 || iSizeX > MAX_TAB_SIZE) return false;
    if (iSizeY < 1 || iSizeY > MAX_TAB_SIZE) return false;

    piTable[0] = new int*[iSizeX];
    std::cout << "Alokacja tablicy [" << iSizeX << "][" << iSizeY << "]\n";

    for (int ii = 0; ii < iSizeX; ii++)
    {
        piTable[0][ii] = new int[iSizeY];
        for (int ij = 0; ij < iSizeY; ij++)
        {
            (*piTable)[ii][ij] = 1000 * ii + ij;
        } //for (int ii = 0; ii < x; ii++)
    } //for (int ii = 0; ii < x; ii++)

    show(piTable, iSizeX, iSizeY);

    return true;
} //bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
    if (iSizeX < 1 || iSizeX > MAX_TAB_SIZE) return false;
    if (iSizeY < 1 || iSizeY > MAX_TAB_SIZE) return false;

    for (int ii = 0; ii < iSizeX; ii++)
    {
        delete [] (*piTable)[ii];
    } //for (int ii = 0; ii < x; ii++)
    delete [] *piTable;

    return true;
} //bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)

