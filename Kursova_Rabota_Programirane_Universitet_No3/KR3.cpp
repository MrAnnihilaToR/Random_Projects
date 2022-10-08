/*Да се дефинира клас Matrica с m реда и n колони,
(който реализира матрица от реални числа) с член – данни с частен достъп,
като размерностите са статични, с подразбиращ се конструктор,
който нулира елементите на матрицата, конструктор,който подава матрица,
деструктор, който съобщава за унищожаване на обект,
методи за: намиране на максимален елемент на матрица,
извеждане на матрица и изчисляване
на сумата от елементите на матрицата.
Да се разработят приятелски функции на класа за
поелементно събиране и изваждане на матрици.
Да се тества класът, като се създадат матрици M1, M2 и M3,
като M1 се създаде с подразбиращия се конструктор, а другите
се въвеждат от клавиатурата.
Главната функция, в която се създават и обработват обектите
да не е приятелска за класа.
*/

#include <iostream>

using namespace std;


class Matrica
{
    string arrName;   //// Variable for name of array
    static int mbr, nbr;     //mbr=number of rows ; nbr=number of columns
    float** v;      //pointer to array of pointers (2D Dynamic Array)
public:
    static void setMrows(int rows)
    {
        mbr = rows; /// setter to set a value from main variable to private Matrica variable 
    }
    int getMrows()
    {
        return mbr; //// Getter just in case if the value of mbr is needed at location with restricted access
    }

    static void setNcols(int cols)
    {
        nbr = cols; /// setter to set a value from main variable to private Matrica variable 
    }
    int getNcols()
    {
        return nbr; //// Getter just in case if the value of nbr is needed at location with restricted access
    }

    void setName(string name)
    {
        arrName = name ; /// setting arrName to inputted parameter from main function
    }
    string getName()
    {
        return arrName; //getter for array's name
    }

    /// ////////////////////////

    Matrica(); //default constructor which gives 0s for the elements
    Matrica(int m, int n);  //constructor with parameters for rows and columns
    Matrica(const Matrica& from); //copy constructor, which is passing matrice by a Matrica variable reference
    ~Matrica();    //Destructor
    /// ///////////////Input&Output function for every Matrica variable
    void in();
    void out();
    //////// Max Element & Sum of Elements methods for every Matrica variable
    void maxElement();
    void sumElements();
    //////////////////////////////////Friend functions , involving summing and subtracting arrays,but using references to Matrica variables
    friend void MatrixAdd(Matrica& a, Matrica& b);    /////prototype friend function
    friend void MatrixSubtract(Matrica& a, Matrica& b);    /////prototype friend function

};


/// ///////// Declaring mbr,nbr variables from here ,because they are static and they are in private and if we don't declare them here we get error of the type : unresolved external symbol for the 2 private variables:|
int Matrica::mbr;
int Matrica::nbr;
/// //////////

Matrica::Matrica()
{
    v = new float* [mbr];  //////Allocating dynamic memory for the array
    for (int i = 0; i < mbr; i++)
    {
        v[i] = new float[nbr];
    }
    /// ////////
    for (int i = 0; i < mbr; i++)
    {
        for (int j = 0; j < nbr; j++)
        {
            v[i][j] = 0;
        }
    }


}
Matrica::Matrica(int m, int n)
{
    v = new float* [mbr = m];  //////Allocating dynamic memory for the array
    for (int i = 0; i < m; i++)
    {
        v[i] = new float[nbr = n];
    }
}
Matrica::Matrica(const Matrica& from)
{
    v = new float* [from.mbr];     //Allocating dynamic memory for the array
    if (!v) exit(1);          // Action if there is no memory for the array "v"
    for (int i = 0; i < from.mbr; i++)
    {
        v[i] = new float[from.nbr];
    }
    for (int i = 0; i < from.mbr; i++)
    {
        for (int j = 0; j < from.nbr; j++)
        {
            v[i][j] = from.v[i][j];
            cout << "CopiedElement[" << i << "][" << j << "] = " << v[i][j] << "\n"; //copied elements from "from"
        }
    }
    mbr = from.mbr;
    nbr = from.nbr;
    cout << endl;
}
Matrica::~Matrica()
{
    cout << "Ooooh no , a matrice has been destroyed ! " << endl;
    for (int i = 0; i < mbr; i++) ///////Deallocating a dynamic memory
    {
        delete v[i];
    }
    delete[]v;

}
void Matrica::in()
{
    for (int i = 0; i < mbr; i++)
    {
        for (int j = 0; j < nbr; j++)
        {
            cout << getName()<<"[" << i << "][" << j << "] = ";
            cin >> v[i][j];
            cout << "\n";

        }
    }
}
void Matrica::out()
{
    for (int i = 0; i < mbr; i++)
    {
        for (int j = 0; j < nbr; j++)
        {
            if (j == nbr - 1)
            {
                cout << v[i][j] << "|" << "\n";
            }
            else
            {
                cout << v[i][j] << "|";
            }

        }
    }
    cout << endl;
}
void Matrica::maxElement()
{
    float maxElement;
    maxElement = v[0][0];
    for (int i = 0; i < mbr; i++)
    {
        for (int j = 0; j < nbr; j++)
        {

            if (maxElement < v[i][j])
            {
                maxElement = v[i][j];
            }
        }
    }
    cout << "The element with maximum value of this particular array is : " << maxElement << endl;
}
void Matrica::sumElements()
{
    float sumEls = 0;
    for (int i = 0; i < mbr; i++)
    {
        for (int j = 0; j < nbr; j++)
        {
            sumEls = sumEls + v[i][j];
        }
    }
    cout << "Sum of Elements for this particular Array is : " << sumEls << endl;
}

