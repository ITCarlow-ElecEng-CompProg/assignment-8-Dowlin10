// Mark Dowling
// Lab 8
// C00216994
// 24/11/17

//Pre Processor Directives
#include <iostream>
#include <math.h>


using namespace std;

//Functions
void inAmp (double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout);
void invertingAmp();

void nonintAmp(double Vin, double R1, double R2 , double *ptr_Av, double *ptr_Vout);
void noninvertingAmp();

char menu(void);
int main()
{
    char userinput;

    //Display heading on screen
    cout << "Operational Amplifier Circuits"<< endl;

    //Do While Loop
    do
    {
        userinput = menu();


        switch (userinput)
        {   // All calculations taking part in the functions
            case 'a':   invertingAmp();
            break;

            case 'c':   noninvertingAmp();
                        break;
            //Quit the function
            case 'q':   cout <<"Goodbye, Have a lovely evening"<< endl;
                        break;
            // Prompy user to CHOOSE A LETTER AGAIN
            default:    cout << "Please choose correct program:"<<endl;
                        break;

        }
    }
    while (userinput != 'q');

    return 0;

}

char menu(void)
{
    //Variable declaration
    char input;

    cout << "Choose conversion\n"<<
    "a = Inverting Amplifier\n"<<
    "c = Non Inverting Amplifier\n"<<
    "q = quit program.\n" << endl ;
    cin >> input;

    return input;
}

void invertingAmp()

{   //varriable declaration
    double Vcc =0 ,Vee =0, Vin=0 ,Rin=0, Rf=0,Av,Vout;
    double *ptr_Av = &Av;
    double *ptr_Vout = &Vout;

    //While Loops to ensure only positive values entered
    while (Vcc <= 0)
    {
        cout << "Enter a value for Vcc: ";
        cin >> Vcc;
    }

      while (Vee <= 0)
    {
        cout << "Enter a value for Vee: ";
        cin >> Vee;
    }


      while (Vin <= 0)
    {
        cout << "Enter a value for Vin: ";
        cin >> Vin;
    }

    while (Rin <= 0)
    {
        cout << "Enter a value for Rin: ";
        cin >> Rin;
    }
    while (Rf <= 0)
    {
        cout << "Enter a value for Rf: ";
        cin >> Rf;
    }
    //Returns values calculated in the specific functions

    inAmp( Vin, Rin, Rf, ptr_Av,ptr_Vout);

    cout << "\nVoltage Gain" << *ptr_Av << endl;


     if(Vout >= Vee || Vout <= Vcc)
    {
        if(Vin <= 0)
        {
            cout << "\n Output voltage is \n\nVout =\t " << Vcc;
        }
        else
        {
            cout << "\nOutput voltage is \n\nVout =\t " << Vee;
        }
    }


    return ;
}


void inAmp (double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout)

{
   *ptr_Av = -Rf/Rin ;
   *ptr_Vout = *ptr_Av * Vin;

}


void noninvertingAmp()
{   //Variable declaration
    double Vcc =0 ,Vee =0,Vin=0, R1=0,R2=0,Av,Vout;
    double *ptr_Av = &Av;
    double *ptr_Vout = &Vout;

    //while loop
    while (Vcc <= 0)
    {
        cout << "Enter a value for Vcc: ";
        cin >> Vcc;
    }

      while (Vee <= 0)
    {
        cout << "Enter a value for Vee: ";
        cin >> Vee;
    }


      while (Vin <= 0)
    {
        cout << "Enter a value for Vin: ";
        cin >> Vin;
    }

    while (R1 <= 0)
    {
        cout << "Enter a value for R1: ";
        cin >> R1;
    }
      while (R2 <= 0)
    {
        cout << "Enter a value for R2: ";
        cin >> R2;
    }
    //Returns values calculated in the specific functions
    nonintAmp( Vin, R1, R2,ptr_Av,ptr_Vout);

	cout << "\nVoltage Gain\t" << *ptr_Av << endl;

    //If statement display correct saturation Value
     if(Vout >= Vee || Vout <= Vcc)

    {
        if(Vin <= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << Vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << Vee ;
        }
    }

  cout << "\n Output Voltage \t" << *ptr_Vout << endl;

    return ;
}
//Function to calculate pointers
void nonintAmp(double Vin, double R1, double R2 , double *ptr_Av, double *ptr_Vout)

{
   *ptr_Av = 1 + (R2/R1) ;
   *ptr_Vout = *ptr_Av * Vin ;
}
