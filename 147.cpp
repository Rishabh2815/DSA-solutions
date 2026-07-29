#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

vector<double> getMedian(vector<int> &arr)
{

    // Max heap to store the smaller half of numbers
    priority_queue<int> s;

    // Min heap to store the greater half of numbers
    priority_queue<int, vector<int>, greater<int>> g;

    vector<double> res;

    for (int i = 0; i < arr.size(); i++)
    {

        // Insert new element into max heap
        s.push(arr[i]);

        // Move the top of max heap to min heap to maintain order
        int temp = s.top();
        s.pop();
        g.push(temp);

        // Balance heaps if min heap has more elements
        if (g.size() > s.size())
        {
            temp = g.top();
            g.pop();
            s.push(temp);
        }

        // Compute median based on heap sizes
        double median;

        if (s.size() != g.size())
            median = s.top();
        else
            median = (double)(s.top() + g.top()) / 2;

        res.push_back(median);
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);

    for (double median : res)
        cout << median << " ";
    return 0;
}