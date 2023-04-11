#pragma once

#include "lve_camera.hpp"
#include "Lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_frame_info.hpp"
#include "player_controller.hpp"

#include <memory>
namespace lve {
	class SimpleRenderSystem {
	public:

		SimpleRenderSystem(LveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
		~SimpleRenderSystem();

		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;


		void renderGameObjects(FrameInfo &frameInfo);
		void updateGameObjects(FrameInfo& framInfo, GLFWwindow* window);

	private:
		void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
		void createPipeline(VkRenderPass renderPass);

		LveDevice &lveDevice;

		std::unique_ptr<LvePipeline> lvePipeLine;
		VkPipelineLayout pipelineLayout;

		PlayerController controller{};
	};
}