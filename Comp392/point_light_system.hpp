#pragma once

#include "lve_camera.hpp"
#include "Lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_frame_info.hpp"

#include <memory>
namespace lve {
	class PointLightSystem {
	public:

		PointLightSystem(LveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
		~PointLightSystem();

		PointLightSystem(const PointLightSystem&) = delete;
		PointLightSystem& operator=(const PointLightSystem&) = delete;

		void update(FrameInfo& frameInfo, GlobalUbo &ubo, GLFWwindow* window);
		void render(FrameInfo &frameInfo);

	private:
		void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
		void createPipeline(VkRenderPass renderPass);

		LveDevice &lveDevice;

		std::unique_ptr<LvePipeline> lvePipeLine;
		VkPipelineLayout pipelineLayout;
		float rotationSpeed = 1.0f;
		glm::vec3 rotationAxis{ 0.f, -1.f, 0.f };
		float circumference = 1.f;
	};
}