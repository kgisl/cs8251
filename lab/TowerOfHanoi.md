

# Tower of Hanoi

The puzzle was invented by the French mathematician Édouard Lucas in 1883. There is a story about an Indian temple in Kashi Vishwanath which contains a large room with three time-worn posts in it, surrounded by 64 golden disks. Brahmin priests, acting out the command of an ancient prophecy, have been moving these disks in accordance with the immutable rules of Brahma since that time. The puzzle is therefore also known as the **Tower of Brahma** puzzle. According to the legend, when the last move of the puzzle is completed, the world will end.

```c
#include <stdio.h> 

void moveDisk(char* from, char* to) {
	printf(" Move top disk from tower %s to tower %s\n", from, to);
}

void TowersOfHanoi(int n, char* from, char* to, char* temp)
{
    //Move top n disks from tower a to tower b, use tower c for intermediate storage.
    if(n > 0)
    {
        TowersOfHanoi(n-1, from, temp, to);   //recursion
				moveDisk(from, to); 
        //Move n-1 disks from temp to the destination
        TowersOfHanoi(n-1, temp, to, from);   //recursion
    }
}


int main() {
	TowersOfHanoi(3, "Tower1", "Tower2", "Inter"); 
	return 0;
}
```

**OUTPUT**

**TowerOfHanoi(1, "Tower 1", "Tower 2", "Inter")**

	Move top disk from tower Tower1 to tower Tower2


**TowerOfHanoi(2, "Tower 1", "Tower 2", "Inter")**

	Move top disk from tower Tower1 to tower Inter
	Move top disk from tower Tower1 to tower Tower2
	Move top disk from tower Inter to tower Tower2

**TowerOfHanoi(3, "Tower 1", "Tower 2", "Inter")**

	Move top disk from tower Tower1 to tower Tower2
	Move top disk from tower Tower1 to tower Inter
	Move top disk from tower Tower2 to tower Inter
	Move top disk from tower Tower1 to tower Tower2
	Move top disk from tower Inter to tower Tower1
	Move top disk from tower Inter to tower Tower2
	Move top disk from tower Tower1 to tower Tower2

### Diagrammatic representation

- https://en.wikibooks.org/wiki/Data_Structures/Stacks_and_Queues#Towers_of_Hanoi
- http://interactivepython.org/runestone/static/pythonds/Recursion/TowerofHanoi.html

### Visualize it! 

http://www.algomation.com/algorithm/towers-hanoi-recursive-visualization

### Play with the code! 

https://repl.it/@kgashok/TowerOfHanoi