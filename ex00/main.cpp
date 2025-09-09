/*The stack is a special region of program memory that is somewhat small (1 MB or so), but it's also really fast. The way to allocate on the stack is just to declare a variable the good ol' boring ol' basic way.

int x = 5;

Perfect. x lives in stack memory.

It's called the "stack" because values are just sorta heaped on, and taken back out in reverse order when they fall out of scope (e.g. when the function they were declared in returns).
 Super fast, super easy, but depends on well-defined temporary scope.

The rest of the memory your program can use (over-simplifying a bit here) is the heap, which is where anything allocated with malloc or new goes - 
including stuff that allocates that under the hood, like std::string, std::vector, std::unordered_map, std::shared_ptr and so on.

The heap is MUCH bigger. I've run programs that use up 16GB of heap space, and I'm sure others on here would laugh at how small that is. 
Things like images usually won't even fit on the stack, so the heap is the only option for many data structures.

The heap is perfectly fine to use! Allocating memory takes some time, since malloc/new have to find an empty region of memory big enough. 
They're pretty fast, so unless you need b l a z i n g fast (e.g. video game engines) allocations, it's not usually an issue. Even in games,
 doing heap allocations up front (e.g. during loading screen) is absolutely okay - as long as you're not doing them frequently during actual program operation.

The stack is also nice because local stack memory fits in a memory page, 
and you can usually be more or less confident that you won't have any cache misses (times where your CPU has to wait extra time on your RAM to load/save a data value) when using stack memory. 
You can get the same benefit with custom allocators using the heap (or stack if you are really clever!), but as with all things: don't worry about it until you actually need it.

EDIT: Another example:

FooClass stackAllocated[16]; // Stack allocated
FooClass* heapAllocated = new FooClass(16); // Heap allocated
std::vector<FooClass> heapAllocated2(16); // Heap allocated*/



/*
-pourquoi dans un cas je dois faire appel a ma fonction destructeur et dans l autre je fais appel a delete ?
Stack vs Heap
 Stack (pile) - Zombie zom("Foo");
- Destruction automatique : Quand la variable sort de son scope (fin de fonction), le destructeur est appelé automatiquement
- Pas besoin de delete : C++ s'en occupe tout seul
- Rapide mais limité en taille

Heap (tas) - Zombie *newZ = newZombie("New Zombie");
- Destruction manuelle : Vous devez explicitement appeler delete
- delete appelle le destructeur : delete newZ; va automatiquement appeler ~Zombie()
- Plus lent mais grande capacité mémoire
*/
#include "Zombie.hpp"

int main(){
    
    //int i = 0;
    randomChump("random");
    
    Zombie *newZ = newZombie("New Zombie");//heap
    newZ->announce();
    delete newZ;
    
    Zombie zom("Foo"); // call to the constructor
    zom.announce();
    
    return (0);
}
