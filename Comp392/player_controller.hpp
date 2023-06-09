#pragma once
#include"lve_game_object.hpp"
#include"lve_window.hpp"

namespace lve {
    class PlayerController {
    public:
        struct PlayerKeyMappings {
            int moveLeft = GLFW_KEY_J;
            int moveRight = GLFW_KEY_L;
            int moveForward = GLFW_KEY_I;
            int moveBackward = GLFW_KEY_K;
            int jump = GLFW_KEY_SPACE;
        };

        void moveInPlaneXZ(GLFWwindow* window, float dt, LveGameObject& gameObject);

        PlayerKeyMappings keys{};
        float velocity{ 3.f };
        float rotationSpeed{ 3.f };
        float gravity{ 0.05f };
        float jumpSpeed{ 5.0f };

        glm::vec3 jumpDir{ 0.f };
    };
}
