#pragma once

#include "lve_camera.hpp"
#include "Lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"

#include <memory>
namespace lve {
	class SimpleRenderSystem {
	public:

		SimpleRenderSystem(LveDevice &device, VkRenderPass renderPass);
		~SimpleRenderSystem();

		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;


		void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<LveGameObject> &gameObjects, const LveCamera &camera);

	private:
		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);

		LveDevice &lveDevice;

		std::unique_ptr<LvePipeline> lvePipeLine;
		VkPipelineLayout pipelineLayout;
	};
}