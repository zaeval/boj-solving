#include <iostream>
#include <list>
#include <string.h>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char pure[1000002];
		scanf("%s", pure);
		list<char> in(1);
		list<char>::iterator iter_in = in.begin();
		int len = strlen(pure);

		for (int j = 0; j < len; j++) {
			if (pure[j] == '<') {
				if (iter_in == in.begin())
					continue;
				--iter_in;
			}
			else if (pure[j] == '>') {
				if (*iter_in == 0)
					continue;
				++iter_in;
			}
			else if (pure[j] == '-') {

				if (iter_in == in.begin())
					continue;

				iter_in--;
				iter_in = in.erase(iter_in);

			}
			else {
				in.insert(iter_in, pure[j]);
			}
		}
		while (in.front()!='\0') {
			printf("%c", in.front());
			in.pop_front();
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

