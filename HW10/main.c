#include <stdio.h>
#include <stdlib.h>
int total_disk;
// Define stack
typedef struct stack
{
int *array;
int maxsize;
int currentsize;
}stack;
struct stack1
{
int source;
int auxiliary;
int destination;

}stack1;

int init(stack * s)
{
if (s->currentsize == s->maxsize - 1)
 return 1;
}
//Create a new node of stack
stack *init_return()
{
//Make a new node
struct stack *s = (struct stack*) malloc(sizeof(stack));
	s -> maxsize =total_disk;
	s -> currentsize = -1;
	s -> array = (int*) malloc(s -> maxsize * sizeof(int));
 return s;
}
// add node at the top of stack
void push(struct stack *s,int d)
{
if (s->currentsize == s->maxsize - 1)
		return;
	s -> array[++s -> currentsize] = d;
}

// return top element of stack
struct stack *peek(struct stack *stack)
{
stack-> maxsize;
}
// Remove top element of stack
int pop(struct stack *stack)
{
if (stack-> currentsize > 0 && stack-> maxsize != 0)
{
struct stack *temp = stack-> maxsize;
// Change top element of stack
stack-> maxsize = temp-> array;

// remove previous top
free(temp);
temp = NULL;
return stack-> currentsize--;
}
}
// Display the movement of current disk 
void result(struct stack1 *node)
{
printf(" Move disk %d from tower %d to  %d\n", node->auxiliary, node->source, node->destination);
}
 
int main()
{

printf("enter a number ");
scanf("%d",&total_disk);
printf("\n");

struct stack *bas,*bit,*diger;
bas = init_return();
bit = init_return();
diger = init_return();
// Iterative tower of hanoi
if (total_disk > 0)
{
// Display total disk
int maxsize = total_disk;

// Seting poles in terms of integer
int source = 1;
int auxiliary = 2;
int destination = 3;

// a stack which is hold information of execute steps
struct stack *stack = init_return();
struct stack1 *node = NULL;
int temp = 0;
while (maxsize > 0 || init(stack) == 0)
{
if (maxsize > 0)
{
node = init_return(maxsize, source, destination, auxiliary);

// Add stack node
push(stack, maxsize);

// Change execution variables
temp = destination;
destination = auxiliary;
auxiliary = temp;

// Reduce disk size
maxsize--;
}
else
{
// Get top element of stack
node = peek(stack);

// Display movement of disk
result(node);

// Get new execution info
source = node->auxiliary;
destination = node->destination;
maxsize= maxsize-1;
auxiliary = node->source;

// Remove stack elemnt
pop(stack);
}
}
}

return 0;
}
