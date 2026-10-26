/**
 * garden mxn
 * you have to plant m*n plants the whole
 *
 * many different types of plants 10 -15
 *
 * rules:
 * same type of plants are planted next to each other up/down/left/right
 *
 * given some input???, we need m rows and n cols, and then number of types?
 *
 *
 */

#include <vector>
using namespace std;

vector<vector<int>> plant_garden(size_t num_rows, size_t num_cols,
                                 uint8_t types) {
  vector<vector<int>> garden(num_rows, vector<int>(num_cols, -1));
  size_t total_plants = num_rows * num_cols;
  // floor so last plant needs to plant more
  size_t per_plant = total_plants / types;
  size_t final_plant = total_plants - (per_plant * (types - 1));

  int cur_plant = 0;
  bool switch_dir = true;
  int c = 0;

  for (int r = 0; r < num_rows; r++) {
    int increment = switch_dir ? 1 : -1;
    int planted = cur_plant == types - 1 ? total_plants : per_plant;

    while (c >= 0 && c < num_cols && planted >= 0) {
      garden[r][c] = cur_plant;
      planted--;
      c += increment;
    }

    if (c == -1) {
      c = 0;
    } else if (c == num_cols) {
      c = num_cols - 1;
    }

    switch_dir = !switch_dir;

    cur_plant++;
  }

  return garden;
}
