#pragma once

#include <core/Window.hpp>
#include <plugin/PluginLoader.hpp>
#include <render/Renderer.hpp>

namespace JEM {
  class Application {
    public:
      void init(char *path);
      void deinit();

      void run();

      static constexpr Version getAppVersion() {
#ifdef VERSION
        return VERSION;
#else
        return "0.0.0";
#endif
      }

      std::shared_ptr<Logger> getLogger() const {
        return m_logger;
      }

    private:
      static inline std::shared_ptr<Window> m_window;
      static inline std::shared_ptr<Renderer> m_renderer;
      static inline std::shared_ptr<PluginLoader> m_pluginLoader;
      static inline std::shared_ptr<Logger> m_logger;

      static inline bool m_quit;
  };
} // namespace JEM