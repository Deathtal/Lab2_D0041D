Course: D0041D  
Student: Herman Åberg
## Part I
* #### Complexities:
	If the size of the array is __n__. The time compexity of just mergesort is *O*{__n__ * log(__n__)}. In our case we do *insertionsort*/*bInsertionsort* when subproblems become the size of __k__ or less. The amount of subproblems therefore become __n__/__k__ and the mergesort part of the total complexity becomes *O*{__n__ * log(__n__/__k__)}, because mergesort only needs to divide the array into __n__/__k__ parts instead of __n__ amount of parts.
	
	Now for the *insertionsort*/*bInsertionsort* we know the size of the subproblems (__k__) and the amount of them (__n__/__k__), so the complexity of that becomes *O*{__n__/__k__ * INS(__k__)} where INS(__k__) is the complexity of *insertionsort*(__k__) or *bInsertionsort*(__k__). The time complexity of *insertionsort*(__k__) is *O*{__k__^2}, while the time complexity of *bInsertionsort*(__k__) is *O*{log(__n__)}.

The total time complexity of *aSort*:
* Best case:  
		INS(__k__) = __k__  
		*Θ*{__n__ + __n__ * log(__n__/__k__)}
* Worst case:  
		INS(__k__) = __k__^2  
		*Θ*{__n__/__k__ * __k__^2 + __n__ * log(__n__/__k__)}
		
		
The total time complexity of *bSort*:
* Best case:  
		INS(__k__) = __k__  
		*Θ*{__n__ + __n__ * log(__n__/__k__)}
* Worst case:  
		INS(__k__) = log(__k__)  
		*Θ*{__n__/__k__ * log(__k__) + __n__ * log(__n__/__k__)}

## Part II
