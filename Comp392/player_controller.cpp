#include "player_controller.hpp"
#include <limits>
#include <iostream>

namespace lve {
    void PlayerController::moveInPlaneXZ(
        GLFWwindow* window, float dt, LveGameObject& gameObject) {

        float yaw = gameObject.transform.rotation.y;
        const glm::vec3 forwardDir{ sin(yaw), 0.f, cos(yaw) };
        const glm::vec3 rightDir{ forwardDir.z, 0.f, -forwardDir.x };
        const glm::vec3 upDir{ 0.f, -1.f, 0.f };
        const glm::vec3 zAxis{ 0.f, 0.f, sin(yaw)};

        glm::vec3 straight = glm::cross(upDir, rightDir);

        glm::vec3 moveDir{ 0.f };
        glm::vec3 rotate{ 0.f };

        if (glfwGetKey(window, keys.moveForward) == GLFW_PRESS) {
            moveDir += forwardDir;
            //rotate -= rightDir;
        }

        if (glfwGetKey(window, keys.moveBackward) == GLFW_PRESS) {
            moveDir -= forwardDir;
            //rotate += rightDir;
        }

        if (glfwGetKey(window, keys.moveRight) == GLFW_PRESS) {
            moveDir += rightDir;
            //rotate += straight;
        }
         
        if (glfwGetKey(window, keys.moveLeft) == GLFW_PRESS) {
            moveDir -= rightDir;
            //rotate -= straight;
        }

        if (glfwGetKey(window, keys.jump) == GLFW_PRESS && gameObject.transform.translation.y == -.25f) {
            jumpDir.y = -jumpSpeed;
        }

        

        jumpDir.y += gravity;
        gameObject.transform.translation += jumpDir * dt;

        gameObject.transform.translation.y = glm::clamp(gameObject.transform.translation.y, -5.f, -.25f);

        if (glm::dot(moveDir, moveDir) > std::numeric_limits<float>::epsilon()) {
            gameObject.transform.translation += velocity * dt * glm::normalize(moveDir);
        }

        /*if (glm::dot(rotate, rotate) > std::numeric_limits<float>::epsilon()) {
            gameObject.transform.rotation += rotationSpeed * dt * glm::normalize(rotate);
        }*/

    }
}