/////////Friend Functions/////////////
void MatrixAdd(Matrica& a, Matrica& b)
{
    float** result = new float* [a.mbr];
    for (int i = 0; i < a.mbr; i++)
    {
        result[i] = new float[a.nbr];
    }

    if (a.mbr == b.mbr && a.nbr == b.nbr)
    {
        for (int i = 0; i < a.mbr; i++)
        {
            for (int j = 0; j < a.nbr; j++)
            {
                result[i][j] = a.v[i][j] + b.v[i][j];
            }
        }
        //Displaying the result array which is the requested summed array (result[i][j] = a.v[i][j] + b.v[i][j];)
        for (int i = 0; i < a.mbr; i++)
        {
            for (int j = 0; j < a.nbr; j++)
            {
                cout << "|" << result[i][j] << "|";
            }
            cout << endl;
        }
    }
    else
        cout << "Invalid Matrix Addition Occurs as size differs\n";
}
void MatrixSubtract(Matrica& a, Matrica& b)
{
    float** result = new float* [a.mbr];
    for (int i = 0; i < a.mbr; i++)
    {
        result[i] = new float[a.nbr];
    }

    if (a.mbr == b.mbr && a.nbr == b.nbr)
    {
        for (int i = 0; i < a.mbr; i++)
        {
            for (int j = 0; j < a.nbr; j++)
            {
                result[i][j] = a.v[i][j] - b.v[i][j];
            }
        }
        //Displaying the result array which is the requested subtracted array (result[i][j] = a.v[i][j] - b.v[i][j];)
        for (int i = 0; i < a.mbr; i++)
        {
            for (int j = 0; j < a.nbr; j++)
            {
                cout << "|" << result[i][j] << "|";
            }
            cout << endl;
        }
    }
    else
        cout << "Invalid Matrix Addition Occurs as size differs\n";
}



void main()
{
    int m1, n1;
    do {
        cout << "PLEASE ENTER CONSTANT NUMBER OF ROWS : ";
        cin >> m1;
    } while (1 > m1 > 1000);

    do {
        cout << "PLEASE ENTER CONSTANT NUMBER OF COLUMNS : ";
        cin >> n1;
    } while (1 > n1 > 1000);

    Matrica::setMrows(m1);
    Matrica::setNcols(n1);

   
    Matrica tab;
    tab.setName("M1");
    cout << endl;
    cout << "MATRICE "<<tab.getName()<<" - DEFAULT CONSTRUCTOR !" << endl;
    cout << endl;
    tab.out();
    tab.maxElement();
    tab.sumElements();
    cout << endl;

    
    Matrica tab2(m1, n1);
    tab2.setName("M2");
    cout << endl;
    cout << "MATRICE " << tab2.getName() << " - MATRICE WITH CONSTRUCTOR WITH INPUTTED ROWS AND COLS WITH INPUTING THE VALUES FOR ELEMENTS !" << endl;
    cout << endl;
    tab2.in();
    tab2.out();
    tab2.maxElement();
    tab2.sumElements();



    cout << endl;
    Matrica tab3(m1, n1);
    tab3.setName("M3");
    cout << endl;
    cout << "MATRICE " << tab3.getName() << " - MATRICE WITH INPUTTED ROWS AND COLS CONSTRUCTOR WITH INPUTTED VALUES FOR ELEMENTS !" << endl;
    cout << endl;
    tab3.in();
    tab3.out();
    tab3.maxElement();
    tab3.sumElements();

    cout << endl;
    cout << "COPY OF MATRICE M3 = NEW MATRICE M4 WITH COPY CONSTRUCTOR!!!!!" << endl;

    Matrica tab4(tab3);
    tab4.setName("M4");
    cout << endl;
    cout << "MATRICE " << tab4.getName() << " - COPIED MATRICE WITH COPY CONSTRUCTOR !" << endl;
    cout << endl;
    tab4.out();
    tab4.maxElement();
    tab4.sumElements();

    cout << endl;
    Matrica tab5(m1, n1);
    tab5.setName("M5");
    cout << endl;
    cout << "MATRICE " << tab5.getName() << " - MATRICE WITH INPUTTED ROWS AND COLS CONSTRUCTOR WITH INPUTTED VALUES FOR ELEMENTS !" << endl;
    cout << endl;
    tab5.in();
    tab5.out();
    tab5.maxElement();
    tab5.sumElements();

    cout << endl;
    Matrica tab6(m1, n1);
    tab6.setName("M6");
    cout << endl;
    cout << "MATRICE " << tab6.getName() << " - MATRICE WITH INPUTTED ROWS AND COLS CONSTRUCTOR WITH INPUTTED VALUES FOR ELEMENTS !" << endl;
    cout << endl;
    tab6.in();
    tab6.out();
    tab6.maxElement();
    tab6.sumElements();

    cout << endl;
    cout << "Summing Matrices (M4+M3)" << endl;
    cout << endl;
    MatrixAdd(tab4, tab3);
    cout << endl;
    cout << "Subtracting Matrices (M6-M5)" << endl;
    cout << endl;
    MatrixSubtract(tab6, tab5);



    system("pause");
}


