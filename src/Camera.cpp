#include <Camera.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace war {

Camera::Camera(const Ray &r, scalar_t d, scalar_t w, scalar_t h, scalar_t t)
    : ray(r), distance(d), width(w), height(h), tilt(t) {
  initCameraAxes();
}

void Camera::initCameraAxes() {
  rotationMatrix_t rotation =
      glm::rotate(rotationMatrix_t(1.0), glm::radians(tilt), ray.D);

  vec_t initialUp(0.0, 1.0, 0.0);
  up = vec_t(rotation * glm::vec4(initialUp, 0.0));

  right = glm::cross(initialUp, ray.D);
  right = vec_t(rotation * glm::vec4(right, 0.0));
}

Ray Camera::getRayFromViewportCoordinates(scalar_t x, scalar_t y) const {
  vec_t center = ray.O + distance * ray.D;
  vec_t target = center + (right * x * width / 2.0) + (up * y * height / 2.0);
  return Ray(ray.O, target - ray.O);
}

coord2d_t Camera::projectPoint(const point_t &point,
                               const projectionMatrix_t &projectionMatrix) {
  vec4_t clipSpace = projectionMatrix * vec4_t(point, 1.0);
  vec_t ndcSpace = vec_t(clipSpace) / clipSpace.w;
  int x = (ndcSpace.x * 0.5 + 0.5) * width;
  int y = (ndcSpace.y * 0.5 + 0.5) * height;
  return glm::vec2(x, y);
}
}; // namespace war
