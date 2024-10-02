#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>

using namespace std;

void intro()
{
    system("color 0a");
    string str="ALGORITHMS AND PROBLEM SOLVING LAB";
    string str2="PROJECT (PBL)";
    cout<<"\n\n\n\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t";
    for (int i=0;i<str.length();i++)
    {
        Sleep(50);
        cout<<str[i];
    }
    cout<<"\n\t\t\t\t";
    for (int i=0;i<str2.length();i++)
    {
        Sleep(100);
        cout<<str2[i];
    }
    cout<<"\n\t\t--------------------------------------------------------------------------"<<endl;
    Sleep(1000);
    string top="\n\tTOPIC : TIFFIN DELIVERY SERVICES";
    for (int i=0;i<top.length();i++)
    {
        Sleep(100);
        cout<<top[i];
    }
    cout<<"\n\t--------------------------------\n"<<endl;
    string crt="\tSUBMITTED BY :";
    for (int i=0;i<crt.length();i++)
    {
        Sleep(100);
        cout<<crt[i];
    }
    cout<<"\n\t--------------------------------\n"<<endl;
    string name="\t1.Khushi Singh - 9922103148\n\t2.Ankita Jha - 9922103166\n\t3.Pushkar Chaudhary - 9922103144\n\t4.Suryansh Malik - 9922103168\n";
    for (int i=0;i<name.length();i++)
    {
        Sleep(100);
        cout<<name[i];
    }
    cout<<endl<<endl;
    Sleep(1000);
    system("pause");
    system("cls");
}

