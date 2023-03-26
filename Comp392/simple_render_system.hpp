#pragma once

#include "lve_camera.hpp"
#include "Lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_frame_info.hpp"

#include <memory>
namespace lve {
	class SimpleRenderSystem {
	public:

		SimpleRenderSystem(LveDevice &device, VkRenderPass renderPass);
		~SimpleRenderSystem();

		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;


		void renderGameObjects(FrameInfo &frameInfo, std::vector<LveGameObject> &gameObjects);

	private:
		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);

		LveDevice &lveDevice;

		std::unique_ptr<LvePipeline> lvePipeLine;
		VkPipelineLayout pipelineLayout;
	};
}