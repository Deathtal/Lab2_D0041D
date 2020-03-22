Course: D0041D  
Student: Herman Åberg
## Part I
* #### Complexities:
	If the size of the array is __n__. The time compexity of just mergesort is *O*{__n__ * log(__n__)}. In our case we do *insertionsort*/*bInsertionsort* when subproblems become the size of __k__ or less. The amount of subproblems therefore become __n__/__k__ and the mergesort part of the total complexity becomes *O*{__n__ * log(__n__/__k__)}, because mergesort only needs to divide the array into __n__/__k__ parts instead of __n__ amount of parts.
	
	Now for the *insertionsort*/*bInsertionsort* we know the size of the subproblems (__k__) and the amount of them (__n__/__k__), so the complexity of that becomes *O*{__n__/__k__ * INS(__k__)} where INS(__k__) is the complexity of *insertionsort*(__k__) or *bInsertionsort*(__k__). The time complexity of *insertionsort*(__k__) is *O*{__k__^2}, while the time complexity of *bInsertionsort*(__k__) is *O*{log(__n__)}.

The total time complexity of *aSort*:
* Best case:  
		*Θ*{__n__ + __n__ * log(__n__/__k__)}
* Worst case:  
		*Θ*{__n__/__k__ * __k__^2 + __n__ * log(__n__/__k__)}
		
		
The total time complexity of *bSort*:
* Best case:  
		*Θ*{__n__ + __n__ * log(__n__/__k__)}
* Worst case:  
		*Θ*{__n__/__k__ * log(__k__) + __n__ * log(__n__/__k__)}

## Part II
| __n__ | __k__ | *aSort* | *bSort* |
|-------|-------|---------|---------|
| 100000 | 10 | 12.4092 ms | 15.3444 ms |
| 100000 | 100 | 18.7331 ms | 22.0354 ms |
| 100000 | 1000 | 105.291 ms | 59.4105 ms |
| 100000 | 10000 | 1128.26 ms | 411.249 ms |
| 1000000 | 10 | 143.816 ms | 176.101 ms |
| 1000000 | 100 | 205.228 ms | 243.214 ms |
| 1000000 | 1000 | 1084.81 ms | 613.713 ms |
| 1000000 | 10000 | 10922.1 ms | 3981.05 ms |

In each case the array consist of random values ranging between 0 and 100000 and after the array have been sorted it is checked for errors to make sure it is sorted.

We can see that the threshold when *bSort* becomes faster than *aSort* does not change with the size of __n__ but is only dependent of __k__. This can also be confirmed by setting __k__ = 1. This way both *insertionsort* and *bInsertionsort* does nothing else but return the value entered. Because of this *aSort* and *bSort* take the same amount of time.

Even though the time complexity of *bSort* is lower than the time complexity of *aSort* it is slower in cases where __k__ is low enough. This is because time complexity tells you more of how a particular function's behavior than it does about how that function stacks up against others. The reason why *aSort* is faster than *bSort* in some cases is because it has lower constants, something that you can not see when looking at time complexities.

Whether or not you should use *aSort* or *bSort* is wholly dependent on the size of __k__. Assuming that it is only sorting that is sought after then *aSort* is always a better choice because setting __k__ to higher value results in worse performance, so the strength of *bSort* is irrelevant.

When it comes to memory they both take the same amount, because in my implementation the only difference between *aSort* and *bSort* is what insertionsort function is called. The workspace needed for moving elements in the array is dynamicly allocated once before the mergesort function is called, this means that there is only one dynamic allocation in the whole function.

I am somewhat happy with my implimentation, but I would do some changes to it if it was to actually be used for a real application. The reason being that I found that it has a huge performance drop for some values of __k__ and in some cases does not work at all. For the values used in the above table they give expected results. I therefore believe that the conclusions drawn in this report are acceptable, but if a higher resolution of __k__ is desired then other implementations are recommended.