void TaskScheduling(int n, int deadlines[], int penalties[]) {
    // 7 40 20 40 30 10 40 60 70 60 50 40 30 20 10
    // 4 20 30 40 10 10 50 60 40

    cout << "All deadlines to be entered in interval of 10 minutes" << endl;
    for (int i=0; i<n; i++) {
        cout << "Enter deadline of order " << i+1 << ": ";
        cin >> deadlines[i];
    }
    for (int i=0; i<n; i++) {
        cout << "Enter % of penalty if late (for order " << i+1 << "): " ;
        cin >> penalties[i];
    }
    pair<int, int> final_positions[100];
    for (int i=0; i<n; i++) {
        final_positions[i].first = penalties[i];
        final_positions[i].second = deadlines[i];
    }
    int tasks[100] = {0};
    int left_tasks = 0;
    bool left_checker[100];
    int var[100];

    for (int i=0; i<100; i++) {
        left_checker[i] = true;
    }

    sort(final_positions, final_positions + n);
    // reversing the sort
    for (int i=0, j=n-1; i<n/2; i++, j--)   {
        int temp = final_positions[i].first;
        final_positions[i].first = final_positions[j].first;
        final_positions[j].first = temp;
        int temp2 = final_positions[i].second;
        final_positions[i].second = final_positions[j].second;
        final_positions[j].second = temp2;
    }

    for (int i=0; i<n; i++) {
        for (int j=final_positions[i].second; j>0; j-=10) {
            if (tasks[j] == 0) {
                tasks[j] = j;
                for (int k=0; k<n; k++) {
                    if (final_positions[i].second == deadlines[k] && final_positions[i].first == penalties[k]) {
                        var[j/10] = k+1;
                    }
                }
                left_checker[i] = false;
                break;
            }
        }
        if (left_checker[i] == true) {
            left_tasks++;
        }
    }

    for (int i=0; i<n; i++) {
        if (left_checker[i] == true) {
            for (int j=10; j<=n*10; j+=10) {
                if (tasks[j] == 0) {
                    tasks[j] = j;
                    for (int k=0; k<n; k++) {
                        if (final_positions[i].second == deadlines[k] && final_positions[i].first == penalties[k]) {
                            var[j/10] = k+1;
                        }
                    }
                    break;
                }
            }
        }
    }

    cout << endl << "Orders should be delivered in thee given order: " << endl;
    for (int i=1; i<=n; i++) {
        cout << var[i] << " ";
    }

    cout << endl << "Orders being delivered late = " << left_tasks << endl << endl;

    for (int i=0; i<n; i++) {
        if (left_checker[i] == true) {
            cout << "Late arrival is order with penalty " << final_positions[i].first << endl;
            cout << "Hence a discount of " << final_positions[i].first << " % is provided on the billing amount" << endl << endl;
        }
    }
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

void printknapSack(int max_weight, int weight[], int profit[], int size_profit) {
    // 3 60 100 120 10 20 30 40

    for (int i=0; i<size_profit; i++) {
        cout << "Enter order value of order no " << i+1 << ": ";
        cin >> profit[i];
    }
    for (int i=0; i<size_profit; i++) {
        cout << "Enter no of items in the order " << i+1 << ": ";
        cin >> weight[i];
    }
    cout << "Total items that can be taken: ";
    cin >> max_weight;
	int ary[size_profit + 1][max_weight + 1];
	for (int i = 0; i <= size_profit; i++) {
		for (int w = 0; w <= max_weight; w++) {
			if (i == 0 || w == 0)
				ary[i][w] = 0;
			else if (weight[i - 1] <= w)
				ary[i][w] = max(profit[i - 1] + ary[i - 1][w - weight[i - 1]], ary[i - 1][w]);
			else
				ary[i][w] = ary[i - 1][w];
		}
	}
	int total_value = ary[size_profit][max_weight];
	int weight_left = max_weight;
    cout << endl << "Carrying orders in the following order will get maximum profit with the given weight constarint" << endl << endl;
	for (int i = size_profit; i > 0 && total_value > 0; i--) {
		if (total_value == ary[i - 1][weight_left])
			continue;
		else {
			cout << "Value of order worth " << profit[i - 1] << endl;
			total_value = total_value - profit[i - 1];
			weight_left = weight_left - weight[i - 1];
		}
	}
}


void tsp(int graph[10][10], bool completed[10], int n, int cost, int currPos, int counter, int& ans){
    // 3 1 2 3 3 4 1 5 6 2 8 7 3
    // 3 10 15 20 10 35 25 15 35 30 20 25 30

	if (counter == n && graph[currPos][0]) {
		ans = min(ans, cost + graph[currPos][0]);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!completed[i] && graph[currPos][i]) {
			completed[i] = true;
			tsp(graph, completed, n, cost + graph[currPos][i], i, counter + 1, ans);
			completed[i] = false;
		}
	}
};


