#include <stdio.h>

int main(void)
{
	int num_nrl;
	int* ptr = NULL;
	int ans_nrl;

	//code
	num_nrl = 5;
	ptr = &num_nrl;
	printf("\n\n");
	printf("  num        =%d\n", num_nrl);
	printf("  &num       =%p\n", &num_nrl);
	printf("  *(&num)    =%d\n", *(&num_nrl));
	printf("  ptr        =%p\n", ptr);
	printf("  *ptr       =%d\n", *ptr);

	printf("\n\n");

	// Add 10 to 'ptr' which is the address of 'num'...
	//Hence, 10 wil be added to the address of 'num' and the resultant address will be displayed
	printf("Answer Of (ptr +10)  =%p\n", (ptr + 10));

	// Add 10 to 'ptr' which is the address of 'num'...
	//Hence, 10 will be added to the address of 'num' and the resultant address will be displayed 
	printf("Answer Of *(ptr +10 )= %d\n", *(ptr + 10));

	// **** ASSOCIATIVITY OF * (Value At Address) AND ++ AND --- Operators Is Form Right To Left ***

	// (Right To Left ) Consider Vlaue *ptr .... Pre-increment *ptr ....That is , value at address 'ptr' i.e. *ptr is pre-incremented (++*ptr) 
	++*ptr; // *ptr is pre-incremented ... *ptr is 5 ..After execution of this statement ... *ptr = 6
	printf("Answer Of ++*ptr : %d\n ", *ptr); // Brackets not nexxessary for pre-increment / pre-decrement

	// (Rigth  To Left) Post-increment address ptr....That is , address 'ptr' i.e. ptr is post-incremented (ptr++) and the value at the new address is displayed (++*ptr)..
	*ptr++; // Incorrect method of post incrementing a vlaue using pointer 
	printf("Answer Of *ptr++ : %d\n", *ptr); // Brackets Are Necessary for post-increment / post-decrements


	// (RIGHT TO LEFT) Post-increment value *ptr ... That is, value at address 'ptr' i.e: *ptr is post - incremented(*ptr)++
	ptr = &num_nrl;
	
	(*ptr)++; // Correct method of post-incrementing a value using pointer ... *ptr is 6 ... at this statement * ptr remains 6 but at next statement * ptr 7 (post - increment)
	printf("Answer Of (*ptr)++ : %d\n\n", *ptr); //Brackets are necessary fo postincrement/ post - decrement
		
	return(0);
}