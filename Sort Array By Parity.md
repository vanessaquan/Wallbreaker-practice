# Wallbreaker-practices-week1
This repository contains the practice problems and solutions of my own in C++. 
 first we can use a for loop to iterate all the elements in the vector list...
      * for each element in the vector list, we should have two iterators (one iterator 'i' starts from begining of list and one  'j' starts from the end of list). the end point is that whenever the i is not less than j, which means we've went through all the elements, we stop. otherwaise, i should continue to check the next of the current  element. 
			     *if the element is not even number
					      1.then swap the element with the last unused (or unvisited) element
								2.after we swapped the current and the last unvisited element, the for loop 
								should not iterate to the next of the current element since the current element 
								hasn't been checked. we just swapped it. therefore, we need to check the 
								current element again. 
								3. since we swapped current and last unvisited element, the last unvisited 
								element now became visited. Thus, we should not look at the last one 
								anymore. we need to set the iterator for ' last ' to 'second of last' element. 
			
			*once we've finished swapping even and odd numbers. return that vector list. 
