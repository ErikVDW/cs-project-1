/*
 *  ev176P1.cpp
 *
 *  COSC 051 Fall 2015
 *  Project #1
 *  Author: Erik Van de Water
 *
 *  Due on: OCT 5, 2015
 *
 * In accordance with the class policies and Georgetown's Honor Code,
 * I certify that I have neither given nor received any assistance
 * on this project with the exceptions of the lecture notes and those
 * items noted below.
 *
 * Note that you should not mention any help from the TAs, the professor,
 * or any code taken from the class textbooks.
 *
 */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

const int CENTER = 40;
const int EXTEND = 10; // used as consistent extra spacer
const int FIRST = 10;
const int SECOND = 18;
const int THIRD = 18;
const int FOURTH = 18;

using namespace std;

int main (){
  //bool okay = 0;
  //if (okay == 0) {
    //return 0;
  //}
  // initialize variables
  char shapeCode, materialCode;
  string shapeName;
  float radius, height, slantHeight = 0, surfaceArea,
  volume, materialCost, laborCost, totalCost, retailCost;

  // introduction
  cout << "Welcome to Appalachian Shape Fabricators.\n";
  cout << "This application calculates surface area, volume, cost\n";
  cout << "and sales values based on your entries.\n";

  // getting calculation variables
  cout << "Please enter shape code (o - cone, y - cylinder, p - sphere):" << endl;
  cin >> shapeCode;
  cin.ignore(500,'\n');
  if ((shapeCode != 'o') && (shapeCode != 'y') && (shapeCode != 'p')
  && (shapeCode != 'O') && (shapeCode != 'Y') && (shapeCode != 'P')) {
    cout << "Not a legitimate shape." << endl;
    return -1;
  }
  switch (shapeCode) {
    case 'o':
      shapeName = "Cone";
      break;
    case 'O':
      shapeName = "Cone";
      break;
    case 'y':
      shapeName = "Cylinder";
      break;
    case 'Y':
      shapeName = "Cylinder";
      break;
    case 'p':
      shapeName = "Sphere";
      break;
    default:
      shapeName = "Sphere";
  }
  cout << "Please enter the material code (k - oak, a - plastic, u - aluminum)" << endl;
  cin >> materialCode;
  cin.ignore(500,'\n');
  if ((materialCode != 'k') && (materialCode != 'a') && (materialCode != 'u')
  && (materialCode != 'K') && (materialCode != 'A') && (materialCode != 'U')) {
    cout << "Not a legitimate material." << endl;
    return -1;
  }

  cout << "Please enter the desired radius for this shape (3\" - 36\"" << endl;
  cin >> radius;
  cin.ignore(500, '\n');
  if ((radius < 3) || (radius > 36)) {
    cout << "The radius entered is outside of limits" << endl;
    return -1;
  }
  if ((shapeCode == 'o') || (shapeCode == 'y') || shapeCode == 'O' || shapeCode == 'Y'){
    cout << "Please enter the desired height for this shape (radius - radius*1.5):" << endl;
    cin >> height;
    cin.ignore(500, '\n');
    if ((height < radius)  || (height > radius * 1.5)){
      cout << "The height entered is outside of limits" << endl;
      return -1;
    }
  }

  // dimension calculations
  if (shapeCode == 'o' || shapeCode == 'O') {
    slantHeight = sqrt(pow(radius,2)+pow(height,2));
    surfaceArea = M_PI*pow(radius,2) + M_PI*radius*slantHeight;
    volume  = (M_PI*pow(radius,2) * height)/3;
  }
  else if (shapeCode == 'y' || shapeCode == 'Y'){
    surfaceArea = 2*M_PI*radius*(height + radius);
    volume = M_PI*pow(radius,2)*height;
  }
  else {
    surfaceArea = 4*M_PI*pow(radius,2);
    volume = (4*M_PI*pow(radius,3))/3;
  }

  //cost calculations
  if (materialCode == 'k' || materialCode == 'K') {
    materialCost = 1.26 * surfaceArea;
    laborCost = 256.27 + (0.4 * materialCost);
  }
  else if (materialCode == 'a' || materialCode == 'A') {
    materialCost = 0.49 * surfaceArea;
    laborCost = 32.10 + (0.1 * materialCost);
  }
  else {
    materialCost = 6.32 * surfaceArea;
    laborCost = 785.16 + (0.8 * materialCost);
  }
  totalCost = materialCost + laborCost;
  retailCost = totalCost * 1.25;

  // output
  cout << "\nResults for shape: " << shapeName << "\n\n";
  cout <<  "surface area: " << surfaceArea << setw(15) << " volume: " << volume << "\n\n";
  cout << setw(CENTER) << "Dimensions\n";
  cout << "-------------------------------------------------------------------\n";
  cout << setw(EXTEND + FIRST) << "radius"
  << setw(SECOND) << "height" << setw(THIRD) << "slant height\n";

  // output the slantheight if the shape has a slantheight.  Otherwise show "n/a" in its place
  if (slantHeight != 0) {
    cout << setprecision(2) << fixed <<  setw(EXTEND + FIRST)
    << radius << setw(SECOND) << height << setw(THIRD) << slantHeight << "\n\n";
  }
  else {
    cout << setprecision(2) << fixed << setw(EXTEND + FIRST)
    << radius << setw(SECOND) << height << setw(THIRD) << "n/a\n";
  }
  cout << "\n";
  cout << setw(CENTER) << "Cost\n";
  cout << "-------------------------------------------------------------------\n";
  cout << setw(FIRST+SECOND+THIRD) << "total" << setw(FOURTH) << "retail\n";
  cout << setw(FIRST) << "material" << setw(SECOND) << "labor" << setw(THIRD)
  << "manufacturing" << setw(FOURTH) << "price" << endl;
  //std::cout.precision(2);
  cout << setprecision(2) << fixed << setw(FIRST) << materialCost << setw(SECOND)
  << laborCost << setw(THIRD) << totalCost << setw(FOURTH) << retailCost << endl;

  // optimal exit
  cout << "\nProgram will exit now.  Goodbye..." << endl;
  return 0; 
}
