      #include <iostream>
      #include <cmath>

      class Point {
      private:
          double x, y;

      public:
          // Constructor
          Point() : x(0.0), y(0.0) {}

          // Method to set the coordinates of the point
          void setCoordinates(double newX, double newY) {
              x = newX;
              y = newY;
          }

          // Method to calculate the distance between two points
          double calculateDistance(const Point& otherPoint) const {
              double dx = x - otherPoint.x;
              double dy = y - otherPoint.y;
              return std::sqrt(dx * dx + dy * dy);
          }

          // Method to display the coordinates of the point
          void displayCoordinates() const {
              std::cout << "Point coordinates: (" << x << ", " << y << ")\n";
          }
      };

      int main() {
          // Create two instances of the Point class
          Point point1, point2;

          // Set coordinates for the two points
          point1.setCoordinates(1.0, 2.0);
          point2.setCoordinates(4.0, 6.0);

          // Display the coordinates of the points
          point1.displayCoordinates();
          point2.displayCoordinates();

          // Calculate and display the distance between the two points
          double distance = point1.calculateDistance(point2);
          std::cout << "Distance between the points: " << distance << std::endl;

          return 0;
      }