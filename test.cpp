#include <algorithm>
#include <vector>

using pii = std::pair<int, int>;

struct Rectangle {
  int bottom_left_x;
  int bottom_left_y;
  int top_right_x;
  int top_right_y;
};

int max_overlaps(std::vector<pii> &intervals) {
  // begin -> -1 and end +1
  std::vector<pii> events;

  // todo: do touching components count as separate? if so, move end to end + 1?
  for (const auto &[start, end] : intervals) {
    events.push_back({start, 1});
    events.push_back({end + 1, 2});
  }

  // todo: there might be an issue here where i need a custom sort function
  // i forgot how to do the comparator right now, but i need to make -1 go after
  // 1 for delta possibly? I could cheat with making end 2 and then
  // ternary down below
  // TODO: work on custom lambda for comparator. i can work around it but
  // i think it would be clearer to have -1 as delta.
  // switching from 2 -> -1 would be confusing
  sort(events.begin(), events.end());

  int cur = 0;
  int max_overlaps = 0;
  for (const auto &[val, delta] : events) {
    cur += delta == 2 ? -1 : 1;
    max_overlaps = std::max(max_overlaps, cur);
  }

  return max_overlaps;
}

int max_components(const std::vector<Rectangle> &rectangles) {
  size_t n = rectangles.size();
  std::vector<pii> intervals_x;
  std::vector<pii> intervals_y;
  std::vector<pii> diagonal_f;
  std::vector<pii> diagonal_r;

  for (const auto &rectangle : rectangles) {
    intervals_x.push_back({rectangle.bottom_left_x, rectangle.top_right_x});
    intervals_y.push_back({rectangle.bottom_left_y, rectangle.top_right_y});

    // y = mx + b
    //
  }

  int overlaps_x = max_overlaps(intervals_x);
  int overlaps_y = max_overlaps(intervals_y);

  return std::max(overlaps_x, overlaps_y);
}

int main() {}

/**
 * pcb board and n rectangular components
 *
 * return max number of components by drawing 1 vertical or horizontal line
 *
 *
 * think of it as 2d grid
 * each index isn't the same size or width
 * component are given in inputs
 * no overlaps
 * input size < 100,000 units
 *
 * component
 *
 */
