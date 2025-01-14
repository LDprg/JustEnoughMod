#include <render/Renderer.hpp>

#include <core/Application.hpp>

JEM::Renderer::Renderer(std::shared_ptr<Application> app) : AppModule(app) {
  auto [width, height] = getApp()->getWindow()->getSize();

  bgfx::Init bgfx_init;
  bgfx_init.type = bgfx::RendererType::Count; // auto choose renderer
  bgfx_init.resolution.width = width;
  bgfx_init.resolution.height = height;
  bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
  bgfx_init.platformData = getApp()->getWindow()->getRendererBindings();
  bgfx::init(bgfx_init);

  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
  bgfx::setViewRect(0, 0, 0, width, height);
}
