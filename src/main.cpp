#include <JustEnoughMod.hpp>

#include <memory>

int main([[maybe_unused]] int argc, char **argv) {
  try {
    // shared_ptr is needed for shared_from_this()
    std::shared_ptr<JEM::Application> app = std::make_shared<JEM::Application>();

    app->init(argv[0]);

    app->run();
  } catch (std::exception e) {
    JEM::getSystemLogger()->error("Unknown Exception: {}", e.what());
  }
}
