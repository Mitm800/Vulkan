#include "keyboard_movement_controller.hpp"
#include <limits>
#include <iostream>

namespace lve {
    static double lastX, lastY, dx, dy;

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {

        dx = xpos - lastX;
        dy = ypos - lastY;
               
        lastX = xpos;
        lastY = ypos;
    }

    void KeyboardMovementController::moveInPlaneXZ(
        GLFWwindow* window, float dt, LveGameObject& gameObject) {
        //glm::vec3 rotate{ 0.f };
        ro = glm::vec3{ 0.f };

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
       glfwSetCursorPosCallback(window, cursor_position_callback);

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwDestroyWindow(window);

       /* if (glfwGetKey(window, keys.lookRight) == GLFW_PRESS) ro.y += 1.f;
        if (glfwGetKey(window, keys.lookLeft) == GLFW_PRESS) ro.y -= 1.f;
        if (glfwGetKey(window, keys.lookUp) == GLFW_PRESS) ro.x += 1.f;
        if (glfwGetKey(window, keys.lookDown) == GLFW_PRESS) ro.x -= 1.f;*/

        if (dx > 0) { 
            ro.y += 1.f;
            dx = 0;
        }
        if (dx < 0) {
            ro.y -= 1.f;
            dx = 0;
        }

        if (dy > 0) {
            ro.x -= 1.f;
            dy = 0;
        }
        if (dy < 0) {
            ro.x += 1.f;
            dy = 0;
        }

        if (glm::dot(ro, ro) > std::numeric_limits<float>::epsilon()) {
            gameObject.transform.rotation += lookSpeed * dt * glm::normalize(ro);
        }

        ro = glm::vec3{ 0.f };

        gameObject.transform.rotation.x = glm::clamp(gameObject.transform.rotation.x, -1.5f, 1.5f);
        gameObject.transform.rotation.y = glm::mod(gameObject.transform.rotation.y, glm::two_pi<float>());

        float yaw = gameObject.transform.rotation.y;
        const glm::vec3 forwardDir{ sin(yaw), 0.f, cos(yaw) };
        const glm::vec3 rightDir{ forwardDir.z, 0.f, -forwardDir.x };
        const glm::vec3 upDir{ 0.f, -1.f, 0.f };

        glm::vec3 moveDir{ 0.f };
        if (glfwGetKey(window, keys.moveForward) == GLFW_PRESS) moveDir += forwardDir;
        if (glfwGetKey(window, keys.moveBackward) == GLFW_PRESS) moveDir -= forwardDir;
        if (glfwGetKey(window, keys.moveRight) == GLFW_PRESS) moveDir += rightDir;
        if (glfwGetKey(window, keys.moveLeft) == GLFW_PRESS) moveDir -= rightDir;
        if (glfwGetKey(window, keys.moveUp) == GLFW_PRESS) moveDir += upDir;
        if (glfwGetKey(window, keys.moveDown) == GLFW_PRESS) moveDir -= upDir;

        if (glm::dot(moveDir, moveDir) > std::numeric_limits<float>::epsilon()) {
            gameObject.transform.translation += moveSpeed * dt * glm::normalize(moveDir);
        }


    }
}
