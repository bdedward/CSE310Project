#include"util.h"
#include"heap.h"


using namespace std;

	int nextCommand(int *i, int *v, int *f){
		char c;
		while(1){
			scanf("%c", &c);
			if(c == ' ' || c == '\t' || c == '\n')
				continue;
			if(c == 'S' || c == 'R' || c == 'W')
				break;
			if(c == 'K' || c == 'k'){
				scanf("%d", i); 
				scanf("%d", v); 
				scanf("%d", f);
				break;
			}
			
			if(c == 'D' || c == 'd'){
				scanf("%d", i);
				break;
			}
			
			if(c == 'I' || c == 'i'){
				scanf("%d", i);
				scanf("%d", v);
				break;
			}

			if(c == 'R' || c == 'r')
				break;

			if(c == 'C' || c == 'c'){
				scanf("%d", i);
				break;
			}
			
			if(c == 'D' || c == 'd'){
				scanf("%d", i); 
				scanf("%d", v);
				scanf("%d", f);
				break;
			}
			
			cout << "Invalid Command\n";
			
		}
	return c;
	}

