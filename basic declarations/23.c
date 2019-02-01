#include <stdio.h>

int main() {


/*
Write a C program that reads three floating 
values and check if it is possible to make a 
triangle with them. Also calculate the perimeter 
of the triangle if the said values are valid.
*/

//int sides[2];

int sidea, sideb, sidec, perimeter;

int shadowa, shadowb, shadowc;


printf("Insert side a length:");
scanf("%d", &sidea);

printf("Insert side b length:");
scanf("%d", &sideb);

printf("Insert side c length:");
scanf ("%d", &sidec);

printf("The following values were inserted: %d, %d, %d\n\n", sidea, sideb, sidec);

shadowa = sidea;
shadowb = sideb;
shadowc = sidec;

printf("Now ordering numbers...\n");


//set sidea as minimum number
if (shadowa < sideb){
    shadowa = sidea;
}
else
    {
    shadowa = sideb;
    shadowb = sidea;

    if (shadowa < sidec)
        shadowa = shadowa;
        else
        {
            shadowa = sidec; 
        }
        
    }

//set sideb

if (shadowb < sidec)
    shadowb = shadowb;
    else
    {
        shadowc = shadowb;
        shadowb = sidec;
        
    }
    


//reset order

sidea = shadowa;
sideb = shadowb;
sidec = shadowc;


printf("Ordered numbers are: %d, %d, %d\n", sidea, sideb, sidec);



// check if triangle is possible

int sum, diff;

sum = sidea + sideb;
diff = sidec - sideb;

if ( sidec < sum && sidea > diff){
    printf("Triangle is possible. Calculating perimeter.\n\n");

    perimeter = sidea + sideb + sidec;

    printf("Perimeter is %d", perimeter);
}
else
{
    printf("Triangle is not possible.\n");
}


return 0;

}