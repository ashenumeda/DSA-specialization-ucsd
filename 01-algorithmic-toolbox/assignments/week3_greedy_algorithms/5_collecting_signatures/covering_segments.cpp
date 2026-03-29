#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  /*
  
    Finds the minimum set of points that intersect all given segments.
    
    This function implements a greedy algorithm that repeatedly selects the rightmost
    point of the segment with the smallest right endpoint, then removes all segments
    that contain that point. The algorithm is straightforward but runs in O(n²) because
    each iteration scans the remaining segments to find the smallest right endpoint.
    A more efficient version would sort the segments once by their right endpoints,
    achieving O(n log n) complexity.

  */
  vector<int> points;

  while (segments.size() > 0) {
    int index = -1;
    int right_most_boundary = INT_MAX;
    
    for (int i = 0; i < segments.size(); i++) {
      if (segments[i].end < right_most_boundary) {
        right_most_boundary = segments[i].end;
        index = i;
      }
    }

    points.push_back(right_most_boundary);
    segments.erase(segments.begin() + index);

    for (int j = segments.size() - 1; j >= 0; j--) {
      if (segments[j].start <= right_most_boundary && right_most_boundary <= segments[j].end) {
        segments.erase(segments.begin() + j);
      }
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
