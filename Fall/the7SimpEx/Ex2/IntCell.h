#ifndef IntCell_H
#define IntCell_H

/**
 * A class for simulating an integer memory cell.
 */
class IntCell{
	public:
		explicit IntCell(int initialValue = 0);
		int read() const;
		void write(int x);
		int add(IntCell & a);
		int add(int c);
		IntCell addToNew(int y);
		void addTo(int z);
		void subTo(int b);

	private:
		int storedValue;
};

#endif
