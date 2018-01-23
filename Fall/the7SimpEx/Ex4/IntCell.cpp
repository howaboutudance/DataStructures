#include "IntCell.h"

/**
 * Construct the IntCell with initial Value
 */
IntCell::IntCell(int initialValue) : storedValue(initialValue){
}

/**
 *  Return the stored value.
 */
int IntCell::read() const{
	return storedValue;
}

/**
 * Store x.
 */
void IntCell::write(int x){
	storedValue = x;
}

/**
 * Add 2 IntCells together.
 */
int IntCell::add(IntCell & a){
	return storedValue + a.read();
}

int IntCell::add(int c){
	return storedValue + c;
}

/**
 * Add int to storedValue and turn that into a new IntCell to return.
 */
IntCell IntCell::addToNew(int y){
	IntCell newCell(storedValue + y);
	return newCell;
}

/**
 * Add to storedValue.
 */
void IntCell::addTo(int z){
	storedValue += z;
}

/**
 * Subtract from storedValue.
 */
void IntCell::subTo(int b){
	storedValue -= b;
}
