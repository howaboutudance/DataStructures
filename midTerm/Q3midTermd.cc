/* Michelle Bergin
 * DataStructures
 * Fall Midterm
 * Q 3
 * Enqueue adds, Dequeue removes and clears, isEmpty (true is empty false otherwise)
 */

/*
 * This may be all wrong but I had the idea that if one or the other was bigger then the other
 * I would just check and add what was left. That way the queues could be different sizes.
 */

Queue<object> & merge(Queue<Object> &rhs){
	Queue<object> n;
	
	/*
	 * Changes: I changed the silly double while loop into one while with an if statement.
	 */

	while(!this.isEmpty()){ 
		n.enqueue(this.dequeue());
		if(!rhs->isEmpty()){
			n.enqueue(rhs->dequeue());
		}
	}

	if(!this.isEmpty()){ // This has the potential of being N and so does the one below it
		while(!this.isEmpty()){
			n.enqueue(this.dequeue());
		}
	}

	if(!rhs->isEmpty()){
		while(!rhs->isEmpty()){
			n.enqueue(rhs->dequeue());
		}
	}

	return n;
}

// 2N + N + N = 4N so BIG O(N)  i think