int main() {
    intro();
    int input;
    string st;
    label:system("color 0a");
    cout<<endl<<endl<<endl<<endl<<"What do you want to do ?"<<endl<<endl<<"1. Find the best economic way to deliver all the orders"<<endl<<"2. Check which orders are possible to deliver getting maximum profit with quantity constraint"<<endl<<"3. What is the maximum numbers of orders to be delivered without imposing penalty"<<endl<<"4. Exit"<<endl;
    cout<<endl;
    cout<<"Enter your choice: ";
    cin>>input;
    getline(cin,st);
    system("cls");
    if (input == 1) {
            system("color 0b");
            int ary[10][10], n, cost = 0;
            int ans = INT_MAX;
            cout << "Enter the number of houses: ";
            cin >> n;
            n++;
            bool completed[10];
            for (int i=0; i<n; i++) {
                    completed[i] = false;
            }
            completed[0] = true;
            cout << endl << "Enter the Cost Matrix (all distances in km)" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        if (i == 0)
                        {
                            cout << endl << "Enter distance of house " << j << " from delivery point (PAAM): ";
                        }
                        else if (j == 0)
                        {
                            cout << endl << "Enter distance of PAAM from house " << i << ": ";
                        }
                        else
                        {
                            cout << endl << "Enter distance of house " << j << " from house no " << i << ": ";
                        }
                        cin >> ary[i][j];
                    }
                    else {
                            ary[i][j] = 0;
                    }
                }
            }
            cout << endl << endl << "The distance matrix is:";
            for (int i = 0; i < n; i++) {
                    cout << endl;
            for (int j = 0; j < n; j++)
                cout << "\t" << ary[i][j];
            }
            cout << endl << endl;
            tsp(ary, completed, n, 0, 0, 1, ans);
            cout << endl << "Minimum distance = " << ans << " km\n";
            system("pause");
            system("cls");
            goto label;
        }
        else if (input == 2) {
                system("color 0f");
                cout << "Super Delivery mode" << endl << endl;
                cout << "Enter number of orders: ";
                int size_profit;
                cin >> size_profit;
                int max_weight, profit[size_profit], weight[size_profit];
                printknapSack(max_weight, weight, profit, size_profit);
                system("pause");
                system("cls");
                goto label;
        }
        else if (input == 3) {
                system("color 0d");
                int number;
                cout << "Enter number of orders: ";
                cin >> number;
                int penalties[number], deadlines[number];
                TaskScheduling(number, deadlines, penalties);
                system("pause");
                system("cls");
                goto label;
        }
        else if (input==4) {
            system("color 0c");
            cout<<endl<<endl<<endl<<endl<<endl<<"Okay";
            return 0;
        }
        else {
            system("color 4b");
            cout<<endl<<endl<<endl<<endl<<endl<<"Try Again"<<endl;
            system("pause");
            system("cls");
            goto label;
        }
    }


int least(int ary[10][10], int completed[10], int n, int* cost, int row) {
    int least_not_visited = 999;
    int found_min = 999, current_cost;

    for (int i=0; i<n; i++) {
        if ((ary[row][i] != 0) && (completed[i] == 0)) {
            if (ary[i][0] + ary[row][i] < found_min) {
                found_min = ary[i][0] + ary[row][i];
                current_cost = ary[row][i];
                least_not_visited = i;
            }
        }
    }

    if (found_min != 999)
        *cost += current_cost;
    return least_not_visited;
}

void mincost(int ary[10][10], int completed[10], int n, int* cost, int city) {
    int i, nextCity;
    completed[city] = 1;
    if (city == 0) {
        cout << "The most economic path or the path with minimum distance covering all orders is: " << endl;
        cout << "PAAM ---> ";
    }
    else {
        cout << city << " ---> ";
    }
    nextCity = least(ary, completed, n, cost, city); // calculating least not visited

    if (nextCity == 999) { // if all visited, base case
        nextCity = 0;
        cout << "PAAM";
        *cost += ary[city][nextCity];
        return;
    }
    mincost(ary, completed, n, cost, nextCity);
}

void TSP(int ary[10][10], int completed[10], int n, int* cost) {
    // 3 1 2 3 3 4 1 5 6 2 8 7 3
    // 3 10 15 20 10 35 25 15 35 30 20 25 30
    // 4 20 30 10 11 15 6 4 2 2 5 2 4 19 6 18 3 16 4 7 16

    cout << "Enter the number of houses: ";
    cin >> n;
    n++;
    cout << endl << "Enter the Cost Matrix (all distances in km)" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (i == 0)
                    cout << endl << "Enter distance of house " << j << " from delivery point (PAAM): ";
                else if (j == 0)
                    cout << endl << "Enter distance of PAAM from house " << i << ": ";
                else
                    cout << endl << "Enter distance of house " << j << " from house no " << i << ": ";
                cin >> ary[i][j];
            }
            else {
                ary[i][j] = 0;
            }
        }
        completed[i] = 0;
    }
    cout << endl << endl << "The distance matrix is:";

    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << "\t" << ary[i][j];
    }
    cout << endl << endl;
    mincost(ary, completed, n, cost, 0); // passing 0 because starting vertex
    cout << endl << endl << "Minimum distance is " << *cost << " km" << endl;
}
