/*
 * Michelle Bergin
 * DataStructures
 * Q 1
 *
 * reverse a List as a member function and not as a member function
 */

// Member FUNction
reverse(){
	Node *front;
	Node *back;
	int count = this.theSize;
	int place = count;
	/*
	 * For BIG O the for loop would be BIG O(N), my goal was to only run through that once
	 * BUT I am running through the List N times. BUT I decrement by 1 on either side (totaling 2) 
	 * I think this is closer to BIG O(N log N) or N^2 
	 */
	for(int i = 0; i < this.theSize(); i++){
		for(iterator::List<object> it = this.begin(); it != this.end(); it++){
			if(place == (this.theSize() - count - 1)){
				front = *it;
				*it = back;
			}
			if(place == count){
				back = *it;
				*it = front;
			}
			count--;
			place++;
		} // I feel this wouldn't all work and I feel like I would be missing a last swap...
	}
}

// Non-Member FUNction
reverse(List<object> &l){
	Object *front;
	Object *back;
	int count = l.size();
	int place = count;
	for(int i = 0; i < l.size(); i++){
		for(iterator::List<Object> it = l.begin(); l != l.end(); it ++){
			if(place ==(l.size() - count - 1)){
				front = *it;
				*it = back;
			}
			if(place == count){
				back = *it;
				*it = front;
			}
			count--;
			place++;
		}
}
