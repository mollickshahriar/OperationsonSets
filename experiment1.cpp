#include<iostream>

#include<string>

using namespace std;

bool isPresent(int arr[], int len, int val)//check wether val is present in arr[] or not, if present then returns true otherwise returns false

{

	for (int i = 0; i < len; ++i)

	{

		if (arr[i] == val)

			return true;

	}

	return false;

}

int intersection(int a[], int a_len, int b[], int b_len, int result[])//find intersection of two sets A,B and returns the length of result set

{

	int r = 0;

	for (int i = 0; i < a_len; ++i)

	{

		for (int j = 0; j < b_len; ++j)

		{

			if (a[i] == b[j])

				result[r++] = a[i];

		}

	}

	return r;

}

int Union(int a[], int a_len, int b[], int b_len, int result[])//find Union of two sets A,B and returns the length of result set

{

	int i, j, k;

	for (i = 0, j = 0, k = 0; i < a_len && j < b_len;)

	{

		if (a[i] < b[j])

			result[k++] = a[i++];

		else if (a[i] > b[j])

			result[k++] = b[j++];

		else

		{

			result[k++] = a[i++];

			j++;

		}

	}

	for (; i < a_len;)

		result[k++] = a[i++];

	for (; j < b_len;)

		result[k++] = b[j++];

	return k;

}

int difference(int a[], int a_len, int b[], int b_len, int result[])//find difference of two sets A-B and returns the length of result set

{

	int k = 0;

	for (int i = 0; i < a_len; ++i)

	{

		if (!isPresent(b, b_len, a[i]))

			result[k++] = a[i];

	}

	return k;

}

int compliment(int a[], int a_len, int Universe[], int universe_len, int result[])//find complement of set A and returns the length of result set

{

	int k = 0;

	for (int i = 0; i < universe_len; ++i)

	{

		if (!isPresent(a, a_len, Universe[i]))

			result[k++] = Universe[i];

	}

	return k;

}

void getset(int set[], int n)//used for inputting the set from user

{

	int i;

	string s;

	for (i = 0; i < n - 1; ++i)

	{

		getline(cin, s, ',');

		set[i] = stoi(s);

	}

	getline(cin, s, '\n');

	set[i] = stoi(s);

}

void printset(int set[], int n)//print set in form of {1,5,6}

{

	if (n == 0)

		cout << "{}";

	else

	{

		int i;

		cout << "{";

		for (i = 0; i < n - 1; ++i)

		{

			cout << set[i] << ",";

		}

		cout << set[i] << "}";

	}

}

int main()

{

	int uni_len, a_len, b_len, result_len;

	int u[100], a[100], b[100], result[100];

	cin >> uni_len;

	getset(u, uni_len);

	cin >> a_len;

	getset(a, a_len);

	cin >> b_len;

	getset(b, b_len);

	result_len = intersection(a, a_len, b, b_len, result);

	cout << "Intersection(A,B): ";

	printset(result, result_len);

	cout << endl;

	result_len = Union(a, a_len, b, b_len, result);

	cout << "Union(A,B): ";

	printset(result, result_len);

	cout << endl;

	result_len = difference(a, a_len, b, b_len, result);

	cout << "Difference(A,B): ";

	printset(result, result_len);

	cout << endl;

	result_len = compliment(a, a_len, u, uni_len, result);

	cout << "Complement(A): ";

	printset(result, result_len);

	cout << endl;

	return 0;

}
//***************COMMENTS*******************************
//(1) No problems.The difficulty level is fine
//(2) It helped me to look at relations from a computer science perspective.
//(3) More problems should be solved by programming
