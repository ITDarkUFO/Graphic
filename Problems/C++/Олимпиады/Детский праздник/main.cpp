#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count_balloons, count_helpers, current_step = 1;
	cin >> count_balloons >> count_helpers;

	vector<int> work_time(count_helpers), work_max(count_helpers), relax_time(count_helpers);
	vector<int> current_relax_time(count_helpers, 0), current_work_done(count_helpers + 1, 0);

	for (int i = 0; i < count_helpers; i++)
		cin >> work_time[i] >> work_max[i] >> relax_time[i];

	while (true)
	{
		for (int i = 0; i < count_helpers; i++)
		{
			if (current_relax_time[i] != 0)
				current_relax_time[i] -= 1;
			else
			{
				if (current_step % work_time[i] == 0)
				{
					current_work_done[i] += 1;
					current_work_done[count_helpers] += 1;
				}
				if (current_work_done[count_helpers] >= count_balloons)
					goto exit;
				if (current_work_done[i] % work_max[i] == 0 && current_work_done[i] != 0)
					current_relax_time[i] = relax_time[i];
			}
		}
		current_step++;
	}
	exit:
	cout << current_step << endl;

	for (int i = 0; i < count_helpers; i++)
	{
		cout << current_work_done[i] << " ";
	}

	return 0;
}
